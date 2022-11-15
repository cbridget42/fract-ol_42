# fract-ol  
It's a basic computer graphics project.  
  
You need to draw some fractals such as the julia set and Mandelbrot set, use the school graphical library,  
this library includes basic necessary tools to open window, create images and deal with Keyboard and mouse.  
If you don't get what fractals are, you can read about it [here](https://en.wikipedia.org/wiki/Fractal)
* Mandatory part  
	+ 1-The mouse wheel zooms in and out, almost infinitely.  
	+ 2-You must be able to create different Julia sets.  
	+ 3-You must use at least a few colors to show the depth of each fractal.  
* Bonus part  
	+ 1-One more different fractal.  
	+ 2-The zoom follow the actual mouse position.  
	+ 3-Make the color ranger shift.  
  
You can see the full assignment here [subject](https://github.com/cbridget42/fract-ol_42/blob/main/subject/en.subject.pdf)  
Coding style: [norminette](https://github.com/cbridget42/fract-ol_42/blob/main/subject/en.norm.pdf)  
  
### Usage:
* You need to download the repository and compile the code! To do this, run:
	```bash
	git clone git@github.com:cbridget42/fract-ol_42.git
	cd fract-ol_42
	make
	```
* then you will have a fractol file. Exemple usage:
	```bash
	./fractol Mandelbrot
	```
	```bash
	./fractol Julia 0.5 0.5 //you can replace 0.5 with any number between -1 and 1
	```
	```bash
	./fractol Burning_ship
	```
  
### Keyboard shortcuts
<table width="100%">
<thead>
<tr>
<td width="65%" height="60px" align="center" cellpadding="0">
<strong>Description</strong>
</td>
<td width="10%" align="center" cellpadding="0">
<span style="width:70px">&nbsp;</span><strong>Key</strong><span style="width:50px">&nbsp;</span>
</td>
</tr>
</thead>
<tbody>
<tr>
<td valign="top" height="30px">zoom in</td>
<td valign="top" align="center"><kbd>&nbsp;i&nbsp;</kbd> or <kbd>&nbsp;scroll wheel&nbsp;</kbd></td>
</tr>
<tr>
<td valign="top" height="30px">zoom out</td>
<td valign="top" align="center"><kbd>&nbsp;k&nbsp;</kbd> or <kbd>&nbsp;scroll wheel&nbsp;</kbd></td>
</tr>
<tr>
<td valign="top" height="30px">move</td>
<td valign="top" align="center"><kbd>&nbsp;▲&nbsp;</kbd><kbd>&nbsp;▼&nbsp;</kbd><kbd>&nbsp;◄&nbsp;</kbd><kbd>&nbsp;►&nbsp;</kbd></td>
</tr>
<tr>
<td valign="top" height="30px">increase render depth</td>
<td valign="top" align="center"><kbd>&nbsp;o&nbsp;</kbd></td>
</tr>
<tr>
<td valign="top" height="30px">decrease render depth</td>
<td valign="top" align="center"><kbd>&nbsp;p&nbsp;</kbd></td>
</tr>
<tr>
<td valign="top" height="30px">change color scheme</td>
<td valign="top" align="center"><kbd>&nbsp;h&nbsp;</kbd></td>
</tr>
<tr>
<td valign="top" height="30px">Close the program</td>
<td valign="top" align="center"><kbd>&nbsp;esc&nbsp;</kbd></td>
</tr>
<tr>
</tbody>
</table>
  
### ScreenShots:
![image](https://github.com/cbridget42/fract-ol_42/blob/main/images/Screen%20Shot%202022-09-15%20at%207.08.58%20PM.png)
![image](https://github.com/cbridget42/fract-ol_42/blob/main/images/Screen%20Shot%202022-09-15%20at%207.12.24%20PM.png)
![image](https://github.com/cbridget42/fract-ol_42/blob/main/images/Screen%20Shot%202022-11-15%20at%204.44.23%20PM.png)
![image](https://github.com/cbridget42/fract-ol_42/blob/main/images/Screen%20Shot%202022-09-15%20at%207.15.18%20PM.png)
![image](https://github.com/cbridget42/fract-ol_42/blob/main/images/Screen%20Shot%202022-09-15%20at%207.17.23%20PM.png)
  
### final score:
![image](https://github.com/cbridget42/fract-ol_42/blob/main/images/Screen%20Shot%202022-09-15%20at%207.19.16%20PM.png)
  
