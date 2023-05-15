
#include <iostream>
#include <fstream>		 // for file handling
#include <iomanip>		 //setprecision
#include <cstring>	 
#include <string>
#include <stdlib.h>		//for system("cls)
#include <stdexcept>		//error handling
#include <limits>

using namespace std;

struct Sales_Computation {
	char Variation[20];
	int PricePerUnit;
	int ProductNumber;
	int QuantitySold;
	float SubTotal;
	float DiscountRate;
	float TaxRate;
	float TotalDue;

	Sales_Computation() { 	//Constructor - use to initialize the member of strucuture
		Variation[20];
		ProductNumber = 0;
		PricePerUnit = 0;
		QuantitySold = 0;
		SubTotal = 0.0;
		DiscountRate = 0.20;
		TaxRate = 0.07;
		TotalDue = 0.0;
	}
};

float computeOrderPrice(Sales_Computation& product);	//return the subtotal of each order.

float applyDiscounts(Sales_Computation& product, float& _subTotal);	//return the 20% discount amount if the user is a senior citizen.

float applyTax(Sales_Computation& product, float& Subtotal, float& discount);	//return the 7% of subtotal amount as Tax

float computeTotalSales(Sales_Computation& product, float& subtotal, float& Discount, float& Tax);	  //return the total amount of all orders

void writeToFile(fstream& salesFile, Sales_Computation product[], const int arrSize, float _subTotal, float _seniorDiscount, float _ValueAddedTax, float _totalDue, float _customerCash, float _customerChange);


int main()
{
	char choice = ' ', response = ' ';
	float seniorDiscount = 0.0, ValueAddedTax = 0.0, totalDue = 0.0, subTotal = 0.0, customerCash = 0.0, customerChange = 0.0;
    int numOfOrder = 0;
	fstream salesFile;
	Sales_Computation product[50];

	do {
		cout << " =======================" << endl;
		cout << "    Sales Computation" << endl;
		cout << " =======================" << endl;
		cout << "  [A] Product List " << endl;
		cout << "  [B] Order List" << endl;
		cout << "  [C] Sales Receipt" << endl;
		cout << "  [D] Exit" << endl;
		cout << " =======================" << endl;
		cout << " Select: ";
		cin >> choice;

		switch (choice) {
		case 'A':
		case 'a':
			system("cls");
			cout << "\t\t\t\t----------------------------------------------" << endl;
			cout << "	 	       \t\t\t\tProduct List" << endl;
			cout << "\t\t\t\t----------------------------------------------" << endl;
			cout << "||=================================================" << "||" << "================================================||" << endl;
			cout << "||=>=>=>=>=>=>=>=>| COLD DRINKS |<=<=<=<=<=<=<=<=<=" << "||" << "=>=>=>=>=>=>=>=>=>| HOT DRINKS |<=<=<=<=<=<=<=<=||" << endl;
			cout << "||=================================================" << "||" << "================================================||" << endl;
			cout << "||		 ***PRICE: PHP 100.00***\t" << "   ||" << "		   ***PRICE: PHP 120.00*** \t     ||" << endl;
			cout << "|| [100] Dark Chocolate" << "\t  [106] Okinawa" << "\t           ||" << " [120] French Press Coffee " << " [126] Matcha Latte  ||" << endl;
			cout << "|| [101] Winter Melon" << "\t  [107] Pudding" << "\t           ||" << " [121] Vanilla Chai Latte  " << " [127] Cappuccino    ||" << endl;
			cout << "|| [102] Oreo Choko" << "\t  [108] Mocha" << "\t           ||" << " [122] Hot Buttered Rum   " << "  [128] Mulled cider  ||" << endl;
			cout << "|| [103] Green Tea" << "\t  [109] Mango" << "\t           ||" << " [123] Spanish Coffee     " << "  [129] Ginger Tea    ||" << endl;
			cout << "|| [104] Blueberry" << "\t  [110] Taro" << "\t           ||" << " [124] Classic Mocha" << "\t [130] Macchiato     ||" << endl;
			cout << "|| [105] Caramell" << "\t\t\t           ||" << " [125] Hot Chocolate \t\t\t     ||" << endl;
			cout << "||=================================================" << "||" << "================================================||" << endl;
			cout << "||=>=>=>=>=>=>=>| VEGETABLE DISH |<=<=<=<=<=<=<=<=<" << "||" << ">=>=>=>=>=>=>=>=>| MEAT DISH |<=<=<=<=<=<=<=<=<=||" << endl;
			cout << "||=================================================" << "||" << "================================================||" << endl;
			cout << "||		***PRICE: PHP 150.00***\t\t" << "   ||" << "\t\t  ***PRICE: PHP 170.00***\t     ||" << endl;
			cout << "|| [220] Togue" << "\t\t  [226] Laing\t\t   " << "||" << " [240] Sisig " << "\t[246] Bulalo\t\t     ||" << endl;
			cout << "|| [221] Ampalaya" << "\t  [227] Munggo\t\t   " << "||" << " [241] Chicken" << "\t[247] Crispy pata\t     ||" << endl;
			cout << "|| [222] Pinakbet" << "\t  [228] Ginataang Pinakbet " << "||" << " [242] Adobo " << "\t[248] Bicol express\t     ||" << endl;
			cout << "|| [223] Ginataang Sitaw" << "  [229] Ginataang Sayote   " << "||" << " [243] Pork Belly " << "\t[249] Lumpia\t\t     ||" << endl;
			cout << "|| [224] Ginisang Pechay" << "  [230] Lumpiang Sariwa" << "\t   ||" << " [244] Lechon" << "\t[250] Sinigang\t\t     ||" << endl;
			cout << "|| [225] Chopsuey" << "\t\t\t\t   ||" << " [245] Kare-kare \t\t\t\t     ||" << endl;
			cout << "||=================================================" << "||" << "================================================||" << endl;
			cout << "\tReminder: System can only accept a maximum of 50 orders & quantity per product." << endl << endl;

			try {
				while (true) {
					cout << "  Enter Number of Order: ";				// getting user input
					cin >> numOfOrder;
					if (numOfOrder >= 1 && numOfOrder <= 50) {			// If input is valid, break out of the loop					
						break;
					}
					else {					 			// If input is invalid, prompt the user input again
						cout << "Error: Only Number between \"1-50\" is accepted!" << endl << endl;
					}
				}

				cout << "\t\t\tNotice: The system can only accept a total of " << numOfOrder << " orders." << endl;
			
				for (int i = 0; i < numOfOrder; i++) {
					cin.ignore();
					cout << "\n  Enter Product Variation: ";			// getting user input
					cin.getline(product[i].Variation, 20);

					cout << "  Enter Product Price    : ";				// getting user input
					cin >> product[i].PricePerUnit;
					if ((cin.fail()) || (product[i].PricePerUnit != 100) && (product[i].PricePerUnit != 120) && (product[i].PricePerUnit != 150) && (product[i].PricePerUnit != 170)) {	//check if price is invalid
						cin.clear();		 										// clear/remove any error set in cin
						cin.ignore(numeric_limits<streamsize>::max(), '\n');							// ignore any remaining input
						throw invalid_argument("Invalid Price!");								// throw an error message to the user
					}
					cout << "  Enter Product Number   : ";										// getting user input
					cin >> product[i].ProductNumber;
					if ((cin.fail()) || (product[i].ProductNumber < 100 || product[i].ProductNumber > 110) && (product[i].ProductNumber < 120 || product[i].ProductNumber > 130) &&
						(product[i].ProductNumber < 220 || product[i].ProductNumber > 230) && (product[i].ProductNumber < 240 || product[i].ProductNumber > 250)) {			//check if Product Number is invalid
						cin.clear();												// clear/remove any error set in cin
						cin.ignore(numeric_limits<streamsize>::max(), '\n');							// ignore any remaining input
						throw invalid_argument("Invalid Product Number!");							// throw an error message to the user
					}
					cout << "  Enter Order Quantity   : ";										// getting user input
					cin >> product[i].QuantitySold;
					if (cin.fail() || (product[i].QuantitySold < 1 || product[i].QuantitySold > 50)) {	// check if Quantity is invalid
						cin.clear();												// clear/remove any error set in cin
						cin.ignore(numeric_limits<streamsize>::max(), '\n');							// ignore any remaining input
						throw invalid_argument("Invalid Order Quantity!");							// throw an error message to the user
					}
					subTotal += computeOrderPrice(product[i]);									// adding all the order subtotal
				}

				cout << "  Are you a Senior Citizen(Y/N)? ";
				cin >> response;
				if (response == 'Y' || response == 'y') {
					for (int i = 0; i < numOfOrder; i++) {
						seniorDiscount = applyDiscounts(product[i], subTotal);					 // applying discount to the computed subtotal

						ValueAddedTax = applyTax(product[i], subTotal, seniorDiscount);				// applying Tax 
						totalDue = computeTotalSales(product[i], subTotal, seniorDiscount, ValueAddedTax);	// compute all the total amount of order
					}
				}
				else if (response == 'N' || response == 'n') {
					for (int i = 0; i < numOfOrder; i++) {
						subTotal += computeOrderPrice(product[i]);	

						ValueAddedTax = applyTax(product[i], subTotal, seniorDiscount);				// applying Tax 
						totalDue = computeTotalSales(product[i], subTotal, seniorDiscount, ValueAddedTax);	// compute all the total amount of order
					}
				}
				else {
					throw invalid_argument("Invalid response!");	// throw an error message to the user
				}

				cout << " ------------------------------------------" << endl;
				cout << "  TOTAL Due                   : " << fixed << setprecision(2) << totalDue << endl;	// show the Total due to the user														
				while (true) {
					cout << "  Enter cash for order payment: ";					// ask the user to enter cash for payment
					cin >> customerCash;
					if (customerCash >= totalDue) {							// If input is valid, break out of the loop
						customerChange = customerCash - totalDue;				// getting the sukli ^_^			
						cout << "Notice: Succesfully paid!" << endl << endl;
						break;
					}
					else {										
						cout << "Error: Not enough cash to pay the bill. Please enter a sufficient amount!" << endl << endl;
					}
				}
			}

			// handle all the exception that throw by the system
			catch (const invalid_argument& exception) {
				cerr << "  Error: " << exception.what() << endl;
			}
			cout << endl;

			// write to File
			writeToFile(salesFile, product, numOfOrder, subTotal, seniorDiscount, ValueAddedTax, totalDue, customerCash, customerChange);
			break;

		case'B':
		case'b':
			system("cls");
			// print out all the data that store in array of structure
			cout << "----------------------------------------------" << endl;
			cout << "	 	  Order List" << endl;
			cout << "----------------------------------------------" << endl;
			for (int i = 0; i < numOfOrder; i++) {
				cout << " Product Variation: " << product[i].Variation << endl;
				cout << " Product Price    : " << product[i].PricePerUnit << ".00" << endl;
				cout << " Product Number   : " << product[i].ProductNumber << endl;
				cout << " Quantity Sold    : " << product[i].QuantitySold << endl << endl;
			}
			cout << "----------------------------------------------" << endl;
			cout << " SubTotal         : " << fixed << setprecision(2) << subTotal << endl;
			cout << " Discout(20%)     : " << fixed << setprecision(2) << seniorDiscount << endl;
			cout << " VAT(7%)          : " << fixed << setprecision(2) << ValueAddedTax << endl;
			cout << " TOTAL Due        : " << fixed << setprecision(2) << totalDue << endl;
			cout << "----------------------------------------------" << endl;
			cout << " Cash             : " << fixed << setprecision(2) << customerCash << endl;
			cout << " Change           : " << fixed << setprecision(2) << customerChange << endl << endl;
			break;

		case'C':
		case'c':
			system("cls");
			// read from file
			salesFile.open("SalesInfo.txt", ios::in);
			string fileText;
			if (salesFile.is_open()) {
				while (getline(salesFile, fileText)) {
					cout << fileText << endl;
				}
				salesFile.close();
			}
			else {
				cout << " Error: Unable to open File!" << endl;
			}
			break;

		}
	} while (choice != 'D' && choice != 'd');


	system("pause > 0");
	return 0;
}

float computeOrderPrice(Sales_Computation& product) {
	const int priceOf_100to110 = 100;  // cold drinks = 100 pesos
	const int priceOf_120to130 = 120;  // hot drinks = 120 pesos
	const int priceOf_220to230 = 150;  // vegetables = 150 pesos
	const int priceOf_240to250 = 170;  // meats = 170 pesos

	if ((product.PricePerUnit == priceOf_100to110) && (product.ProductNumber >= 100 && product.ProductNumber <= 110)) {			// cold drinks = 100 pesos
		return product.SubTotal = product.PricePerUnit * product.QuantitySold;
	}
	else if ((product.PricePerUnit == priceOf_120to130) && (product.ProductNumber >= 120 && product.ProductNumber <= 130)) {	 // hot drinks = 120 pesos
		return product.SubTotal = product.PricePerUnit * product.QuantitySold;
	}
	else if ((product.PricePerUnit == priceOf_220to230) && (product.ProductNumber >= 220 && product.ProductNumber <= 230)) {	// vegetables = 150 pesos
		return product.SubTotal = product.PricePerUnit * product.QuantitySold;
	}
	else if ((product.PricePerUnit == priceOf_240to250) && (product.ProductNumber >= 240 && product.ProductNumber <= 250)) {	 // meats = 170 pesos
		return product.SubTotal = product.PricePerUnit * product.QuantitySold;
	}
	else {
		throw invalid_argument("Product Price or Product Number is incorrect!");	// throw error message if the user enter out of range Price and Product Number
	}
}

float applyDiscounts(Sales_Computation& product, float& _subTotal) {
	return product.DiscountRate *= _subTotal;
}

float applyTax(Sales_Computation& product, float& Subtotal, float& discount) {
	return product.TaxRate = product.TaxRate * (Subtotal - discount);
}

float computeTotalSales(Sales_Computation& product, float& subtotal, float& Discount, float& Tax) {
	return product.TotalDue = (subtotal - Discount) + Tax;
}

void writeToFile(fstream& salesFile, Sales_Computation product[], const int arrSize, float _subTotal, float _seniorDiscount, float _ValueAddedTax, float _totalDue, float _customerCash, float _customerChange) {
	salesFile.open("SalesInfo.txt", ios::out);
	if (salesFile.is_open()) {
		salesFile << "----------------------------------------------" << endl;
		salesFile << "	 	Sales Receipt" << endl;
		salesFile << "----------------------------------------------" << endl;
		salesFile << " Qty   " << " Variation   " << "    Product No.   " << "Price" << endl;
		for (int i = 0; i < arrSize; i++) {
			salesFile << "  " << product[i].QuantitySold << "    " << product[i].Variation << " 	 " << product[i].ProductNumber << "         "  << product[i].PricePerUnit << ".00" << endl;
		}
		salesFile << "----------------------------------------------" << endl;
		salesFile << " SubTotal       : " << fixed << setprecision(2) << _subTotal << endl;
		salesFile << " Discount(20%)  : " << fixed << setprecision(2) << _seniorDiscount << endl;
		salesFile << " VAT(7%)        : " << fixed << setprecision(2) << _ValueAddedTax << endl;
		salesFile << " TOTAL Due      : " << fixed << setprecision(2) << _totalDue << endl;
		salesFile << "---------------------------" << endl;
		salesFile << " Cash           : " << fixed << setprecision(2) << _customerCash << endl;
		salesFile << " Change         : " << fixed << setprecision(2) << _customerChange << endl << endl;
		salesFile.close();
	}
	else {
		cout << " Error: Unable to open File!" << endl;
	}
}
