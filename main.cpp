
/********************************************************************
*                         INVENTORY SYSTEM 3.0                      *
*    This program is a Inventory System with Output/Input Files.    *
*                           Version 1.0                             *
*      Lucas Nicolas Greco (grecolucas477@yahoo.com.ar)             *
*                                                                   *
********************************************************************/

#include <iostream>
#include <windows.h>
#include <time.h>
#include <cstdlib>
#include <conio.h>
#include <iomanip>
#include <fstream>


using namespace std;

#include "Headers/Structs.h"
#include "Headers/Funciones.h"




int main()
{
    for (int i = 0; i<Max_Chars ; i++)
    {
        File_Name[i] = 0;
    }

    for(;;)
    {
        switch (Wait_Option ())
        {
            case 1:
                New_Product ();
            break;

            case 2:
                Delete_Product ();
            break;

            case 3:
                Buy_Product ();
            break;

            case 4:
                Sell_Product ();
            break;

            case 5:
                Report_Product ();
            break;

            case 6:
                Save_File ();
            break;

            case 7:
                Load_File ();
            break;

            case 8:
                return EXIT_SUCCESS;
            break;
        }
    }
}
