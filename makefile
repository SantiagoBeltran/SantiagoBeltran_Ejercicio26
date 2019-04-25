SegundaDerivada.png: rk4.dat euler.dat leapfrog.dat
	python graficador.py 

rk4.dat euler.dat leapfrog.dat: runge.x
	./runge.x 

runge.x: rungeKutta.cpp
	c++ rungeKutta.cpp -o runge.x

clean:
	rm -rf *.x *.dat *.png

