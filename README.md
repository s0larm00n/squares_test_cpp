# Square dragging demo app

This is a simple 2D graphics showcase project written in C++ with OpenGL 3.3 and GLFW 3. Tested on MacOS and Windows.

To run this application, you need to pass path to /shaders folder in project directory as program argument. You can use existing run configurations in this project for CLion or Visual Studio, both named 'Run squares test'.

After app launches, you will see an empty screen. Clicking at empty space at the app window at any time will cause a square creation. There is no square deletion functionality in this app. There is no limit of how many squares can be created.

Each square gets a random color when it is created. The size of a new square is equal to 10% of the lesser side of the window. The square you have last interacted with will also have a white border (5px) on top of it. The square you have last interacted with is also being placed on top layer.

If you click at an existing square, you will be able to drag the square around the window. The squares' coordinates are restricted to fit the window's current dimensions.

In case the window is being resized, a boundaries check will be re-run for every square.

![img_2.png](screenshots%2Fimg_2.png)
