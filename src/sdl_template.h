#include <SDL2/SDL.h>
#include <stdbool.h>
#include <stdio.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>

// Global variables
SDL_Window *win = NULL;
SDL_Renderer *ren = NULL;
bool active = true; // so you can use while (active) { // SDL events }

// =============INITIALIZATION, WINDOW, EVENTS===========================

bool init(const char *title, int width, int height) {
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
        printf("SDL_Init Error: %s\n", SDL_GetError());
        return false;
    }
    
    win = SDL_CreateWindow(title, 100, 100, width, height, SDL_WINDOW_RESIZABLE);
    if (win == NULL) {
        printf("SDL_CreateWindow Error: %s\n", SDL_GetError());
        SDL_Quit();
        return false;
    }

    ren = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (ren == NULL) {
        SDL_DestroyWindow(win);
        printf("SDL_CreateRenderer Error: %s\n", SDL_GetError());
        SDL_Quit();
        return false;
    }

    // Init external libs
    if (!(IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG)) {
        printf("IMG_Init Error: %s\n", IMG_GetError());
        SDL_DestroyRenderer(ren);
        SDL_DestroyWindow(win);
        SDL_Quit();
        return false;
    }

    if (TTF_Init() == -1) {
        printf("SDL_ttf could not initialize! TTF_Error: %s\n", TTF_GetError());
        SDL_DestroyRenderer(ren);
        SDL_DestroyWindow(win);
        SDL_Quit();
        return false;
    }

    return true;
}

void quit() {
    if (ren) {
        SDL_DestroyRenderer(ren);
    }
    if (win) {
        SDL_DestroyWindow(win);
    }
    TTF_Quit();
    IMG_Quit();
    SDL_Quit();
}

void handle_events() {
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        switch (event.type) {
            case SDL_QUIT:
                active = false;
                break;
            // Handle other events here if needed
            default:
                break;
        }
    }
}

void debug() {
    if (SDL_WasInit(SDL_INIT_EVERYTHING) == 0) {
        printf("SDL is not initialized.\n");
    }
    if (win == NULL) {
        printf("SDL_CreateWindow Error: %s\n", SDL_GetError());
    }
    if (ren == NULL) {
        printf("SDL_CreateRenderer Error: %s\n", SDL_GetError());
    }
}

// =============COLOR, DRAW (RECT, TRI, CIR), RENDER RELATED FUNCTIONS===========================

typedef struct {
    Uint8 r;
    Uint8 g;
    Uint8 b;
    Uint8 a;
} Color;

// Define color constants
const Color BLACK = {0, 0, 0, 255};
const Color WHITE = {255, 255, 255, 255};
const Color RED = {255, 0, 0, 255};
const Color GREEN = {0, 255, 0, 255};
const Color BLUE = {0, 0, 255, 255};
const Color YELLOW = {255, 255, 0, 255};
const Color CYAN = {0, 255, 255, 255};
const Color MAGENTA = {255, 0, 255, 255};
const Color GRAY = {128, 128, 128, 255};
const Color DARK_GRAY = {64, 64, 64, 255};
const Color LIGHT_GRAY = {192, 192, 192, 255};
const Color ORANGE = {255, 165, 0, 255};
const Color PURPLE = {128, 0, 128, 255};
const Color PINK = {255, 192, 203, 255};
const Color BROWN = {139, 69, 19, 255};

typedef enum {
    FILLED,
    OUTLINE
} ShapeType;

void draw_rectangle(Color color, int width, int height, int xpos, int ypos, ShapeType type) {
    SDL_Rect rect;
    rect.x = xpos; // X position
    rect.y = ypos; // Y position
    rect.w = width; // Width
    rect.h = height; // Height

    SDL_SetRenderDrawColor(ren, color.r, color.g, color.b, color.a); // Rectangle color
    // Draw based on the type
    if (type == FILLED) {
        SDL_RenderFillRect(ren, &rect);
    } else if (type == OUTLINE) {
        SDL_RenderDrawRect(ren, &rect);
    }
}

void draw_triangle(Color color, int x1, int y1, int x2, int y2, int x3, int y3, ShapeType type) {
    SDL_SetRenderDrawColor(ren, color.r, color.g, color.b, color.a);

    if (type == FILLED) {
        int minX = SDL_min(x1, SDL_min(x2, x3));
        int maxX = SDL_max(x1, SDL_max(x2, x3));
        int minY = SDL_min(y1, SDL_min(y2, y3));
        int maxY = SDL_max(y1, SDL_max(y2, y3));

        for (int y = minY; y <= maxY; y++) {
            for (int x = minX; x <= maxX; x++) {
                int w0 = (x - x2) * (y1 - y2) - (x1 - x2) * (y - y2);
                int w1 = (x - x3) * (y2 - y3) - (x2 - x3) * (y - y3);
                int w2 = (x - x1) * (y3 - y1) - (x3 - x1) * (y - y1);

                if (w0 >= 0 && w1 >= 0 && w2 >= 0) {
                    SDL_RenderDrawPoint(ren, x, y);
                }
            }
        }
    } else if (type == OUTLINE) {
        SDL_RenderDrawLine(ren, x1, y1, x2, y2);
        SDL_RenderDrawLine(ren, x2, y2, x3, y3);
        SDL_RenderDrawLine(ren, x3, y3, x1, y1);
    }
}

void draw_circle(Color color, int cx, int cy, int radius, ShapeType type) {
    SDL_SetRenderDrawColor(ren, color.r, color.g, color.b, color.a);

    if (type == FILLED) {
        for (int w = 0; w < radius * 2; w++) {
            for (int h = 0; h < radius * 2; h++) {
                int dx = radius - w; // horizontal offset
                int dy = radius - h; // vertical offset
                if ((dx * dx + dy * dy) <= (radius * radius)) {
                    SDL_RenderDrawPoint(ren, cx + dx, cy + dy);
                }
            }
        }
    } else if (type == OUTLINE) {
        int d = 3 - 2 * radius;
        int x = 0, y = radius;

        while (y >= x) {
            SDL_RenderDrawPoint(ren, cx + x, cy + y);
            SDL_RenderDrawPoint(ren, cx - x, cy + y);
            SDL_RenderDrawPoint(ren, cx + x, cy - y);
            SDL_RenderDrawPoint(ren, cx - x, cy - y);
            SDL_RenderDrawPoint(ren, cx + y, cy + x);
            SDL_RenderDrawPoint(ren, cx - y, cy + x);
            SDL_RenderDrawPoint(ren, cx + y, cy - x);
            SDL_RenderDrawPoint(ren, cx - y, cy - x);
            x++;
            if (d > 0) {
                y--;
                d = d + 4 * (x - y) + 10;
            } else {
                d = d + 4 * x + 6;
            }
        }
    }
}

// =====================CLEAR SCREEN, REFRESH AND PRESENT FUNCTION==========================

void clear_screen(Color color) {
    SDL_SetRenderDrawColor(ren, color.r, color.g, color.b, color.a);
    SDL_RenderClear(ren);
}

void present() {
    SDL_RenderPresent(ren);
}

// =============IMG, AUDIO LOAD===========================

void load_img(const char *path) {
    SDL_Surface *img = IMG_Load(path);
    if (img == NULL) {
        printf("IMG_Load Error: %s\n", IMG_GetError());
        return;
    }
    
    SDL_Texture *temp_tex = SDL_CreateTextureFromSurface(ren, img);
    if (temp_tex == NULL) {
        printf("SDL_CreateTextureFromSurface Error: %s\n", SDL_GetError());
        SDL_FreeSurface(img);
        return;
    }

    SDL_RenderCopy(ren, temp_tex, NULL, NULL);
    SDL_RenderPresent(ren);

    SDL_DestroyTexture(temp_tex);
    SDL_FreeSurface(img);
}

// =================WRITE TEXT (SDL_TTF)=======================
// global variables
TTF_Font *font = NULL;

int load_font(const char *path, int size) {
    // Load font
    font = TTF_OpenFont(path, size);
    if (!font) {
        printf("Failed to load font! TTF_Error: %s\n", TTF_GetError());
        return -1;
    }
    return 0;
}

int write_text(const char *text, Color color) {
    SDL_Color sdl_color = {color.r, color.g, color.b, color.a};
    
    // Render text to surface
    SDL_Surface *textSurface = TTF_RenderText_Solid(font, text, sdl_color);
    if (!textSurface) {
        printf("Unable to render text surface! TTF_Error: %s\n", TTF_GetError());
        return -1;
    }

    // Create a Texture from the Surface
    SDL_Texture *textTexture = SDL_CreateTextureFromSurface(ren, textSurface);
    if (!textTexture) {
        printf("Unable to create texture from rendered text! SDL_Error: %s\n", SDL_GetError());
        SDL_FreeSurface(textSurface);
        return -1;
    }

    // Render the text
    SDL_Rect dst = {0, 0, textSurface->w, textSurface->h};
    SDL_RenderCopy(ren, textTexture, NULL, &dst);

    // Clean up the surface and texture
    SDL_FreeSurface(textSurface);
    SDL_DestroyTexture(textTexture);

    return 0;
}
// draw text is different from write text, in draw text you get extral control over x,y,w,h
int draw_text(const char *text,int x, int y, int w, int h, Color color) {
    SDL_Color sdl_color = {color.r, color.g, color.b, color.a};
    
    // Render text to surface
    SDL_Surface *textSurface = TTF_RenderText_Solid(font, text, sdl_color);
    if (!textSurface) {
        printf("Unable to render text surface! TTF_Error: %s\n", TTF_GetError());
        return -1;
    }

    // Create a Texture from the Surface
    SDL_Texture *textTexture = SDL_CreateTextureFromSurface(ren, textSurface);
    if (!textTexture) {
        printf("Unable to create texture from rendered text! SDL_Error: %s\n", SDL_GetError());
        SDL_FreeSurface(textSurface);
        return -1;
    }

    // Render the text
    SDL_Rect dst = { x, y, w, h };
    SDL_RenderCopy(ren, textTexture, NULL, &dst);

    // Clean up the surface and texture
    SDL_FreeSurface(textSurface);
    SDL_DestroyTexture(textTexture);

    return 0;
}
