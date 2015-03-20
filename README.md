[![Build Status](https://webapi.biicode.com/v1/badges/diego/diego/opencvex/master)](https://www.biicode.com/diego/opencvex) 

# Getting started with OpenCV and biicode

OpenCV is a great open source project, it is the most popular reference in Computer Vision around the globe.
It is well engineered and packaged, with very convenient CMake files. It is also a very big project, with
thousands of files and many build options, so modularizing it in different blocks and uploading to biicode
could probably take a large effort. Instead, it has been made available in biicode through a couple of hooks, one
for the mainstream version 2.4.10 and other for 3.0-beta.

This is a very convenient way to get started with OpenCV, for teaching purposes, prototyping, etc., as the process
with biicode is always exactly the same in any platform: Win, Linux, Mac.

These hooks will download, build if necessary and configure OpenCV in order to make it available for your projects.

After downloading and installing biicode, run the following for getting the examples from biicode:

	$ bii init mycvproject
	$ cd mycvproject
	$ bii open diego/opencvex

You can also start cloning this repo:

	$ git clone https://github.com/drodri/opencv-getting-started.git
	$ cd opencv-getting-started
	$ bii init -L

Then:

	$ bii configure

If in windows you should use VS 12 or other VS instead.

	$ bii configure -G "Visual Studio 12" 

Then we can build the project. Note that this can take a while, until it downloads and builds OpenCV. Note, however,
that this is done only once in your machine, in your "user/.biicode" folder. If the opencv installation process fails,
you might simply want to go there, delete opencv files inside "user/.biicode" and repeat. 

	$ bii build

Your binaries are located inside the bin folder:

	$ cd bin
	$ ./diego_opencvex_main

![BiiCV](https://raw.githubusercontent.com/drodri/opencv-getting-started/master/biiapp.png)


	$ ./diego_opencvex_mainfaces


![BiiCV](https://raw.githubusercontent.com/drodri/opencv-getting-started/master/lena.png)

## Developing your own application

In the previous step, an existing biicode block with examples was opened in order to get started.
To start from scratch your own application, you should do the following:

	$ bii init mycvproject -L
	$ cd mycvproject

Now you can just write a main.cpp file in this folder and #include OpenCV as:

	#include "diego/opencv/opencv/cv.h"

If you type

	$ bii deps

You will check that opencv/cv.h is an "unresolved" dependency. You can find it with:

	$ bii find

Now, you can just configure and build your project as described above.

If you want simpler #include directives, you can configure it in your biicode.conf file. Let your includes be:

	#include "opencv/cv.h"

And then just write in your biicode.conf:

	[includes]
		 opencv/cv.h: diego/opencv

	[requirements]
		 diego/opencv: 0

## Switching OpenCV versions

If you want to try or develop your application against opencv 2.4.10 and also try 3.0-beta, you can change easily in
your biicode.conf file, simply alternating track in your requirements

	[requirements]
		 diego/opencv: 2

replace with:

	[requirements]
		 diego/opencv(beta): 2

Note that the first time you switch to 3.0-beta, it will also take a while to download and build the 3.0-beta release.
From that point you can easily change forth and back between versions, just modifying your biicode.conf requirements.

The hooks that will be used are in these blocks:

 * [OpenCV 2.4.10](http://www.biicode.com/diego/opencv)
 * [OpenCV 3.0 beta](http://www.biicode.com/diego/diego/opencv/beta)


This is just an example of how can it be done with biicode python hooks. Probably now that CMake files reuse is possible, 
it could be better to implement it with CMake, in order to get more control over the build of OpenCV.

If you have any trouble with these examples, please ask in http://forum.biicode.com, I will try to address issues there.
