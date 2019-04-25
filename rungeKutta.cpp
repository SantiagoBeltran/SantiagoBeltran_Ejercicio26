#include <iostream>
#include <fstream>
using namespace std;


void solve_equation_euler(float t_init, float t_end, float delta_t, float omega, string filename);
void solve_equation_rk4(float t_init, float t_end, float delta_t, float omega, string filename);
void solve_equation_leapfrog(float t_init, float t_end, float delta_t, float omega, string filename);

int main(){
  float omega=1.0;
  solve_equation_euler(0.0, 10000.0, omega/2, omega, "euler.dat");
  solve_equation_rk4(0.0, 10000.0, omega/2, omega, "rk4.dat");
  solve_equation_leapfrog(0.0, 10000.0, omega/2, omega, "leapfrog.dat"); 
  return 0;
}

void solve_equation_rk4(float t_init, float t_end, float delta_t, float omega, string filename){
  float t=t_init;
  float y=1.0; 
  float z=0.0;
  float z_0=0.0; 
    
  ofstream outfile;
  outfile.open(filename);

  while(t<t_end){    
    outfile << t << " " << z << " "<< y << endl;
    float y1, y2, y3,z1, z2, z3, f0, f1,f2,f3,f4, g4=0;
  f0=-1*omega*omega*y;   
  z1=z+f0*delta_t/2;
  y1=y+z_0*delta_t/2;    
  f1=-1*omega*omega*y1;
  z2=z+f1*delta_t/2;  
  y2=y+z1*delta_t/2;
  f2=-1*omega*omega*y2;
  z3=z+f2*delta_t;    
  y3=y+z2*delta_t;
  f3=-1*omega*omega*y3;
  f4=f0/6+f1/3+f2/3+f3/6; 
  g4=z_0/6+z1/3+z2/3+z3/6;    
    z = z + delta_t * f4; 
    y = y + delta_t*g4;
    z_0=z;  
    t = t + delta_t;
  }
  outfile.close();
}

void solve_equation_euler(float t_init, float t_end, float delta_t, float omega, string filename){
    float t=t_init;
  float y=1.0; 
  float z=0.0;
  float z_0=0.0; 
    
  ofstream outfile;
  outfile.open(filename);
  while(t<t_end){    
    outfile << t << " " << z << " "<< y << endl; 
    z = z - delta_t *omega*omega*y; 
    y = y + delta_t*z_0;
    z_0=z;  
    t = t + delta_t;
  }    
}    

void solve_equation_leapfrog(float t_init, float t_end, float delta_t, float omega, string filename){
    float t=t_init;
    float y=1.0;
    float z=0.0;
    float z1=0.0;
    float y1;
  z1=z-omega*omega*y*delta_t/2; 
    ofstream outfile;
  outfile.open(filename);
    while(t<t_end){
    outfile << t << " " << z1 << " "<< y << endl; 
       
    y=y+z1*delta_t;
    z1=z1-omega*omega*y*delta_t; 
    t=t+delta_t;}    
}
