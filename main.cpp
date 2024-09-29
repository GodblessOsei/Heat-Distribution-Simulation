/*The goal of this software is to  stimulate the thermal distribution in a thin metal plate in a form of a grid with unknown dimensions. The software presents the user with options to:(1) Create the dynamic 2D grid (2) Set initial side temperature values for the grid, (3) Stimulate the grid at a specific point, (4) calculate the thermal distribution based on the specific stimulation and initial conditions (and save the results in an image file), (5) Print the thermal grid on the screen, or (6) Exit the program.
 ***********************************************************/

#include <iostream> //for input and output
#include <iomanip>
#include "Functions.h"
#include "Bitmap_Helper.h"
using namespace std;

int main(){
    int choice = 0;
    int rowOfstimulationpnt = 0;
    int colOfstimulationpnt = 0;
    double constTopTemperature = 0, constBottomTemperature = 0;
    double constLeftTemperature = 0, constRightTemperature = 0;
    double ToleranceValue = 0, StimulationTemperature = 0;
    
    uint8_t** new_2Ddisplay =nullptr;
    
    double **SimulationGridPrt = nullptr;
    
    bool validate1 = false, validate2 = false, validate3 = false, validate4 = false;
    
    do{
        //Menu for the user to make a choice
        cout<<"Choose 1 to create a 2D grid for your simulation \n";
        cout<<"Choose 2 to set the side temperatures for your grid \n";
        cout<<"Choose 3 to set the point you want to stimulate your simulation and enter the specific temperature you want \n";
        cout<<"Choose 4 to calculate the thermal distribution based on the specific stimulation and initial conditions \n";
        cout<<"Choose 5 to view the thermal distribution simulation grid \n";
        cout<<"Choose 6 to exit the program \n";
        
        //Get value from the user
        cout<<"Please enter your choice: \n";
        cin>>choice;
        
        //Coditions of a user input
        switch (choice) {
                //When user enters 1
            case 1:
                cout << "Enter the number of rows of the grid \n";
                cin >> No_Rows;
                cout<< "Enter the number of columns of the grid \n";
                cin >> No_Columns;
                
                if(No_Rows <= 3 || No_Columns <= 3){
                    
                    cout << "The number of rows must be greater than 3 to get interior points which can be stimulated \n"<<"Enter a new number of rows \n";
                    cin >> No_Rows;
                    
                    cout <<"The number of column must be greater than 3 to get interior points which can be stimulated \n"<<"Enter a new number of columns \n";
                    cin>>No_Columns;
                }
                
                create2Dgrid(SimulationGridPrt, No_Rows, No_Columns);
                
                validate1 = true;
                
                break;
                
                //When user inputs 2
            case 2:
                
                if (validate1 == false) {
                    cout<<"You must create a grid first \n";
                    
                    break;
                }
                
                cout << "Enter the temperature of the top side of the thin film \n ";
                cin >> constTopTemperature;
                
                
                cout << "Enter the temperature of the bottom side of the thin film \n ";
                cin >> constBottomTemperature;
                
                
                
                cout << "Enter the temperature of the left side of the thin film \n ";
                cin >> constLeftTemperature;
                
                
                cout << "Enter the temperature of the right side of the thin film \n ";
                cin >> constRightTemperature;
                
                
                setBoundaryConditions(SimulationGridPrt, constTopTemperature, constBottomTemperature, constLeftTemperature, constRightTemperature);
                
                validate2 = true;
                
                break;
                
                //When user inputs 3
            case 3:
                
                if (validate1==false || validate2 == false) {
                    cout << "Create grid and initalize boundary conidition first \n";
                    
                    break;
                }
                
                cout << "Enter the row on which you want to stimulate the simulation grid \n";
                cin >> rowOfstimulationpnt;
                
                cout << "Enter the column on which you want to stimulate the simulation grid \n";
                cin >> colOfstimulationpnt;
                
                cout << "Enter the stimulation temperature \n";
                cin >> StimulationTemperature;
                
                if(rowOfstimulationpnt <1 || rowOfstimulationpnt >= No_Rows-1 || colOfstimulationpnt <1 || colOfstimulationpnt >= No_Columns-1 ){
                    
                    cout<<"The row number you entered is invalid row or column \n"<<" Row should be between 1 and "<<No_Rows-1<<endl<<"Enter a new row \n ";
                    cin>>rowOfstimulationpnt;
                    
                    cout<<"Column should be between 1 and "<<No_Columns-1<<endl<<"Enter a new column \n";
                    cin>>colOfstimulationpnt;
                    
                   
                }
                
                stimulateGrid(SimulationGridPrt, rowOfstimulationpnt, colOfstimulationpnt, StimulationTemperature);
                
                validate3 = true;
                
                break;
                
                //When user inputs 4
            case 4:
                
                if (validate1 == false || validate2 == false || validate3 == false) {
                    cout<<"You must create a gride, set boundary temperature, and stimulate the grid first \n";
                    
                    break;
                }
                
                cout<< "Enter the tolerance value of your material \n";
                cin>>ToleranceValue;
                
                simulateThermalDissipation(SimulationGridPrt, ToleranceValue);
                
                new_2Ddisplay = converter(SimulationGridPrt, new_2Ddisplay);
                
                writeBitmap("ThermalDistribution.bmp", new_2Ddisplay, No_Rows, No_Columns);
                
                
                validate4 = true;
                
                break;
                //When user inputs 5
            case 5:
                
                if (validate1 == false || validate2 == false || validate3 == false || validate4 == false) {
                    cout<<"You must create a grid, initialize boundary temperature, stimulate it and start simulation before displaying \n";
                    
                    break;
                }
                
                displayGrid(SimulationGridPrt);
                
                delete2DArray(SimulationGridPrt, No_Rows);
                
                break;
                
                //when user inputs 6
            case 6:
                cout<<"You have successfully exited the program \n";
                
                exit(-1);
                
                break;
                
            default:
                cout<<"You have entered an invalid choice please try again \n";
                break;
        }
    }while (choice !=6);
    return 0;
}


