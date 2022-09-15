# fract-ol  
  
It's a basic computer graphics project.  
  
### Requirements:
You need to draw some fractals such as the julia set and Mandelbrot set, use the school graphical library,  
this library includes basic necessary tools to open window, create images and deal with Keyboard and mouse.  
* Mandatory part  
+ 1-The mouse wheel zooms in and out, almost infinitely.  
+ 2-You must be able to create different Julia sets.  
+ 3-You must use at least a few colors to show the depth of each fractal.  
* Bonus part  
+ 1-One more different fractal.  
+ 2-The zoom follow the actual mouse position.  
+ 3-Make the color ranger shift.  
  
### Usage:
* You need to download the repository and compile the code! To do this, run:
	```bash
	git clone git@github.com:cbridget42/fract-ol_42.git
	cd libft_42
	make
	```
* then you will have a fractol file. Exemple usage:
	```bash
	./fractol Mandelbrot
	```
  
	```bash
	./fractol Julia 0.5 0.5
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
<td valign="top" height="30px">Close the program</td>
<td valign="top" align="center"><kbd>&nbsp;esc&nbsp;</kbd></td>
</tr>
<tr>
<td valign="top" height="30px">image enlargement</td>
<td valign="top" align="center"><kbd>&nbsp;i&nbsp;</kbd> and <kbd>&nbsp;mouse&nbsp;</kbd></td>
</tr>
<tr>
<td valign="top" height="30px">reduce the image</td>
<td valign="top" align="center"><kbd>&nbsp;k&nbsp;</kbd> and <kbd>&nbsp;mouse&nbsp;</kbd></td>
</tr>
<tr>
