
Sales Computation system allows users to input the product they want to order base on, product variation, product price, product number, and the quantity they want to purchase. The program will then compute the subtotal, discount, Value Added Tax(VAT), and total due of the order. The user then input the amount of cash given, and the program will compute the change amount.

The system uses an array of structure called "Sales Computation" that store the details of the products that will be sold. The struct has the following members:

•	Variation: a cstring that stores the name of the product variation 

•	PricePerUnit: an integer that stores the price per unit of the product

•	ProductNumber: an integer that stores the product number of the variation

•	QuantitySold: an integer that stores the quantity of the product sold

•	SubTotal: a float that stores the subtotal of the order

•	DiscountRate: a float that stores the discount rate (currently set at 20%)

•	TaxRate: a float that stores the tax rate (currently set at 7%)

•	TotalDue: a float that stores the total due for the order

The system also has 5 functions:

•	computeOrderPrice: calculates the subtotal of the order

•	applyDiscounts: applies the discount to the subtotal

•	applyTax: applies the VAT to the discounted subtotal

•	computeTotalSales: calculates the total due for the order

•	writeToFile: that writes the details of the order to a file called "SalesInfo.txt".

The main function of the program uses a menu system to allow the user to interact with the program. The user can select from the following options:

A.	Product List: displays a list of the available products for sale.

B.	Order List: display all the details of the order from array of structure.

C.	Sales Receipt: displays the details of the order and writes them to the SalesInfo.txt file.

D.	Exit: exits the program.

![Menu](https://github.com/RoMiyo21/SalesComputation/assets/133717480/ad75938d-1fb7-4605-95b8-c7cd4c0104cc)

![image](https://github.com/RoMiyo21/SalesComputation/assets/133717480/46191c70-b84d-4c95-bfe8-3b0c1920d5ed)
