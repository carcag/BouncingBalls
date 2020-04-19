# BouncingBalls
A small program using SFML to simulate a closed area with some bouncing balls.

## Usage

Just click on the window area to create a random ball which will start bouncing. Click again to make other balls appear.

## Possible enhancements
- Check location of balls appearing area to avoïd overlap,
- Make GameHandler responsable for the bounces on the edge of the map (actually handled by the ball itself)
- Create a function to check for collisions with rectangles, add two Racket objects, link one to the keyboard keys by event, add a simili-AI to the other, count points when a ball touch an "X" edge, and then make it more like the Pong game that it intended to be :)
- Adaptative view when window is resized
