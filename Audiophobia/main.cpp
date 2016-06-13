//
//  main.cpp
//  Audiophobia
//
//  Created by Miguel Cuellar on 2/29/16.
//  Copyright © 2016 Miguel Cuellar. All rights reserved.
//

#include <iostream>
#include <limits.h>
using namespace std;
int main() {
    int casos,C,S,Q,c1,c2,d;
    cin>>casos;
    for(int i = 1; i<=casos; i++){
        cin>>C>>S>>Q;
        int control[C][C];
        for (int ix=0; ix<C; ix++) {
            for (int iy=0; iy<C; iy++) {
                (ix==iy) ? control[ix][iy]=0 : control[ix][iy]=INT_MAX;
            }
        }
        for (int is=0; is<S; is++) {
            cin>>c1>>c2>>d;
            control[c1-1][c2-1]=d;
            control[c2-1][c1-1]=d;
        }
        /*
        for (int ix=0; ix<C; ix++) {
            for (int iy=0; iy<C; iy++) {
                cout<<control[ix][iy]<<" ";
            }
            cout<<endl;
        }
     */
        
        for(int k = 0; k < C; k++)
            for(int i = 0; i < C; i++)
                for(int j = 0; j < C; j++){
                    if(control[i][j]>max(control[i][k],control[k][j]))
                        control[i][j]=max(control[i][k],control[k][j]);
                }
        cout<<"Case "<<i<<":"<<endl;
        for (int iQ=1; iQ<=Q; iQ++) {
            cin>>c1>>c2;
            control[c1-1][c2-1]==INT_MAX ? cout<<"no path"<<endl : cout<<control[c1-1][c2-1]<<endl;
        }
        
    }
    
    return 0;
}
