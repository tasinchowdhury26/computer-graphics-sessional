
> **Aim of the project**

To build a visual representation of a cityscape in three different times of a day. 


> **Description**

OpenGL provides a gigantic library which we chose to go with for the implementation. It has structured manner of calling the functions. 

The <GL/glut.h> header includes the necessary graphical functions of OpenGL, which we used for initializing the viewport, scaling the window and basically drawing all the shapes. <iostream> , <math.h> and other header help us doing various calculations and seemlessly handling the input-output. 

Along with the main function, there are 10 more user-defined functions within the codebase. The init function initializes the whole OpenGL visual functionalities, however the manner of its usage may differ between various operating systems. For example, In our team, two members use Windows and the other one use Linux which caused them adjusting back and forth. 

The display function is basically where the static objects are created with mostly glVertex3f and glVertex2f in some cases. In our project, the scale of the viewport is 0 to 500 in X-axis, and 0 to 300 in Y-axis. We divided the regions during planning for making it more convenient to put the objects in place.  

start_moving and changeDay methods are directly responsible for bringing the static objects in life. Also we have done some adjustments to switch colors and positions to match with the different times of the day as we declared in the variable day_mood. 

Last but not least, the my_keyboard method is defined to handle the key presses for making all the transitions to happen. The a, d and n key changes the daytime to afternoon, day and night respectively. The m key fires the start_moving method and the speed can be adjusted with s and f. We have also included raining with the key r pressed. 



> **Conclusion **

In the beginning of the project, we learned the basics of OpenGL. Then we started putting piece by piece in it and tried our best to bring out the best out of it.  We are more enthusiastic about learning more of it, so that we can be a part of the modern technological realm, and share our innovative ideas. And we are very grateful to our instructor who has been really nice to us in all circumstances.  We appreciate her effort in guiding us to make this project happen. 

Some images of the project outcome: 
![Afternoon](https://i.ibb.co/NtgdjG5/Screenshot-from-2022-11-28-02-07-12.png)
![Day](https://i.ibb.co/wr2QgDb/Screenshot-from-2022-11-28-02-07-02.png)
![Rain](https://i.ibb.co/WsQ3YJv/Screenshot-from-2022-11-14-01-32-54.png)
![Night Rain](https://i.ibb.co/1rqQ0z9/Screenshot-from-2022-11-28-02-07-32.png)

