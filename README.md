# Practice-1
## Processor ring cumulative sum
First practice of High Performance Computing at [National Autonomus University of Mexico](https://www.unam.mx/) (2023-2)

Karime Ochoa Jacinto karime8aj@gmail.com

GNU/GPL License 3.0
## Project description

A processor ring is a network topology that connects multiple processors in a circle in wich each node is connected to two adjacent processors in the ring, forming a loop. As shown in the image below:


![](https://github.com/Kadkam8a/Practice-1/blob/main/ring%20topology.jpg 'Image-r')

Taken from: https://sites.google.com/site/networktopologies12/home/ring--the-beginning

This program in particular makes a cumulative sum from an initial value $x0$ for $m$ cycles in the ring helped by [MPICH](https://www.mpich.org/) 
