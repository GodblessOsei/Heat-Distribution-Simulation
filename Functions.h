//
//  Functions.h
//  Assignment_2
//
//  Created by NYUAD on 19/11/2023.
//

#ifndef Functions_h
#define Functions_h

using namespace std;

int No_Rows , No_Columns;

bool x;

double **diff2Darr = nullptr;

double **New2Darr = nullptr;

bool isLessThanTol(double **diffarr, double tolerance);

void delete2DArray(double**& dynamicArray, double rows);

/*This function takes the user's input for the dimensions of the 2D grid and creates a dynamic array of the set dimension -------------------------------------------------------------*/
void create2Dgrid(double ** &twoDgrid, int rows, int columns ){
    
    
    twoDgrid = new double *[rows];
    
    for(int i = 0; i<rows; i++){
        
        twoDgrid[i] = new double[columns];
    }
    
    for(int i = 0; i< rows; i++ ){
        
        for(int j = 0; j<columns; j++ ){
            
            twoDgrid[i][j]=0;
        }
    }
    
};
/*This function takes the user's input for the constant side temperatures of the grid and set the initial boundaries of the two dimensional array------------------------------------*/

//void setBoundaryConditions(double **twoDgrid,double sidetempTop, double sidetempBottom, double sidetempLeft, double sidetempRight ){

void setBoundaryConditions(double **twoDgrid, double sidetempTop, double sidetempBottom, double sidetempLeft, double sidetempRight){
    
    for(int j = 0; j<No_Columns; j++){
        
        twoDgrid[0][j] = sidetempTop;
        
        twoDgrid[No_Rows-1][j] = sidetempBottom;
    }
    
    for(int i = 1; i<No_Rows-1; i++){
        
        twoDgrid[i][0] = sidetempLeft;
        
        twoDgrid[i][No_Columns-1] = sidetempRight;
    }
    
};


/*This function takes a user's input for the point where he/she wants the stimulate to the grid and also the intensity or temperature he wants to stimulate the grid and modifies the 2D array accordingly---------------------------------------------------------------------- */
void stimulateGrid(double **twoDgrid, int rowOfsimpnt, int colOfsimpnt, double stimulationTemp ){
    
    twoDgrid[rowOfsimpnt][colOfsimpnt] = stimulationTemp;
    
};

/*This function takes the user input for the tolerance value and then runs the simulation by calculating the averages of four points surrounding an interior piont then modifies all the interior pionts untill the difference between the old and new interior points are less than the given threshold.----------------------------------------------------------
 The difference between the new interior temperatures and the old interior temperatures are stored in a 2D array*/

void simulateThermalDissipation(double **twoDgrid, double tolerancevalue){
        
    New2Darr = new double*[No_Rows];
    
    for(int i = 0; i<No_Rows; i++){
        
        New2Darr[i] = new double[No_Columns];
    }
    
    for(int i = 0; i<No_Rows; i++){
        
        for(int j = 0; j<No_Columns; j++ ){
            
            New2Darr[i][j] = twoDgrid[i][j];
        }
    }
    
    diff2Darr = new double*[No_Rows];
    
    for(int i = 0; i<No_Rows; i++){
        
        diff2Darr[i] = new double[No_Columns];
        
    }
    
    do{
        for(int i = 1; i<No_Rows-1; i++){
            
            for(int j = 1; j<No_Columns-1; j++){
                
                New2Darr[i][j] = (twoDgrid[i][j-1] + twoDgrid[i][j+1] + twoDgrid[i-1][j] + twoDgrid[i+1][j])/ 4;
                
                diff2Darr[i][j] = New2Darr[i][j] - twoDgrid[i][j];
                
                twoDgrid[i][j] = New2Darr[i][j];
                
            }
            
            x =  isLessThanTol(diff2Darr, tolerancevalue);
        }
    }while(x == false);
    
    
    
   
};

/*This Fuction takes all the differences between the inital interior temperatures and the new interior temperatures and checks if they are all less than the tolerance value given by the user --------------------------------------------------------------*/
bool isLessThanTol(double **diffarr, double tolerance){
    
    int ctr = 0;
    
    for(int i =0; i<No_Rows; i++){
        
        for(int j =0; j<No_Columns; j++){
            
            if (diffarr[i][j] < tolerance)
                
                ctr++;
            
            if(diffarr[i][j] > tolerance)
                
                return false;
            
            if(ctr == No_Rows * No_Columns)
                
                return true;
        }
    }
    return false;}


/*This Function displays the simulations of the thermal distribution to a user in the form of a 2D Array------------------------- */
void displayGrid(double **twoDgrid){
    
    for(int i = 0; i<No_Rows; i++)
    { int j = 0;
        do{
            cout << setw(10)<<twoDgrid[i][j];
            j++;
        }
        while(j<No_Columns);
        cout<<" "<<endl;
    }
};

uint8_t** converter(double** twoDgrid, uint8_t** new_array){
    
    new_array = new uint8_t*[No_Rows];
    
    for (int i = 0; i < No_Rows; ++i) {
        
        new_array[i] = new uint8_t[No_Columns];
        
    }
    
    
    
    // Convert each element from double to unsigned integer
    
    for (int i = 0; i < No_Rows; ++i) {
        
        for (int j = 0; j < No_Columns; ++j) {
            
            new_array[i][j] = static_cast<uint8_t>(twoDgrid[i][j]);
            
        }
        
    }
    
    return new_array;
  
    delete2DArray(New2Darr, No_Rows);
    
   delete2DArray(diff2Darr, No_Rows);
}

void delete2DArray(double**& dynamicArray, double rows) {
    for (int i = 0; i < rows; ++i) {
        delete[] dynamicArray[i];
    }
    delete[] dynamicArray;
}

#endif /* Functions_h */

