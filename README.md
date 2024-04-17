**By usage of Qt library and C++ programming language, developed a "Cannon and the Battleship"  application with following features:**
The application will be based on one MainWindow.
The balls will appear at the right part of the window in regular intervals. 
The horizontal position of the new ball will be set by a random generator (in terms of window height)
After the ball creation, the ball will start moving from right side of the window to the left. ( assuming as shooting balls)
The specific direction of the ball coming from the right will be set randomly - the ball won't move in fixed position only horizontally but will have some slight up or down movement and will be reflected by walls if necessary. 
When the ball reaches the  left side of the window, it disappears (it need to be correctly destroyed).
In the left part of the main window, there will be a small rectangle (representing the battle ship), which can be moved to the up /down by a mouse or keyboard.
Every hit can cause the game stop, and the time between game start and game stop will be the "score".
Put a start button for the game to be started.
The whole application needs to be cross-platform and use Qt library and QTimers.
