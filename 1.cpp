#include <iostream>
#include <cmath>

using namespace std;

double Ve=100.,Me=0.1,M0=1.0,g=9.81;

double dVrdt(double t){
    
        return Ve*Me/(M0-Me*t)-g;
    }

int main(){
    
    int N;
    double *Vrk, *Z1;
    double time,dT(0.05),ET=1;
    double k1,k2;
    
    N=ET/dT;
    
    Vrk=new double [N+1];
    Z1=new double [N+1];
    
    time=-dT;
    Vrk[0]=0.;
    Z1[0]=0.;
    
    time+=dT;
    Vrk[1]=0.;
    Z1[1]=0.;
    
    for(int i=0;i<N;i++){
        
        k1=dT*dVrdt(time);
        k2=dT*dVrdt(time+dT);
        Vrk[i+1]=Vrk[i]+0.5*(k1+k2);
        Z1[i+1]=Z1[i]+dT*0.5*(Vrk[i]+Vrk[i+1]);
        time+=dT;
        
        cout<<time<<" "<<Z1[i+1]<<endl;
        
        
        
    }
    
    
    return 0;
}
