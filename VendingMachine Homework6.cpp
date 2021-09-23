#include <iostream>
using namespace std;

int main()
{
	int a=17, b=25, c=28, d=32; //product price
	int onedollar=100, twodollar=100, fivedollars=100, tendollars=100; //coins are preloaded 
	int ovf1=0, ovf2=0, ovf5=0, ovf10=0;	//number of coins in the overflow 
	int pay_one, pay_two, pay_five, pay_ten; //to handle customer payments
	int temp_one, temp_two, temp_five, temp_ten; //to store the incremented payments
	int product; //user input for product choice
	int pwd; //Authorized password is 12345
	
	//this will run when muchine has sufficient change inside
	while (onedollar!=0 || twodollar!=0 || fivedollars!=0 || tendollars!=0 ) 
	{
		cout << "Welcome! How may I help you? \n" << endl;
		cout << "Enter 1 to purchase Product A $17 \nEnter 2 to purchase Product B $25 \nEnter 3 to purchase Product C $28 \nEnter 4 to purchase Product D $32" << endl;
	
		cout << "Please Enter Product (or password): ";
		cin >> product; 
		
		if (product == 0) //to show coins out of range
		{
			break;
		}
		
		//if invalid number entered as product this will run
		while ( ! (product>=1 && product<=4 ) ) 
		{
			cout << "Invalid!" << endl;
			cout << "Enter 1 to purchase Product A $17 \nEnter 2 to purchase Product B $25 \nEnter 3 to purchase Product C $28 \nEnter 4 to purchase Product D $32" << endl;
			cout << "Please Enter Product (or password): ";
			cin.clear();
			cin.ignore();
			cin >> product;
		}
		cout << endl;
		
		int price; //to display price
		
		//display price
		switch (product)
		{
			case 1: 
				price=a;
				cout << "Your price is $17" << endl;
				break;
			case 2:
				price=b;
				cout << "Your price is $25" << endl;
				break;
			case 3:
				price=c;
				cout << "Your price is $28" << endl;
				break;
			case 4:
				price=d;
				cout << "Your price is $32" << endl;
				break;
		}
		cout << endl;
		
		//initializing variables
		pay_one=0, pay_two=0, pay_five=0, pay_ten=0;
		temp_one=0, temp_two=0, temp_five=0, temp_ten=0;
		int count=0, lack=0, payment=0;	//count-increments, lack- insufficient Value, //payment- customer payment
		
		while(payment<price)
		{ //this will be executed until customer enters the sufficient payment
			if (count!=0) 
			{
				lack = price-payment;
				cout << "$" << lack << " is insufficient! Insert remaining" << endl;
			}
			cout << "Only $1 $2 $5 and $10 coins are accepted" << endl;
			
			cout << "Number of $1 coins: ";
			cin >> pay_one;
			cout << "Number of $2 coins: ";
			cin >> pay_two;
			cout << "Number of $5 coins: ";
			cin >> pay_five;
			cout << "Number of $10 coins: ";
			cin >> pay_ten;
			
			temp_one += pay_one;
			temp_two += pay_two;
			temp_five += pay_five;
			temp_ten += pay_ten;
			
			//calculate the total payment
			payment+=(pay_one*1 + pay_two*2 + pay_five*5 + pay_ten*10);
			
			//add entered coins to relevant denomination reserve 
			onedollar+=pay_one;
			twodollar=pay_two;
			fivedollars=pay_five;
			tendollars=pay_ten;
			
			pay_one=0, pay_two=0, pay_five=0, pay_ten=0; //reset values
			count++;
		}
		
		//Balance calculation
		int balance = payment - price;
		int temp_balance=balance;
		pay_one=0, pay_two=0, pay_five=0, pay_ten=0;
		
		pay_ten=balance/10;
		if(tendollars < pay_ten)
		{
			pay_ten = tendollars;
		}
		balance = balance - pay_ten*10;
		
		pay_five=balance/10;
		if(fivedollars < pay_five)
		{
			pay_five = fivedollars;
		}
		balance = balance - pay_five*5;  
		
		pay_two=balance/10;
		if(twodollar < pay_two)
		{
			pay_two = twodollar;
		}
		balance = balance - pay_two*2;
		
		pay_one=balance/10;
		if(onedollar < pay_one)
		{
			pay_one = onedollar;
		}
		balance = balance - pay_one*1;
		
		bool changed = 1; //used to store balanced paid(1) or not paid(0)
		
		//deliver change to cutomer
		if(changed)
		{
			if(temp_balance==0)
			{
				cout << "Your Balance is $" << temp_balance << endl;
			}
			else
			{
				cout << "Your Balance is $" << temp_balance <<" Please Collect!" << endl;
			}
		}
		else
		{
			cout << "Sorry! Out of change! Please get back your $" << payment << endl;
		}
		
		if (pay_ten)
		{
			cout << "$10: " << pay_ten << endl;
		}
		if (pay_five)
		{
			cout << "$5: " << pay_five << endl;
		}
		if (pay_two)
		{
			cout << "$2: " << pay_two << endl;
		}
		if (pay_one)
		{
			cout << "$1: " << pay_one << endl;
		}
		
		cout << "Enjoy!" << endl << endl;
				
		//balance is deducted
		onedollar-=pay_one;
		twodollar-=pay_two;
		fivedollars-=pay_five;
		tendollars-=pay_ten;
		
		//move excess coins to relevant overflow bins
		if(onedollar>120)
		{
			ovf1+=(onedollar-100);
			onedollar=100;	
		}
		if(twodollar>120)
		{
			ovf2+=(twodollar-100);
			twodollar=100;	
		}
		if(fivedollars>120)
		{
			ovf5+=(fivedollars-100);
			fivedollars=100;	
		}
		if(tendollars>120)
		{
			ovf10+=(tendollars-100);
			tendollars=100;	
		}
		
		//reinitializing variables
		pay_one=0, pay_two=0, pay_five=0, pay_ten=0;
		temp_one=0, temp_two=0, temp_five=0, temp_ten=0;
		payment=0, balance=0;	
		
		//Owner terminates
		pwd=0;
		cout << "Press 0 to end! \nAuthorized personal can enter password: " ;
		cin >> pwd;
		if(pwd==12345)
		{
			break;
		}
		cout << endl;
	}
	cout << endl;
	
	
	if (pwd!=12345) 
	{//this will run only when machines is out of change
		cout << "Out of Change! Please Check Denomination Reserves" << endl;
	}
	else
	{//this will ruun when owner terminates
		cout << "Owner Terminated the Program" << endl;
	}
	
	//Display coins in denomination reserves
	cout << "Coins in each Denomination Reserve" << endl;
	cout << "Number of coins in $1 Reserve: " << onedollar << endl;
	cout << "Number of coins in $2 Reserve: " << twodollar << endl;
	cout << "Number of coins in $5 Reserve: " << fivedollars << endl;
	cout << "Number of coins in $10 Reserve: " << tendollars << endl << endl;
	
	//Display coins in overflow bin
	cout << "Coins in each Overflow Bin" << endl;
	cout << "Number of coins in $1 Reserve: " << ovf1 << endl;
	cout << "Number of coins in $2 Reserve: " << ovf2 << endl;
	cout << "Number of coins in $5 Reserve: " << ovf5 << endl;
	cout << "Number of coins in $10 Reserve: " << ovf10 << endl << endl;
	
	/*
	Assumptions
	Maximum of each denomination reserve is 120 coins.
	Customer always enters legally valid coins.
	*/
}
