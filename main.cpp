#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int main()
{  
   //user input variables
   string usrInputStr;
   double usrInputDouble;

   //recipe name, variables for all nutrient totals
   string recipeName;
   double totalPro = 0.0, totalCarb = 0.0, totalSod = 0.0,
      totalFib = 0.0, totalFat = 0.0, totalChol = 0.0;

   //Food 1 Constants Per-Gram
   const string FOOD_1 = "Uncured Pork Bacon";
   const double FOOD_1_PRO = 0.074;       //grams per gram
   const double FOOD_1_SOD = 3.57;        //milligrams per gram
   const double FOOD_1_FAT = 0.1;         //grams per gram
   const double FOOD_1_CHOL = 0.22;       //milligrams per gram

   //Food 1 constants Per-Strip
   const double FOOD_1_PRO_PP = 5.0;      //grams per strip
   const double FOOD_1_SOD_PP = 240.0;    //milligrams per strip
   const double FOOD_1_FAT_PP = 7.0;      //grams per strip
   const double FOOD_1_CHOL_PP = 15.0;    //milligrams per strip

   //Food 2 Constants
   const string FOOD_2 = "Extra-Large Eggs";
   const double FOOD_2_PRO = 0.11;        //grams per gram
   const double FOOD_2_SOD = 1.23;        //milligrams per gram
   const double FOOD_2_FAT = 0.077;       //grams per gram
   const double FOOD_2_CHOL = 3.23;       //milligrams per gram

   //Food 2 Constants Per-Egg
   const double FOOD_2_PRO_PP = 7.0;      //grams per egg
   const double FOOD_2_SOD_PP = 80.0;     //milligrams per egg
   const double FOOD_2_FAT_PP = 5.0;      //grams per egg
   const double FOOD_2_CHOL_PP = 210.0;   //milligrams per egg

   //Food 3 Constants
   const string FOOD_3 = "Chicken Sausage";
   const double FOOD_3_PRO = 0.13;        //grams per gram
   const double FOOD_3_CARB = 0.083;      //grams per gram
   const double FOOD_3_SOD = 10.35;       //milligrams per gram
   const double FOOD_3_FAT = 0.14;        //grams per gram
   const double FOOD_3_CHOL = 1.2;        //milligrams per gram

   //Food 3 Constants Per-Link
   const double FOOD_3_PRO_PP = 11.0;     //grams per link
   const double FOOD_3_CARB_PP = 3.0;     //grams per link
   const double FOOD_3_SOD_PP = 400.0;    //milligrams per link
   const double FOOD_3_FAT_PP = 6.0;      //grams per link
   const double FOOD_3_CHOL_PP = 50.0;    //milligrams per link

   //Food 4 Constants
   const string FOOD_4 = "Raw Jalapenos";
   const double FOOD_4_PRO = 0.01;        //grams per gram
   const double FOOD_4_CARB = 0.067;      //grams per gram
   const double FOOD_4_SOD = 0.01;        //milligrams per gram
   const double FOOD_4_FIB = 0.03;        //grams per gram
   const double FOOD_4_FAT = 0.01;        //grams per gram
   const double FOOD_4_CHOL = 1.2;        //milligrams per gram

   //Food 4 Constants Per-Pepper
   const double FOOD_4_CARB_PP = 1.0;     //grams per pepper

   //Food 5 Constants
   const string FOOD_5 = "Raw Onions";
   const double FOOD_5_PRO = 0.0125;      //grams per gram
   const double FOOD_5_CARB = 0.094;      //grams per gram
   const double FOOD_5_SOD = 0.038;       //milligrams per gram
   const double FOOD_5_FIB = 0.019;       //grams per gram

   //Food 5 Constants Per-Onion
   const double FOOD_5_PRO_PP = 1.0;      //grams per onion
   const double FOOD_5_CARB_PP = 16.0;    //grams per onion
   const double FOOD_5_SOD_PP = 5.0;      //milligrams per onion
   const double FOOD_5_FIB_PP = 2.0;      //grams per onion

   //Food 6 Constants
   const string FOOD_6 = "Lite Mozzarella Cheese";
   const double FOOD_6_PRO = 0.18;        //grams per gram
   const double FOOD_6_SOD = 6.79;        //milligrams per gram
   const double FOOD_6_FAT = 0.11;        //grams per gram
   const double FOOD_6_CHOL = 0.36;       //milligrams per gram

   //Food 6 Constants Per-CUP
   const double FOOD_6_PRO_PP = 0.18;     //grams per cup
   const double FOOD_6_SOD_PP = 6.79;     //milligrams per cup
   const double FOOD_6_FAT_PP = 0.11;     //grams per cup
   const double FOOD_6_CHOL_PP = 0.36;    //milligrams per cup

   const string INDENT = "   ";

   // print list of ingredients
   cout << "---------- List of Possible Ingredients ---------" << endl;
   cout << INDENT << "Ingredient # 1: " << FOOD_1 << endl;
   cout << INDENT << "Ingredient # 2: " << FOOD_2 << endl;
   cout << INDENT << "Ingredient # 3: " << FOOD_3 << endl;
   cout << INDENT << "Ingredient # 4: " << FOOD_4 << endl;
   cout << INDENT << "Ingredient # 5: " << FOOD_5 << endl;
   cout << INDENT << "Ingredient # 6: " << FOOD_6 << endl << endl;    

   /*Get and store recipe name. There is no error checking for this since
   we don't really care what the end user wants to call their creation.*/
   cout << "What are you calling this recipe? ";
   getline(cin, recipeName);

   //get units for FOOD_1
   cout << "\nFor " << FOOD_1 << ", will your answer be stated"
      " in Grams, or Strips? ";
   cin >> usrInputStr;

   //error-check user input
   if (usrInputStr[0] != 'g' && usrInputStr[0] != 'G' 
      && usrInputStr[0] != 's' && usrInputStr[0] != 'S')
   {
      cout << "\n\nError: Amounts for this ingredient may"
         " only be stated in Grams or Strips.\n" << endl;
      return 1;
   }

   //get amount for FOOD_1
   usrInputDouble = -1.0;
   cout << "\nHow many " << usrInputStr << " will be used? ";
   cin >> usrInputDouble;

   //error-check user input
   if (usrInputDouble < 0)
   {
      cout << "\n\nError: Amounts must be stated"
         " as positive numbers (decimals are ok).\n" << endl;
      return 1;
   }

   //update nutrient totals with FOOD_1 info
   if (usrInputStr[0] == 'g' || usrInputStr[0] == 'G')
   {
      totalPro += (usrInputDouble * FOOD_1_PRO);
      totalSod += (usrInputDouble * FOOD_1_SOD);
      totalFat += (usrInputDouble * FOOD_1_FAT);
      totalChol += (usrInputDouble * FOOD_1_CHOL);
   }
   else if (usrInputStr[0] == 's' || usrInputStr[0] == 'S')
   {
      totalPro += (usrInputDouble * FOOD_1_PRO_PP);
      totalSod += (usrInputDouble * FOOD_1_SOD_PP);
      totalFat += (usrInputDouble * FOOD_1_FAT_PP);
      totalChol += (usrInputDouble * FOOD_1_CHOL_PP);
   }

   //get units for FOOD_2
   cout << "\nFor " << FOOD_2 << ", will your answer be"
      " stated in Grams, or Eggs? ";
   cin >> usrInputStr;

   //error-check user input
   if (usrInputStr[0] != 'g' && usrInputStr[0] != 'G' 
      && usrInputStr[0] != 'e' && usrInputStr[0] != 'E')
   {
      cout << "\n\nError: Amounts for this ingredient may"
         " only be stated in Grams or Eggs.\n" << endl;
      return 1;
   }

   //get amount for FOOD_2
   usrInputDouble = -1.0;
   cout << "\nHow many " << usrInputStr << " will be used? ";
   cin >> usrInputDouble;

   //error-check user input
   if (usrInputDouble < 0)
   {
      cout << "\n\nError: Amounts must be stated"
         " as positive numbers (decimals are ok).\n" << endl;
      return 1;
   }

   //update nutrient totals with FOOD_2 info
   if (usrInputStr[0] == 'g' || usrInputStr[0] == 'G')
   {
      totalPro += (usrInputDouble * FOOD_2_PRO);
      totalSod += (usrInputDouble * FOOD_2_SOD);
      totalFat += (usrInputDouble * FOOD_2_FAT);
      totalChol += (usrInputDouble * FOOD_2_CHOL);
   }
   else if (usrInputStr[0] == 'e' || usrInputStr[0] == 'E')
   {
      totalPro += (usrInputDouble * FOOD_2_PRO_PP);
      totalSod += (usrInputDouble * FOOD_2_SOD_PP);
      totalFat += (usrInputDouble * FOOD_2_FAT_PP);
      totalChol += (usrInputDouble * FOOD_2_CHOL_PP);
   }

   //get units for FOOD_3
   cout << "\nFor " << FOOD_3 << ", will your answer be"
      " stated in Grams, or Links? ";
   cin >> usrInputStr;

   //error-check user input
   if (usrInputStr[0] != 'g' && usrInputStr[0] != 'G' 
      && usrInputStr[0] != 'l' && usrInputStr[0] != 'L')
   {
      cout << "\n\nError: Amounts for this ingredient"
         " may only be stated in Grams or Links.\n" << endl;
      return 1;
   }

   //get amount for FOOD_3
   usrInputDouble = -1.0;
   cout << "\nHow many " << usrInputStr << " will be used? ";
   cin >> usrInputDouble;

   //error-check user input
   if (usrInputDouble < 0)
   {
      cout << "\n\nError: Amounts must be stated"
         " as positive numbers (decimals are ok).\n" << endl;
      return 1;
   }

   //update nutrient totals with FOOD_3 info
   if (usrInputStr[0] == 'g' || usrInputStr[0] == 'G')
   {
      totalPro += (usrInputDouble * FOOD_3_PRO);
      totalSod += (usrInputDouble * FOOD_3_SOD);
      totalFat += (usrInputDouble * FOOD_3_FAT);
      totalChol += (usrInputDouble * FOOD_3_CHOL);
      totalCarb += (usrInputDouble * FOOD_3_CARB);
   }
   else if (usrInputStr[0] == 'l' || usrInputStr[0] == 'L')
   {
      totalPro += (usrInputDouble * FOOD_3_PRO_PP);
      totalSod += (usrInputDouble * FOOD_3_SOD_PP);
      totalFat += (usrInputDouble * FOOD_3_FAT_PP);
      totalChol += (usrInputDouble * FOOD_3_CHOL_PP);
      totalCarb += (usrInputDouble * FOOD_3_CARB_PP);
   }

   //get units for FOOD_4
   cout << "\nFor " << FOOD_4 << ", will your answer be"
      " stated in Grams, or Peppers? ";
   cin >> usrInputStr;

   //error-check user input
   if (usrInputStr[0] != 'g' && usrInputStr[0] != 'G' 
      && usrInputStr[0] != 'p' && usrInputStr[0] != 'P')
   {
      cout << "\n\nError: Amounts for this ingredient"
         " may only be stated in Grams or Peppers.\n" << endl;
      return 1;
   }

   //get amount for FOOD_4
   usrInputDouble = -1.0;
   cout << "\nHow many " << usrInputStr << " will be used? ";
   cin >> usrInputDouble;

   //error-check user input
   if (usrInputDouble < 0)
   {
      cout << "\n\nError: Amounts must be stated"
         " as positive numbers (decimals are ok).\n" << endl;
      return 1;
   }

   //update nutrient totals with FOOD_4 info
   if (usrInputStr[0] == 'g' || usrInputStr[0] == 'G')
   {
      totalPro += (usrInputDouble * FOOD_4_PRO);
      totalSod += (usrInputDouble * FOOD_4_SOD);
      totalFat += (usrInputDouble * FOOD_4_FAT);
      totalChol += (usrInputDouble * FOOD_4_CHOL);
      totalCarb += (usrInputDouble * FOOD_4_CARB);
      totalFib += (usrInputDouble * FOOD_4_FIB);
   }
   else if (usrInputStr[0] == 'p' || usrInputStr[0] == 'P')
   {
      totalCarb += (usrInputDouble * FOOD_4_CARB_PP);
   }

   //get units for FOOD_5
   cout << "\nFor " << FOOD_5 << ", will your answer be"
      " stated in Grams, or Onions? ";
   cin >> usrInputStr;

   //error-check user input
   if (usrInputStr[0] != 'g' && usrInputStr[0] != 'G' 
      && usrInputStr[0] != 'o' && usrInputStr[0] != 'O')
   {
      cout << "\n\nError: Amounts for this ingredient"
         " may only be stated in Grams or Onions.\n" << endl;
      return 1;
   }

   //get amount for FOOD_5
   usrInputDouble = -1.0;
   cout << "\nHow many " << usrInputStr << " will be used? ";
   cin >> usrInputDouble;

   //error-check user input
   if (usrInputDouble < 0)
   {
      cout << "\n\nError: Amounts must be stated"
         " as positive numbers (decimals are ok).\n" << endl;
      return 1;
   }

   //update nutrient totals with FOOD_5 info
   if (usrInputStr[0] == 'g' || usrInputStr[0] == 'G')
   {
      totalPro += (usrInputDouble * FOOD_5_PRO);
      totalSod += (usrInputDouble * FOOD_5_SOD);
      totalCarb += (usrInputDouble * FOOD_5_CARB);
      totalFib += (usrInputDouble * FOOD_5_FIB);
   }
   else if (usrInputStr[0] == 'o' || usrInputStr[0] == 'O')
   {
      totalPro += (usrInputDouble * FOOD_5_PRO_PP);
      totalSod += (usrInputDouble * FOOD_5_SOD_PP);
      totalCarb += (usrInputDouble * FOOD_5_CARB_PP);
      totalFib += (usrInputDouble * FOOD_5_FIB_PP);
   }

   //get units for FOOD_6
   cout << "\nFor " << FOOD_6 << ", will your answer be"
      " stated in Grams, or Cups? ";
   cin >> usrInputStr;

   //error-check user input
   if (usrInputStr[0] != 'g' && usrInputStr[0] != 'G' 
      && usrInputStr[0] != 'c' && usrInputStr[0] != 'C')
   {
      cout << "\n\nError: Amounts for this ingredient"
         " may only be stated in Grams or Cups.\n" << endl;
      return 1;
   }

   //get amount for FOOD_6
   usrInputDouble = -1.0;
   cout << "\nHow many " << usrInputStr << " will be used? ";
   cin >> usrInputDouble;

   //error-check user input
   if (usrInputDouble < 0)
   {
      cout << "\n\nError: Amounts must be stated"
         " as positive numbers (decimals are ok).\n" << endl;
      return 1;
   }

   //update nutrient totals with FOOD_6 info
   if (usrInputStr[0] == 'g' || usrInputStr[0] == 'G')
   {
      totalPro += (usrInputDouble * FOOD_6_PRO);
      totalSod += (usrInputDouble * FOOD_6_SOD);
      totalFat += (usrInputDouble * FOOD_6_FAT);
      totalChol += (usrInputDouble * FOOD_6_CHOL);
   }
   else if (usrInputStr[0] == 'c' || usrInputStr[0] == 'C')
   {
      totalPro += (usrInputDouble * FOOD_6_PRO_PP);
      totalSod += (usrInputDouble * FOOD_6_SOD_PP);
      totalFat += (usrInputDouble * FOOD_6_FAT_PP);
      totalChol += (usrInputDouble * FOOD_6_CHOL_PP);
   }

   //final output for recipe
   cout << "\n\nNutrient Totals for " << recipeName << " are:" << endl;
   cout << INDENT << "Protein:     " << totalPro << " grams." << endl;
   cout << INDENT << "Sodium:      " << totalSod << " milligrams." <<endl;
   cout << INDENT << "Fat:         " << totalFat << " grams." <<endl;
   cout << INDENT << "Cholesterol: " 
      << totalChol << " milligrams." <<endl;
   cout << INDENT << "Fiber:       " << totalFib << " grams." << endl;
   cout << INDENT << "Sodium:      " << totalSod << " milligrams.\n" << endl;

   //make sure final output stays up and doesn't vanish
   { cout << flush; getchar(); }

   return 0;
}