# Priscilla 
the code base is splited across several files: 
```src/
      window.c window.h
      button.c button.h
      label.c label.h
      textbox.c textbox.h
      others will be added later (entry, containers, grid, ...)
```
each file contains it's own implementation like for example the window.c handles the ```c window_init()``` and the ```quit()```, while the button.c handles code for button.
all implementation should small letters all through like ```window_init()``` instead of ```Window_Init()``` or ```WINDOW_INIT()``` as users can code faster that way

# To-Do List
Below is a list of tasks that need to be implemented for the GUI library.

## Core Features
- [x] Basic window implemetation 
- [ ] Button component with click events
- [ ] Label component for displaying text
- [ ] Text box/Entry component for user input
- [ ] Container component for organizing GUI elements

## Advanced Features
- [ ] Customizable styling for components
- [ ] Support for different font types and sizes
- [ ] Implement mouse hover effects for interactive components
- [ ] Ability to handle keyboard input for focused components

## UI/UX Improvements
- [ ] Responsive layout for different screen sizes
- [ ] Implement basic animations for smoother transitions
- [ ] Support for tooltips for better user guidance
- [ ] Implement a simple event system for inter-component communication

## Documentation and Testing
- [ ] Write documentation for the API usage
- [ ] Implement unit tests for each component
- [ ] Ensure cross-platform compatibility with SDL2

Feel free to contribute to the project
