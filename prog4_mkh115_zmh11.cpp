/*
   File: prog4_mkh115_zmh11.cpp  
   Author: Mavrick Henderson, Zachary Hickey       
   C.S.1428.002            
   Lab Section: L17, L17        
   Program: #4
   Due Date: 10/30/19      
   This program prompts the user for the number of items purchased. If no
   items were purchased, the program terminates after printing an appropriate
   message to the screen; otherwise, the program repeatedly prompts the
   user for the price of the specified number of items and calculates the
   total of all purchased items. It then calculates the shipping charge,
   discounted total, tax on the discounted total, and the total amount due.
   After all calculations are performed, the program prints the author's
   identifying information followed by the total of all purchased items,
   the discounted total, the tax rate, the tax on the discounted total,
   shipping charges and the total amount due as shown below. Output is
   written in receipt form to both the console and to an output file.
   With the exception of the tax rate, the numeric data is formatted to
   two decimal places. The tax rate is formatted to four decimal places.
   Input (keyboard): number of items purchased, integer
                     item price, double
   Constants:        discount amount, double (sample: 0.20)
                     cut off amount for free shipping, double
                     shipping charge, double
                     tax rate, double (sample: 0.0825)
   Output (console):
          Sample Console Output (These samples do not reflect prompts.)
          Author's Name
          C.S.1428.?        // '?' represents three-digit lecture section number
          Lab Section: L?   // '?' represents two-digit lab section number
          --/--/--          // dashes represent due date, month/day/year
               <blank line>
          Total Purchases:    $ ??.??
          Discounted Total:     ??.??
          Tax Rate:              ?.????
          Tax:                   ?.??
          Shipping:              ?.??
               <blank line>
          Total Amount Due:   $ ??.??
               <blank line>
               <blank line>
          A copy for your records can be found in prog4_00?out.txt.
   Output (file - prog4_?out.txt):
          Author's Name
          C.S.1428.?        // '?' represents three-digit lecture section number
          Lab Section: L?   // '?' represents two-digit lab section number
          --/--/--          // dashes represent due date, month/day/year
               <blank line>
          Total Purchases:    $ ??.??
          Discounted Total:     ??.??
          Tax Rate:              ?.????
          Tax:                   ?.??
          Shipping:              ?.??
               <blank line>
          Total Amount Due:   $ ??.??
          ================================================
          <Output will vary based on actual input values.>
*/

#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

int main()
{
    const double DISCOUNT = .2,
                 CUT_OFF = 150,
                 SHIPPING_CHARGE = 8.50,
                 TAX_RATE = .0825;
    double discount_total,
           total,
           shipping,
           tax,
           amount_owed,
           item_price;
    int items_purchased;

    cout << "Enter the number of items purchased: ";
    cin >> items_purchased;
    cout << endl;

    if (items_purchased == 0)
        cout << "Come back again soon!";
    else 
        {
        for (int i = 0; i < items_purchased; i++)
            {
                cout << "Enter the item price: ";
                cin >> item_price;
                total += item_price;
            }

            discount_total = total - (total * DISCOUNT);

            if (discount_total >= CUT_OFF)
                shipping = 0;
            else 
                shipping = SHIPPING_CHARGE;

            tax = discount_total * TAX_RATE;
            
            amount_owed = discount_total + shipping + tax;

            ofstream fout;
            fout.open("prog4_mkh115_zmh11_out.txt");
            if ( !fout )
                {
                    cout << endl << endl
                    << " ***Program Terminated.*** " << endl << endl
                    << "Output file failed to open." << endl;

                     return 2;
                }
            
            fout << "Mavrick Henderson, Zachary Hickey" << endl 
                 << "C.S.1428.002" << endl 
                 << "Lab Section: L17, L17" << endl 
                 << "10/30/19" << endl << endl 

                << fixed << setprecision(2)
                 << "Total Purchases:    $ " << setw(6) << total << endl
                 << "Discounted Total:     " << setw(6) << discount_total << endl
                 << setprecision(4) 
                 << "Tax Rate:             " << setw(8) << TAX_RATE << endl
                 << setprecision(2) 
                 << "Tax:                  " << setw(6) << tax << endl
                 << "Shipping:             " << setw(6) << shipping << endl << endl

                 <<"Total Amount Due:    $ " << setw(6) << amount_owed << endl;

                 fout.close();
            
            cout << endl << endl
                 << "Mavrick Henderson, Zachary Hickey" << endl 
                 << "C.S.1428.002" << endl 
                 << "Lab Section: L17, L17" << endl 
                 << "10/30/19" << endl << endl 

                << fixed << setprecision(2)
                 << "Total Purchases:    $ " << setw(6) << total << endl
                 << "Discounted Total:     " << setw(6) << discount_total << endl
                 << setprecision(4) 
                 << "Tax Rate:             " << setw(8) << TAX_RATE << endl
                 << setprecision(2) 
                 << "Tax:                  " << setw(6) << tax << endl
                 << "Shipping:             " << setw(6) << shipping << endl << endl

                 << "Total Amount Due:    $ " << setw(6) << amount_owed << endl << endl 
                 << "A copy for your records can be found in prog4_mkh115_zmh11_out.txt" << endl;
            
        }

    system("PAUSE>NUL");

    return 0;
}
