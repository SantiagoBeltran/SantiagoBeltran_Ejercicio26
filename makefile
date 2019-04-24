SegundaDerivada.png: datos1.dat
	python graficador.py 

datos1.dat: runge.x
	./runge.x > datos1.dat

runge.x: rungeKutta.cpp
	c++ rungeKutta.cpp -o runge.x

clean:
	rm -rf *.x *.dat *.png