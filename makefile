SegundaDerivada.png: datos1.dat datos2.dat
	python graficador.py 

datos1.dat datos2.dat: runge.x
	./runge.x 

runge.x: rungeKutta.cpp
	c++ rungeKutta.cpp -o runge.x

clean:
	rm -rf *.x *.dat *.png
