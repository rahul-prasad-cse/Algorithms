#include<iostream>
#include<cstdlib>
#include<cmath>
#include<ctime>

using namespace std;

int** add(int maxm, int** matrixA,int** matrixB){
    int** matrix;
    matrix=new int*[maxm];
    for(int i=0;i<maxm;i++){
      matrix[i]=new int[maxm];
    }
    for(int i=0;i<maxm;i++){
      for(int j=0;j<maxm;j++){
        matrix[i][j]=matrixA[i][j]+matrixB[i][j];
      }
    }
    return matrix;
}

int** subtract(int maxm,int** matrixA,int** matrixB){
    int** matrix;
    matrix=new int*[maxm];
    for(int i=0;i<maxm;i++){
      matrix[i]=new int[maxm];
    }
    for(int i=0;i<maxm;i++){
      for(int j=0;j<maxm;j++){
        matrix[i][j]=matrixA[i][j]-matrixB[i][j];
      }
    }
    return matrix;
}

int** strassan(int Am,int An,int Bm,int Bn, int** matrixA,int** matrixB){
  int** outputMatrix;
  outputMatrix=new int*[1];
  outputMatrix[0]=new int[1];
  if(Am==1 && An==1 && Bm==1 && Bn==1){
    outputMatrix[0][0]=matrixA[Am-1][An-1]*matrixB[Bm-1][Bn-1];
    return outputMatrix;
  }
  int maxm=Am;
  int** A;
  A=new int*[maxm/2];
  int** B;
  B=new int*[maxm/2];
  int** C;
  C=new int*[maxm/2];
  int** D;
  D=new int*[maxm/2];
  int** E;
  E=new int*[maxm/2];
  int** F;
  F=new int*[maxm/2];
  int** G;
  G=new int*[maxm/2];
  int** H;
  H=new int*[maxm/2];
  for(int i=0;i<maxm/2;i++){
    A[i]=new int[maxm/2];
    B[i]=new int[maxm/2];
    C[i]=new int[maxm/2];
    D[i]=new int[maxm/2];
    E[i]=new int[maxm/2];
    F[i]=new int[maxm/2];
    G[i]=new int[maxm/2];
    H[i]=new int[maxm/2];
  }

  for(int i=0;i<maxm/2;i++){
    for(int j=0;j<maxm/2;j++){
      A[i][j]=matrixA[i][j];
    }
  }
  for(int i=0;i<maxm/2;i++){
    for(int j=0;j<maxm/2;j++){
      B[i][j]=matrixA[i][j+(maxm/2)];
    }
  }
  for(int i=0;i<maxm/2;i++){
    for(int j=0;j<maxm/2;j++){
      C[i][j]=matrixA[i+(maxm/2)][j];
    }
  }
  for(int i=0;i<maxm/2;i++){
    for(int j=0;j<maxm/2;j++){
      D[i][j]=matrixA[i+(maxm/2)][j+(maxm/2)];
    }
  }
  for(int i=0;i<maxm/2;i++){
    for(int j=0;j<maxm/2;j++){
      E[i][j]=matrixB[i][j];
    }
  }
  for(int i=0;i<maxm/2;i++){
    for(int j=0;j<maxm/2;j++){
      F[i][j]=matrixB[i][j+(maxm/2)];
    }
  }
  for(int i=0;i<maxm/2;i++){
    for(int j=0;j<maxm/2;j++){
      G[i][j]=matrixB[i+(maxm/2)][j];
    }
  }
  for(int i=0;i<maxm/2;i++){
    for(int j=0;j<maxm/2;j++){
      H[i][j]=matrixB[i+(maxm/2)][j+(maxm/2)];
    }
  }
  int** P1,**P2,**P3,**P4,**P5,**P6,**P7;
  P1=new int*[maxm/2];
  P2=new int*[maxm/2];
  P3=new int*[maxm/2];
  P4=new int*[maxm/2];
  P5=new int*[maxm/2];
  P6=new int*[maxm/2];
  P7=new int*[maxm/2];
  for(int i=0;i<maxm/2;i++){
    P1[i]=new int[maxm/2];
    P2[i]=new int[maxm/2];
    P3[i]=new int[maxm/2];
    P4[i]=new int[maxm/2];
    P5[i]=new int[maxm/2];
    P6[i]=new int[maxm/2];
    P7[i]=new int[maxm/2];
  }
  P1=strassan(maxm/2,maxm/2,maxm/2,maxm/2,A,(subtract(maxm/2,F,H)));
  P2=strassan(maxm/2,maxm/2,maxm/2,maxm/2,(add(maxm/2,A,B)),H);
  P3=strassan(maxm/2,maxm/2,maxm/2,maxm/2,add(maxm/2,C,D),E);
  P4=strassan(maxm/2,maxm/2,maxm/2,maxm/2,D,subtract(maxm/2,G,E));
  P5=strassan(maxm/2,maxm/2,maxm/2,maxm/2,add(maxm/2,A,D),add(maxm/2,E,H));
  P6=strassan(maxm/2,maxm/2,maxm/2,maxm/2,subtract(maxm/2,B,D),add(maxm/2,G,H));
  P7=strassan(maxm/2,maxm/2,maxm/2,maxm/2,subtract(maxm/2,A,C),add(maxm/2,E,F));
  int** XA,**XB,**XC,**XD;
  XA=new int*[maxm/2];
  XB=new int*[maxm/2];
  XC=new int*[maxm/2];
  XD=new int*[maxm/2];
  for(int i=0;i<maxm/2;i++){
    XA[i]=new int[maxm/2];
    XB[i]=new int[maxm/2];
    XC[i]=new int[maxm/2];
    XD[i]=new int[maxm/2];
  }
  XA=add(maxm/2,add(maxm/2,P5,P4),subtract(maxm/2,P6,P2));
  XB=add(maxm/2,P1,P2);
  XC=add(maxm/2,P3,P4);
  XD=subtract(maxm/2,add(maxm/2,P1,P5),add(maxm/2,P3,P7));
  int** X;
  X=new int*[maxm];
  for(int i=0;i<maxm;i++){
    X[i]=new int[maxm];
  }
  for(int i=0;i<maxm/2;i++){
    for(int j=0;j<maxm/2;j++){
      X[i][j]=XA[i][j];
    }
  }
  for(int i=0;i<maxm/2;i++){
    for(int j=0;j<maxm/2;j++){
      X[i][j+maxm/2]=XB[i][j];
    }
  }
  for(int i=0;i<maxm/2;i++){
    for(int j=0;j<maxm/2;j++){
      X[i+maxm/2][j]=XC[i][j];
    }
  }
  for(int i=0;i<maxm/2;i++){
    for(int j=0;j<maxm/2;j++){
      X[i+int(maxm/2)][j+int(maxm/2)]=XD[i][j];
    }
  }
  return X;
}

int main()
{
  srand(time(NULL));
  int Am=int(rand()%8+2),An=int(rand()%8+2),Bm,Bn=int(rand()%8+2);
  Bm=An;
  int maxm=Am;
  if(An>maxm){
    maxm=An;
  }
  if(Bm>maxm){
    maxm=Bm;
  }
  if(Bn>maxm){
    maxm=Bn;
  }
  int p=1;
  while(int(maxm/pow(2,p))!=0){
    p+=1;
  }
  maxm=int(pow(2,p));
  cout<<"              "<<maxm<<"                 \n";
  int** matrixA;
  matrixA=new int*[maxm];
  for(int i=0;i<maxm;i++){
    matrixA[i]=new int[maxm];
  }
  for(int i=0;i<Am;i++){
    for(int j=0;j<An;j++){
      matrixA[i][j]=rand()%100;
    }
  }
  for(int i=Am;i<maxm;i++){
    for(int j=An;j<maxm;j++){
      matrixA[i][j]=0;
    }
  }
  int** matrixB;
  matrixB=new int*[maxm];
  for(int i=0;i<maxm;i++){
    matrixB[i]=new int[maxm];
  }
  for(int i=0;i<Bm;i++){
    for(int j=0;j<Bn;j++){
      matrixB[i][j]=rand()%100;
    }
  }
  for(int i=Bm;i<maxm;i++){
    for(int j=Bn;j<maxm;j++){
      matrixB[i][j]=0;
    }
  }
  int** outputMatrix;
  outputMatrix= new int*[maxm];
  for(int i=0;i<maxm;i++){
    outputMatrix[i]=new int[maxm];
  }
  outputMatrix = strassan(maxm,maxm,maxm,maxm,matrixA,matrixB);
  cout<<"\nMatrixA : \n";
  for(int i=0;i<Am;i++){
    for(int j=0;j<An;j++){
      cout<<matrixA[i][j];
      cout<<" ";
    }
    cout<<"\n";
  }
  cout<<"\nMatrixB : \n";
  for(int i=0;i<Bm;i++){
    for(int j=0;j<Bn;j++){
      cout<<matrixB[i][j];
      cout<<" ";
    }
    cout<<"\n";
  }
  cout<<"\nMatrixA X MatrixB : \n";
  for(int i=0;i<Am;i++){
    for(int j=0;j<Bn;j++){
      cout<<outputMatrix[i][j];
      cout<<" ";
    }
    cout<<"\n";
  }
  return 0;
}
