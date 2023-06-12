#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

COORD coord = {0,0};
char KEY_PAD;

struct Article_Struct *Pointer_Articles[100];

void gotoxy(int x,int y);
void Show_Title (void);
int Wait_Option (void);
int New_Product (void);
int Delete_Product (void);
int Buy_Product (void);
int Sell_Product (void);
int Report_Product (void);
int Get_Elements_Number (void);
void Init_Structure_Elements (int Article);
int Save_File (void);
int Load_File (void);
void Show_Error (char *Pointer_String, int Show_Delay_us);

int Counter_Articles = 0;
char File_Name [Max_Chars];
float Total_Inventary = 0;



/* 
/********************************************************************
*  [LNG 2023-06-11]     Function:  gotoxy                           *
* Input Arguments:                                                  *
*- Integers: Coordenates X and Y in screen.                         *
* Output Arguments:                                                 *
* -----------------                                                 *
* This function move the cursor to an specific coordenates.         *
********************************************************************/
void gotoxy(int x,int y)
{
    coord.X=x;
    coord.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}

/********************************************************************
*   [LNG 2023-06-11]   Function: Select_Option                      *
*        This function only present de program to the user.         *
********************************************************************/
void Show_Title (void)
{
    int X = 0;
    int Y = 0;

    system("cls");

    char Line1[] = {"  ----------------------------------------------------------------------------   "};
    char Line2[] = {" |                          INVENTORY SYSTEM V.3.0                            |  "};
    char Line3[] = {" |                                                                            |  "};
    char Line4[] = {" |                         grecolucas477@yahoo.com.ar                         |  "};
    char Line5[] = {" |                                                                            |  "};
    char Line6[] = {"  ----------------------------------------------------------------------------   "};


    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), Color_Green);
    gotoxy (X,Y+2);
    for (unsigned int i= 0; i < sizeof(Line1); i++)
    {
        cout << Line1[i];
        Sleep(Delay_us);
    }
    gotoxy (X,Y+3);
    for (unsigned int i= 0; i < sizeof(Line2); i++)
    {
        cout << Line2[i];
        Sleep(Delay_us);
    }
    gotoxy (X,Y+4);
    for (unsigned int i= 0; i < sizeof(Line3); i++)
    {
        cout << Line3[i];
        Sleep(Delay_us);
    }
    gotoxy (X,Y+5);
    for (unsigned int i= 0; i < sizeof(Line4); i++)
    {
        cout << Line4[i];
        Sleep(Delay_us);
    }
    gotoxy (X,Y+6);
    for (unsigned int i= 0; i < sizeof(Line5); i++)
    {
        cout << Line5[i];
        Sleep(Delay_us);
    }
    gotoxy (X,Y+7);
    for (unsigned int i= 0; i < sizeof(Line6); i++)
    {
        cout << Line6[i];
        Sleep(Delay_us);
    }

    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), Color_Def);
}

/********************************************************************
* [LNG 2023-06-11] - Function:  Wait_Option                         *
* Input Arguments:                                                  *
*                                                                   *
* Output Arguments:                                                 *
*- Integer value related with a option menu.                        *
* This function wait until the user enter a option.                 *
********************************************************************/
int Wait_Option (void)
{
    int Cursor_Pos = 14;

    system("cls");
    Show_Title ();

    gotoxy(30,10);
    cout << "SELECT A OPTION.";

    gotoxy(5,14);
    cout << "(1) NEW PRODUCT.";

    gotoxy(5,16);
    cout << "(2) DELETE PRODUCT.";

    gotoxy(5,18);
    cout << "(3) BUY PRODUCT.";

    gotoxy(5,20);
    cout << "(4) SALE PRODUCT.";

    gotoxy(5,22);
    cout << "(5) SHOW REPORT.";

    gotoxy(5,24);
    cout << "(6) SAVE REPORT.";

    gotoxy(5,26);
    cout << "(7) LOAD REPORT.";

    gotoxy(5,28);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), Color_Green);
    cout << "(8) EXIT." << endl;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), Color_Def);

    gotoxy(17,30);
    cout << "Use Key Pad To Select One Or Press ESC To EXIT. " << endl;

    gotoxy(3,Cursor_Pos);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), Color_Green);
    cout << (char)Cursor;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), Color_Def);
    gotoxy(64,30);

    do{
        if (kbhit())
        {
            KEY_PAD = getch();

            switch (KEY_PAD)
            {
                case KEY_UP:
                {
                    if (Cursor_Pos >= 16) Cursor_Pos = Cursor_Pos - 2;
                }
                break;

                case KEY_DOWN:
                {
                    if (Cursor_Pos <= 26) Cursor_Pos = Cursor_Pos + 2;
                }
                break;

                case KEY_ENTER:
                {
                    switch (Cursor_Pos)
                    {
                        case 14: return 1; break;
                        case 16: return 2; break;
                        case 18: return 3; break;
                        case 20: return 4; break;
                        case 22: return 5; break;
                        case 24: return 6; break;
                        case 26: return 7; break;
                        case 28: return 8; break;
                    }
                }
                break;

                case KEY_ESC: return 8; break;

            }

            for (int i = 0; i<16 ; i+=2)
            {
                gotoxy(3,14+i);
                cout << (char) 0;
            }

            gotoxy(3,Cursor_Pos);
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), Color_Green);
            cout << (char)Cursor;
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), Color_Def);
            gotoxy(64,30);
        }
    }while (KEY_PAD!=27);

    return 8;
}

/********************************************************************
* [LNG 2023-06-11] -  Function:  New_Product                        *
* Input Arguments:                                                  *
*                                                                   *
* Output Arguments:                                                 *
*- Integer value only for indicate that the function is over.       *
* This function adds products to the inventory.                     *
********************************************************************/
int New_Product (void)
{
    int Cursor_Pos = 13;
    char Name[Max_Chars];
    float Cost = 0, Price = 0;

    system("cls");
    Show_Title ();
    gotoxy(29,9);
    cout << ">> NEW PRODUCT <<" << endl;
    gotoxy(5,13);
    cout << "Name Product : " << endl;
    gotoxy(5,15);
    cout << "Cost Product : " << endl;
    gotoxy(4,17);
    cout << "Price Product : " << endl;
    gotoxy(6,19);
    cout << "<< SAVE >> " << endl;
    gotoxy(5,21);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), Color_Green);
    cout << " << RETURN MAIN" << endl;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), Color_Def);
    gotoxy(25,25);
    cout << "Use Key Pad To Select One Option." << endl;

    gotoxy(22,Cursor_Pos);

    do{
        if (kbhit())
        {
            KEY_PAD = getch();

            switch (KEY_PAD)
            {
                case KEY_UP:
                {
                    if (Cursor_Pos > 13) Cursor_Pos = Cursor_Pos - 2;
                }
                break;

                case KEY_DOWN:
                {
                    if (Cursor_Pos < 20) Cursor_Pos = Cursor_Pos + 2;
                }
                break;

                case KEY_ENTER:
                {
                    switch (Cursor_Pos)
                    {
                        case 13:
                            gotoxy(20,Cursor_Pos);
                            cout << (char)Cursor << "                    ";
                            gotoxy(20,Cursor_Pos);
                            cout << (char)Cursor << " ";
                            //cin.getline (Name,Max_Chars,'\n');

                            cin >> Name;
                            cin.clear();
                            cin.ignore(10, '\n');

                            for (int i=0; i<Max_Chars ; i++)
                            {
                                Name[i] = toupper(Name[i]);
                                if (Name[i] == 0) break;
                            }
                            gotoxy(35,Cursor_Pos);
                            cout << "Done";
                        break;

                        case 15:
                            gotoxy(20,Cursor_Pos);
                            cout << (char)Cursor << "                    ";
                            gotoxy(20,Cursor_Pos);
                            cout << (char)Cursor << " ";
                            cin >> Cost;
                            gotoxy(35,Cursor_Pos);
                            cout << "Done";
                        break;

                        case 17:
                            gotoxy(20,Cursor_Pos);
                            cout << (char)Cursor << "                    ";
                            gotoxy(20,Cursor_Pos);
                            cout << (char)Cursor << " ";
                            cin >> Price;
                            gotoxy(35,Cursor_Pos);
                            cout << "Done";
                        ; break;

                        case 19:
                            if (Cost == 0 || Price == 0 || Name[0] == 0)
                            {
                                Show_Error ((char *) "ERROR: YOU MUST ENTER ALL VALUES.  ", 1500);
                            }
                            else
                            {
                                Pointer_Articles[Counter_Articles] = new Article_Struct;
                                Init_Structure_Elements(Counter_Articles);
                                int Local_Articles = Get_Elements_Number();

                                for (int i=0; i<Max_Chars ; i++)
                                {
                                    Pointer_Articles[Local_Articles]->Name[i] = Name[i];
                                    if (Name[i] == 0) break;
                                }
                                Pointer_Articles[Local_Articles]->Cost = Cost;
                                Pointer_Articles[Local_Articles]->Price = Price;
                                Pointer_Articles[Local_Articles]->Pieces = 0;
                                Pointer_Articles[Local_Articles]->Value *= Cost;

                                if (Counter_Articles == Local_Articles) Counter_Articles++;

                                return 0;
                            }
                        break;

                        case 21: return 0 ; break;

                    }
                }
            }
            gotoxy(22,Cursor_Pos);
        }
      }while (KEY_PAD!=27);

      return 0;
}

/********************************************************************
*  [LNG 2023-06-11] Function:  Delete_Product                       *
* Input Arguments:                                                  *
*                                                                   *
* Output Arguments:                                                 *
*- Integer value only for indicate that the function is over.       *
* This function deletes produts to the inventory.                   *
********************************************************************/
int Delete_Product (void)
{
    int Cursor_Pos = 16;
    int Delete_Register = 0;

    system("cls");
    Show_Title ();
    gotoxy(29,9);
    cout << ">> DELETE PRODUCT <<" << endl;
    gotoxy(1,11);
    cout <<"------------------------------------------------------------------------------";
    gotoxy(1,12);
    cout << "|No.|";
    cout << "      NAME     |";
    cout << "     BUY     |";
    cout << "     SALE    |";
    cout << "  AVALIABLE  |";
    cout << "     PRICE    |";
    gotoxy(1,13);
    cout <<"------------------------------------------------------------------------------";
    gotoxy(1,9);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), Color_Green);
    cout << " << RETURN MAIN";
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), Color_Def);
    gotoxy(57,9);
    cout << "DELETE Reg. No:" ;

    for (int j = 0 ; j < Counter_Articles ; j++)
    {
        gotoxy(3,14+j);
        cout << j+1;
        gotoxy(10,14+j);
        for (int i = 0 ; i<Max_Chars ; i++)
        {
            cout << Pointer_Articles[j]->Name[i];
            if (Pointer_Articles[j]->Name[i] == 0)
            {
                break;
            }
        }
        cout.precision(2);
        gotoxy(26,14+j);
        cout << fixed << Pointer_Articles[j]->Cost;
        gotoxy(40,14+j);
        cout << fixed << Pointer_Articles[j]->Price;
        gotoxy(55,14+j);
        cout << fixed << Pointer_Articles[j]->Pieces;
        gotoxy(70,14+j);
        cout << fixed << Pointer_Articles[j]->Value;
    }

    gotoxy(Cursor_Pos,9);

    do{
        if (kbhit())
        {
            KEY_PAD = getch();

            switch (KEY_PAD)
            {
                case KEY_LEFT:
                {
                    if (Cursor_Pos == 74) Cursor_Pos = Cursor_Pos = 16;

                }
                break;

                case KEY_RIGHT:
                {
                    if (Cursor_Pos == 16) Cursor_Pos = Cursor_Pos = 74;
                }
                break;

                case KEY_ENTER:
                {
                    switch (Cursor_Pos)
                    {
                        case 74:
                            gotoxy(Cursor_Pos-1,9);
                            cout << (char)Cursor;
                            cin >> Delete_Register;
                            if (Delete_Register>Counter_Articles)
                            {
                                Show_Error ((char *) "ERROR: REGISTER NUMBER IS INVALID.", 1500);
                                Cursor_Pos = 16;
                            }
                            else
                            {
                                for (int i=0; i<Max_Chars ; i++)
                                {
                                    Pointer_Articles[Delete_Register-1]->Name[i] = 0;
                                }
                                Pointer_Articles[Delete_Register-1]->Cost = 0;
                                Pointer_Articles[Delete_Register-1]->Price = 0;
                                Pointer_Articles[Delete_Register-1]->Pieces = 0;
                                Pointer_Articles[Delete_Register-1]->Value = 0;
                                //delete[] Pointer_Articles[Delete_Register-1];
                                gotoxy(19,9);
                                cout << "DONE.";
                                Cursor_Pos = 16;
                            }
                        break;

                        case 16: return 0; break;
                    }
                }
            }
            gotoxy(Cursor_Pos,9);
        }
      }while (KEY_PAD!=27);

      return 0;
}


/********************************************************************
* [LNG 2023-06-11] - Function:  Buy_Product                         *
* Input Arguments:                                                  *
*                                                                   *
* Output Arguments:                                                 *
*- Integer value only for indicate that the function is over.       *
* This function manage the Inventory  Buys.                         *
********************************************************************/
int Buy_Product (void)
{
    int Cursor_Pos = 13;
    char Name[Max_Chars];
    int Quantity_Prod;
    bool Found_Article = false;

    system("cls");
    Show_Title ();
    gotoxy(29,9);
    cout << ">> BUY PRODUCT <<";
    gotoxy(5,13);
    cout << "Name Product :";
    gotoxy(4,15);
    cout << "Quantity Prod :";
    gotoxy(7,17);
    cout << "<< SAVE >> ";
    gotoxy(5,19);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), Color_Green);
    cout << " << RETURN MAIN" << endl;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), Color_Def);

    gotoxy(22,Cursor_Pos);

    do{
        if (kbhit())
        {
            KEY_PAD = getch();

            switch (KEY_PAD)
            {
                case KEY_UP:
                {
                    if (Cursor_Pos > 13) Cursor_Pos = Cursor_Pos - 2;
                }
                break;

                case KEY_DOWN:
                {
                    if (Cursor_Pos < 19) Cursor_Pos = Cursor_Pos + 2;
                }
                break;

                case KEY_ENTER:
                {
                    switch (Cursor_Pos)
                    {
                        case 13:
                            gotoxy(20,Cursor_Pos);
                            cout << (char)Cursor << "                    ";
                            gotoxy(20,Cursor_Pos);
                            cout << (char)Cursor << " ";
                            //cin.getline (Name,Max_Chars,'\n');

                            cin >> Name;
                            cin.clear();
                            cin.ignore(10, '\n');
                            gotoxy(35,Cursor_Pos);
                            cout << "Done";
                        break;

                        case 15:
                            gotoxy(20,Cursor_Pos);
                            cout << (char)Cursor << "                    ";
                            gotoxy(20,Cursor_Pos);
                            cout << (char)Cursor << " ";
                            cin >> Quantity_Prod;
                            cin.clear();
                            cin.ignore(10, '\n');
                            gotoxy(35,Cursor_Pos);
                            cout << "Done";
                        break;

                        case 17:
                            if (Quantity_Prod == 0 || Name[0] == 0)
                            {
                                Show_Error((char *) "ERROR: YOU MUST ENTER ALL VALUES.", 1500);
                            }
                            else
                            {
                                int j;
                                int i;
                                for (j = 0 ; j < Counter_Articles ; j++)
                                {
                                    for (i = 0 ; i<Max_Chars ; i++)
                                    {
                                        if (Pointer_Articles[j]->Name[i] != toupper(Name[i]) || Pointer_Articles[j]->Name[i] == 0)
                                        {
                                            break;
                                        }
                                    }

                                    if (i == strlen(Name))
                                    {
                                        Found_Article = true;
                                        break;
                                    }
                                }

                                if (Found_Article)
                                {
                                    Pointer_Articles[j]->Pieces += Quantity_Prod;
                                    Pointer_Articles[j]->Value = Pointer_Articles[j]->Cost * Pointer_Articles[j]->Pieces;
                                    return 0;
                                }
                                else
                                {
                                    Show_Error((char *) "ERROR: ARTICLE DIDN'T FOUNDED ON INVENTARY.", 1500);
                                }
                            }
                        break;

                        case 19: return 0; break;
                    }
                }
            }
            gotoxy(22,Cursor_Pos);
        }
      }while (KEY_PAD!=27);
}

/********************************************************************
* [LNG 2023-06-11] - Function:  Sale_Product                        *
* Input Arguments:                                                  *
*                                                                   *
* Output Arguments:                                                 *
*- Integer value only for indicate that the function is over.       *
* This function manage the Inventory Sales.                         *
********************************************************************/
int Sell_Product (void)
{
    int Cursor_Pos = 13;
    char Name[Max_Chars];
    int Quantity_Prod;
    bool Found_Article = false;

    system("cls");
    Show_Title ();
    gotoxy(29,9);
    cout << ">> SALE PRODUCT <<" << endl;
    gotoxy(5,13);
    cout << "Name Product :" << endl;
    gotoxy(4,15);
    cout << "Quantity Prod :" << endl;
    gotoxy(5,17);
    cout << "<< SAVE >> ";
    gotoxy(5,19);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), Color_Green);
    cout << " << RETURN MAIN" << endl;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), Color_Def);

    gotoxy(22,Cursor_Pos);

    do{
        if (kbhit())
        {
            KEY_PAD = getch();

            switch (KEY_PAD)
            {
                case KEY_UP:
                {
                    if (Cursor_Pos > 13) Cursor_Pos = Cursor_Pos - 2;

                }
                break;

                case KEY_DOWN:
                {
                    if (Cursor_Pos < 19) Cursor_Pos = Cursor_Pos + 2;
                }
                break;

                case KEY_ENTER:
                {
                    switch (Cursor_Pos)
                    {
                        case 13:
                            gotoxy(20,Cursor_Pos);
                            cout << (char)Cursor << "                    ";
                            gotoxy(20,Cursor_Pos);
                            cout << (char)Cursor << " ";
                            //cin.getline (Name,Max_Chars,'\n');

                            cin >> Name;
                            cin.clear();
                            cin.ignore(10, '\n');
                            gotoxy(35,Cursor_Pos);
                            cout << "Done";
                        break;

                        case 15:
                            gotoxy(20,Cursor_Pos);
                            cout << (char)Cursor << "                    ";
                            gotoxy(20,Cursor_Pos);
                            cout << (char)Cursor << " ";
                            cin >> Quantity_Prod;
                            cin.clear();
                            cin.ignore(10, '\n');
                            gotoxy(35,Cursor_Pos);
                            cout << "Done";
                        break;

                        case 17:
                            if (Quantity_Prod == 0 || Name[0] == 0)
                            {
                                Show_Error((char *) "ERROR: YOU MUST ENTER ALL VALUES.",1500);
                            }
                            else
                            {
                                int j;
                                int i;
                                for (j = 0 ; j < Counter_Articles ; j++)
                                {
                                    for (i = 0 ; i<Max_Chars ; i++)
                                    {
                                        if (Pointer_Articles[j]->Name[i] != toupper(Name[i]) || Pointer_Articles[j]->Name[i] == 0)
                                        {
                                            break;
                                        }
                                    }

                                    if (i == strlen(Name))
                                    {
                                        Found_Article = true;
                                        break;
                                    }
                                }

                                if (Found_Article)
                                {
                                    if (Quantity_Prod <= Pointer_Articles[j]->Pieces)
                                    {
                                        Pointer_Articles[j]->Pieces -= Quantity_Prod;
                                        Pointer_Articles[j]->Value = Pointer_Articles[j]->Cost * Pointer_Articles[j]->Pieces;
                                        return 0;
                                    }
                                    else
                                    {
                                        Show_Error((char *) "ERROR: ARTICLES QUANTITY IS TOO HIGH.",1500);
                                    }
                                }
                                else
                                {
                                    Show_Error((char *) "ERROR: ARTICLE DIDN'T FOUNDED ON INVENTARY.",1500);
                                }
                            }
                        break;

                        case 19: return 0; break;
                    }
                }
            }
            gotoxy(22,Cursor_Pos);
        }
      }while (KEY_PAD!=27);
}

/********************************************************************
* [LNG 2023-06-11] - Function:  Report_Product                      *
* Input Arguments:                                                  *
*                                                                   *
* Output Arguments:                                                 *
*- Integer value only for indicate that the function is over.       *
* This function show the Report Products.                           *
********************************************************************/
int Report_Product (void)
{
    float Total = 0;

    system("cls");
    Show_Title ();
    gotoxy(27,9);
    cout << ">> REPORT PRODUCTS <<" << endl;
    gotoxy(1,11);
    cout <<"------------------------------------------------------------------------------";
    gotoxy(1,12);
    cout << "|No.|";
    cout << "      NAME     |";
    cout << "     BUY     |";
    cout << "     SALE    |";
    cout << "  AVALIABLE  |";
    cout << "     PRICE    |";
    gotoxy(1,13);
    cout <<"------------------------------------------------------------------------------";
    gotoxy(1,9);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), Color_Green);
    cout << " << RETURN MAIN" << endl;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), Color_Def);

    int j;
    int i;

    for (j = 0 ; j < Counter_Articles ; j++)
    {
        gotoxy(3,14+j);
        cout << j+1;
        gotoxy(10,14+j);
        for (i = 0 ; i<Max_Chars ; i++)
        {
            cout << Pointer_Articles[j]->Name[i];
            if (Pointer_Articles[j]->Name[i] == 0)
            {
                break;
            }
        }
        cout << setprecision(2);
        gotoxy(26,14+j);
        cout << fixed << Pointer_Articles[j]->Cost;
        gotoxy(40,14+j);
        cout << fixed << Pointer_Articles[j]->Price;
        gotoxy(55,14+j);
        cout << fixed << Pointer_Articles[j]->Pieces;
        gotoxy(70,14+j);
        cout << fixed << Pointer_Articles[j]->Value;
    }

    gotoxy(1, 15+j);
    cout <<"------------------------------------------------------------------------------";
    gotoxy(57, 16+j);
    cout << "TOTAL : ";
    gotoxy(70, 16+j);

    for (int k = 0; k < Counter_Articles ; k++)
    {
        Total +=  Pointer_Articles[k]->Value;
    }
    cout << Total;

    gotoxy(46, 17+j);
    cout << "LAST REPORT GAIN : ";
    gotoxy(70, 17+j);
    cout << Total - Total_Inventary;

    gotoxy(16,9);

    do{
        if (kbhit())
        {
            KEY_PAD = getch();

            switch (KEY_PAD)
            {
                case KEY_ENTER:
                {
                    return 0;
                }
            }
            //gotoxy(22,Cursor_Pos);
        }
      }while (KEY_PAD!=27);
}


/********************************************************************
* [LNG 2023-06-11] Function:  Get_Elements_Number                   *
* Input Arguments:                                                  *
*                                                                   *
* Output Arguments:                                                 *
*- Integer Number of elements inside of array.                      *
* This function return the number of structure's elements.          *
********************************************************************/
int Get_Elements_Number (void)
{
    int Elements_Number = 0;

    for (int i = 0; i < 100 ; i++)
    {
        if (Pointer_Articles[i]->Name[i] == 0) break;
        Elements_Number++;
    }
    return Elements_Number;
}


/********************************************************************
*[LNG 2023-06-11]Function:  Init_Structure_Elements                 *
* Input Arguments:                                                  *
*- Integer Array Number Element.                                    *
* Output Arguments:                                                 *
*                                                                   *
* This function initialize the structure base.                      *
********************************************************************/
void Init_Structure_Elements (int Article)
{
    for (int i = 0 ; i<Max_Chars ; i++)
    {
        Pointer_Articles[Article]->Name[i] = NULL;
    }
    Pointer_Articles[Article]->Pieces = 0;
    Pointer_Articles[Article]->Cost = 0;
    Pointer_Articles[Article]->Price = 0;
    Pointer_Articles[Article]->Value = 0;
}


/********************************************************************
*[LNG 2023-06-11] -     Function:  Save_File                        *
* Input Arguments:                                                  *
*                                                                   *
* Output Arguments:                                                 *
*- Integer value only for indicate that the function is over.       *
* This function saves Inventory data in a File.                     *
********************************************************************/
int Save_File (void)
{
    int Cursor_Pos = 13;
    float Total = 0;

    system("cls");
    Show_Title ();
    gotoxy(27,9);
    cout << ">> SAVE REPORT <<" << endl;
    gotoxy(6,13);
    cout << "File Name :   " << File_Name <<endl;
    gotoxy(7,15);
    cout << "<< SAVE >>" << endl;
    gotoxy(4,17);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), Color_Green);
    cout << " << RETURN MAIN" << endl;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), Color_Def);

    gotoxy(20,Cursor_Pos);

    do{
        if (kbhit())
        {
            KEY_PAD = getch();

            switch (KEY_PAD)
            {
                case KEY_UP:
                {
                    if (Cursor_Pos > 13) Cursor_Pos = Cursor_Pos - 2;
                }
                break;

                case KEY_DOWN:
                {
                    if (Cursor_Pos < 17) Cursor_Pos = Cursor_Pos + 2;
                }
                break;

                case KEY_ENTER:
                {
                    switch (Cursor_Pos)
                    {
                        case 13:
                            gotoxy(18,Cursor_Pos);
                            cout << (char)Cursor << "                    ";
                            gotoxy(18,Cursor_Pos);
                            cout << (char)Cursor << " ";
                            //cin.getline (Name,Max_Chars,'\n');

                            cin >> File_Name;
                            cin.clear();
                            cin.ignore(10, '\n');
                            gotoxy(35,Cursor_Pos);
                            cout << "Done";

                            for (int i = 0 ; i<Max_Chars ; i++)
                            {
                                File_Name[i] = toupper(File_Name[i]);
                                if (File_Name[i] == 0) break;
                            }
                        break;

                        case 15:
                            if (File_Name[0] == 0)
                            {
                                Show_Error ((char *) "ERROR: ENTER A NAME FIRST.", 1500);
                            }
                            else
                            {
                                ofstream file (File_Name);
                                if (file.is_open())
                                {
                                    file << "                            >> REPORT PRODUCTS <<                               " << endl;
                                    file << " ------------------------------------------------------------------------------ " << endl;
                                    file << "|\tNo.\t|\tNAME\t|\tBUY\t|\tSALE\t|\tAVALIABLE\t|\tPRICE\t|" << endl;
                                    file << " ------------------------------------------------------------------------------ " << endl;
                                    file << endl;

                                    int j;
                                    int i;

                                    for (j = 0 ; j < Counter_Articles ; j++)
                                    {
                                        file << "#\t" << j+1 << "\t\t";
                                        for (i = 0 ; i<Max_Chars ; i++)
                                        {
                                            file << Pointer_Articles[j]->Name[i];
                                            if (Pointer_Articles[j]->Name[i] == 0)
                                            {
                                                break;
                                            }
                                        }
                                        file << setprecision(2);
                                        file << "\t\t" << fixed << Pointer_Articles[j]->Cost;
                                        file << "\t\t" << fixed << Pointer_Articles[j]->Price;
                                        file << "\t\t" << fixed << Pointer_Articles[j]->Pieces;
                                        file << "\t\t" << fixed << Pointer_Articles[j]->Value << endl;
                                    }

                                    file << endl;
                                    file <<"------------------------------------------------------------------------------" << endl;
                                    file << "\t\t\t\t\t\t\t\t\t\tTOTAL $ ";

                                    for (int k = 0; k < Counter_Articles ; k++)
                                    {
                                        Total +=  Pointer_Articles[k]->Value;
                                    }
                                    file << Total;

                                    file.close();
                                    gotoxy(25,25);
                                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), Color_Green);
                                    cout << "FILE CREATED SUCCESSFULLY.";
                                    Sleep (1500);
                                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), Color_Def);
                                    return 0;
                                }
                                else
                                {
                                    Show_Error ((char *) "ERROR: FILE WASN'T CREATED.", 1500);
                                    return 0;
                                }
                            }
                        break;

                        case 17:
                            return 0;
                        break;
                    }
                }
            }
            gotoxy(20,Cursor_Pos);
        }
      }while (KEY_PAD!=27);
      return 0;
}

/********************************************************************
* [LNG 2023-06-11] -    Function:  Load_File                        *
* Input Arguments:                                                  *
*                                                                   *
* Output Arguments:                                                 *
*- Integer value only for indicate that the function is over.       *
* This function loads Inventory data of a File.                     *
********************************************************************/
int Load_File (void)
{
    int Cursor_Pos = 13;
    char String_Row[50];

    char Name[Max_Chars];
    float Cost = 0, Price = 0;
    int Pieces;
    float Value;

    system("cls");
    Show_Title ();
    gotoxy(27,9);
    cout << ">> LOAD REPORT <<" << endl;
    gotoxy(6,13);
    cout << "File Name : " << endl;
    gotoxy(7,15);
    cout << "<< LOAD >>" << endl;
    gotoxy(4,17);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), Color_Green);
    cout << " << RETURN MAIN" << endl;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), Color_Def);

    gotoxy(20,Cursor_Pos);

    do{
        if (kbhit())
        {
            KEY_PAD = getch();

            switch (KEY_PAD)
            {
                case KEY_UP:
                {
                    if (Cursor_Pos > 13) Cursor_Pos = Cursor_Pos - 2;
                }
                break;

                case KEY_DOWN:
                {
                    if (Cursor_Pos < 17) Cursor_Pos = Cursor_Pos + 2;
                }
                break;

                case KEY_ENTER:
                {
                    switch (Cursor_Pos)
                    {
                        case 13:
                            gotoxy(18,Cursor_Pos);
                            cout << (char)Cursor << "                    ";
                            gotoxy(18,Cursor_Pos);
                            cout << (char)Cursor << " ";

                            cin >> File_Name;
                            cin.clear();
                            cin.ignore(10, '\n');
                            gotoxy(35,Cursor_Pos);
                            cout << "Done";

                            for (int i = 0 ; i<Max_Chars ; i++)
                            {
                                File_Name[i] = toupper(File_Name[i]);
                                if (File_Name[i] == 0) break;
                            }
                        break;

                        case 15:
                            if (File_Name[0] == 0)
                            {
                                Show_Error ((char *) "ERROR: ENTER A NAME FIRST.", 1500);
                            }
                            else
                            {
                                ifstream file (File_Name);
                                if (file.is_open())
                                {
                                    while(!file.eof())
                                    {
                                        file >> String_Row;

                                        if (String_Row[0] == '#')
                                        {
                                            file >> String_Row;
                                            file >> Name;
                                            file >> Cost;
                                            file >> Price;
                                            file >> Pieces;
                                            file >> Value;

                                            if (Name[0] != 0)
                                            {
                                                Pointer_Articles[Counter_Articles] = new Article_Struct;
                                                Init_Structure_Elements(Counter_Articles);

                                                for (int i = 0 ; i<Max_Chars ; i++)
                                                {
                                                    Pointer_Articles[Counter_Articles]->Name[i] = Name[i];
                                                    if (Name[i] == 0)
                                                    {
                                                        break;
                                                    }
                                                }
                                                Pointer_Articles[Counter_Articles]->Cost = Cost;
                                                Pointer_Articles[Counter_Articles]->Price = Price;
                                                Pointer_Articles[Counter_Articles]->Value = Value;
                                                Pointer_Articles[Counter_Articles]->Pieces = Pieces;

                                                Counter_Articles++;
                                            }
                                        }
                                        if (String_Row[0] == '$') file >> Total_Inventary;
                                    }

                                    if (Counter_Articles == 0)
                                    {
                                        Show_Error ((char *) "FILE DOESN'T HAVE INFORMATION TO LOAD.", 1500);
                                        file.close();
                                        return 0;
                                    }
                                    else
                                    {
                                        gotoxy(25,25);
                                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), Color_Green);
                                        cout << "FILE LOADED SUCCESSFULLY.";
                                        Sleep (1500);
                                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), Color_Def);
                                        file.close();
                                        return 0;
                                    }

                                }
                                else
                                {
                                    Show_Error ((char *) "ERROR: FILE WASN'T OPENED.", 1500);
                                    return 0;
                                }
                            }
                        break;

                        case 17:
                            return 0;
                        break;
                    }
                }
            }
            gotoxy(20,Cursor_Pos);
        }
      }while (KEY_PAD!=27);
      return 0;
}

/********************************************************************
* [LNG 2023-06-11] -  Function:  Show_Error                         *
* Input Arguments:                                                  *
*- Pointer to String, Integet Delay Time.                           *
* Output Arguments:                                                 *
*                                                                   *
* This function Shows A ERROR in Screem.                             *
********************************************************************/
void Show_Error (char *Pointer_String, int Show_Delay_us)
{
    int Strin_Leng = strlen (Pointer_String);
    gotoxy(23,25);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), Color_Red);
    for (int i = 0; i <= Strin_Leng ; i++)
    {
        cout << *(Pointer_String+i);
    }
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), Color_Def);
    Sleep(Show_Delay_us);
    gotoxy(23,25);
    for (int i = 0; i <= Strin_Leng ; i++)
    {
        cout << ' ';
    }
}


#endif // FUNCIONES_H_INCLUDED
