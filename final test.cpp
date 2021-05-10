#ifndef ATM_H
#define ATM_H 
#ifndef SCREEN_H
#define SCREEN_H
#include "Screen.h"
#include "Keypad.h" 
#include "CashDispenser.h" 
#include "DepositSlot.h" 
#include "BankDatabase.h" 
class Transaction; 
class ATM
{
	public:
	ATM(); 
	void run(); 
	private:
	bool userAuthenticated; 
	int currentAccountNumber; 
	Screen screen; 
	Keypad keypad; 
	CashDispenser cashDispenser; 
	DepositSlot depositSlot; 
	BankDatabase bankDatabase; 
	 
	 void authenticateUser(); 
	void performTransactions(); 
	int displayMainMenu() const; 
	Transaction *createTransaction( int );
	 }; 
	#endif /
 
 #include 
 using std::string;
 
 class Screen
{
public:
void displayMessage( string ) const; 
void displayMessageLine( string ) const; 
void displayDollarAmount( double ) const; 
}; 

#endif 
#include 
using std::cout;
using std::endl;
using std::fixed;

#include 
using std::setprecision;

#include "Screen.h" 

void Screen::displayMessage( string message ) const
{
cout << message;
} 

 
void Screen::displayMessageLine( string message ) const
 {
 cout << message << endl;
} 

 void Screen::displayDollarAmount( double amount ) const
 {
cout << fixed << setprecision( 2 ) << "$" << amount;
} 
#ifndef KEYPAD_H
#define KEYPAD_H
class Keypad
{
	public:
	int getInput() const;
};
#endif
#include 
using std::cin;
#include "Keypad.h"
int Keypad::getInput() const
{
int input; 
cin >> input; 
return input; 
} 
#ifndef CASH_DISPENSER_H
#define CASH_DISPENSER_H
class CashDispenser
{
 	public:
	CashDispenser();	
	void dispenseCash( int );
	bool isSufficientCashAvailable( int ) const;
	private:
	const static int INITIAL_COUNT = 500;
	int count; 
	}; 
#endif
#include "CashDispenser.h"
CashDispenser::CashDispenser()
{
count = INITIAL_COUNT;
} 
void CashDispenser::dispenseCash( int amount )
{
int billsRequired = amount / 20; 
count -= billsRequired; 
} 
bool CashDispenser::isSufficientCashAvailable( int amount ) const
{
int billsRequired = amount / 20;
if ( count >= billsRequired )
return true; 
else
return false; 
} 
#ifndef DEPOSIT_SLOT_H
#define DEPOSIT_SLOT_H
class DepositSlot
{
	public:
 	bool isEnvelopeReceived() const; 
};
#endif

#include "DepositSlot.h"
 	bool DepositSlot::isEnvelopeReceived() const
 	{
	return true;
	}
#ifndef ACCOUNT_H
#define ACCOUNT_H
class Account
{
	public:
	 Account( int, int, double, double );
	bool validatePIN( int ) const; 
	double getAvailableBalance() const;
	double getTotalBalance() const; 
	void credit( double ); 
	void debit( double ); 
	int getAccountNumber() const; 
	private:
	int accountNumber; 
	int pin; 
	double availableBalance; 
	double totalBalance;
}; 
#endif
#include "Account.h"
	Account::Account( int theAccountNumber, int thePIN,
	double theAvailableBalance, double theTotalBalance )
 	: accountNumber( theAccountNumber ),
	pin( thePIN ),
	availableBalance( theAvailableBalance ),
	totalBalance( theTotalBalance )
	{
	} 
bool Account::validatePIN( int userPIN ) const
{
	if ( userPIN == pin )
	return true;
	else
	return false;
} 
	double Account::getAvailableBalance() const
	{
	return availableBalance;
	} 
	double Account::getTotalBalance() const
	{
	return totalBalance;
	} 
void Account::credit( double amount )
{
totalBalance += amount;
} 
void Account::debit( double amount )
{
availableBalance -= amount;
totalBalance -= amount;
} 
int Account::getAccountNumber() const
{
return accountNumber;
} 
#ifndef BANK_DATABASE_H
#define BANK_DATABASE_H
#include
using std::vector;
#include "Account.h" 
class BankDatabase
{
public:BankDatabase();
bool authenticateUser( int, int ); 
double getAvailableBalance( int );
double getTotalBalance( int ); 
void credit( int, double );
void debit( int, double ); 
private:
vector< Account > accounts; 
Account * getAccount( int );
};
#endif 
#include "BankDatabase.h"
 BankDatabase::BankDatabase()
 {
 Account account1( 12345, 54321, 1000.0, 1200.0 );
Account account2( 98765, 56789, 200.0, 200.0 );
accounts.push_back( account1 );
accounts.push_back( account2 );
}
Account * BankDatabase::getAccount( int accountNumber )
{
for ( size_t i = 0; i < accounts.size(); i++ )
{
if ( accounts[ i ].getAccountNumber() == accountNumber )
return &accounts[ i ];
} 
return NULL;
}
bool BankDatabase::authenticateUser( int userAccountNumber,
int userPIN )
{
Account * const userAccountPtr = getAccount( userAccountNumber );
if ( userAccountPtr != NULL )
return userAccountPtr->validatePIN( userPIN );
else
return false;
} 
double BankDatabase::getAvailableBalance( int userAccountNumber )
{
Account * const userAccountPtr = getAccount( userAccountNumber );
return userAccountPtr->getAvailableBalance();
}
double BankDatabase::getTotalBalance( int userAccountNumber )
{
Account * const userAccountPtr = getAccount( userAccountNumber );
return userAccountPtr->getTotalBalance();
}
void BankDatabase::credit( int userAccountNumber, double amount )
{
Account * const userAccountPtr = getAccount( userAccountNumber );
userAccountPtr->credit( amount );
} 
void BankDatabase::debit( int userAccountNumber, double amount )
{
Account * const userAccountPtr = getAccount( userAccountNumber );
userAccountPtr->debit( amount );
}

#ifndef TRANSACTION_H
define TRANSACTION_H
class Screen
class BankDatabase
class Transaction
{
public:Transaction( int, Screen &, BankDatabase & );
virtual ~Transaction() { }
int getAccountNumber() const;
Screen &getScreen() const; BankDatabase &getBankDatabase() const;
virtual void execute() = 0; 
private:
int accountNumber; 
Screen &screen; BankDatabase &bankDatabase; 
};
#endif
#ifndef BALANCE_INQUIRY_H
#define BALANCE_INQUIRY_H
#include "Transaction.h"
class BalanceInquiry : public Transaction
{
public:
BalanceInquiry( int, Screen &, BankDatabase & );
virtual void execute(); 
};
#endif
 	#include "BalanceInquiry.h"
 	#include "Screen.h" 
 	#include "BankDatabase.h"
	BalanceInquiry:: BalanceInquiry( int userAccountNumber, Screen &atmScreen,
 	BankDatabase &atmBankDatabase )	: Transaction( userAccountNumber, atmScreen, atmBankDatabase )
	 {
	}
void BalanceInquiry::execute()
{
BankDatabase &bankDatabase = getBankDatabase();
Screen &screen = getScreen();
double availableBalance =
bankDatabase.getAvailableBalance( getAccountNumber() );
double totalBalance =
bankDatabase.getTotalBalance( getAccountNumber() );
screen.displayMessageLine( "
Balance Information:" );
screen.displayMessage( " - Available balance: " );
screen.displayDollarAmount( availableBalance );
screen.displayMessage( "
 - Total balance: " );
screen.displayDollarAmount( totalBalance );
screen.displayMessageLine( "" );
}

#ifndef WITHDRAWAL_H
#define WITHDRAWAL_H
#include "Transaction.h"
	class Keypad;
	class CashDispenser;
	class Withdrawal : public Transaction
{
public:
Withdrawal( int, Screen &, BankDatabase &, Keypad &, CashDispenser & );
virtual void execute();
private;
int amount;
Keypad &keypad;
CashDispenser &cashDispenser; 
int displayMenuOfAmounts() const;
};
#endif
#include "Withdrawal.h"
#include "Screen.h" 
#include "BankDatabase.h" 
#include "Keypad.h" 
#include "CashDispenser.h"
const static int CANCELED = 6;
Withdrawal::Withdrawal( int userAccountNumber, Screen &atmScreen,
BankDatabase &atmBankDatabase, Keypad &atmKeypad,
CashDispenser &atmCashDispenser )
: Transaction( userAccountNumber, atmScreen, atmBankDatabase ),
keypad( atmKeypad ), cashDispenser( atmCashDispenser )
{
}
void Withdrawal::execute()
{
bool cashDispensed = false; 
bool transactionCanceled = false; 
BankDatabase &bankDatabase = getBankDatabase();
Screen &screen = getScreen();
do
{
int selection = displayMenuOfAmounts();if ( selection != CANCELED )
amount = selection;
double availableBalance =
bankDatabase.getAvailableBalance( getAccountNumber() );
if ( amount <= availableBalance )
{
if ( cashDispenser.isSufficientCashAvailable( amount ) )
{
bankDatabase.debit( getAccountNumber(), amount );
cashDispenser.dispenseCash( amount );
cashDispensed = true;
screen.displayMessageLine("Please take your cash from the cash dispenser." );
}
else
screen.displayMessageLine("Insufficient cash available in the ATMPlease choose a smaller amount." );
}else
{
screen.displayMessageLine("Insufficient funds in your accountPlease choose a smaller amount." );
else
{
screen.displayMessageLine( "Canceling transaction..." );
transactionCanceled = true; 
}
} while ( !cashDispensed && !transactionCanceled );
}
int Withdrawal::displayMenuOfAmounts() const
{
int userChoice = 0;
Screen &screen = getScreen();
int amounts[] = { 0, 20, 40, 60, 100, 200 }
while ( userChoice == 0 )
}
screen.displayMessageLine( "
Withdrawal options:" );
screen.displayMessageLine( "1 - $20" );
screen.displayMessageLine( "2 - $40" );
screen.displayMessageLine( "3 - $60" );
screen.displayMessageLine( "4 - $100" );
screen.displayMessageLine( "5 - $200" );
screen.displayMessageLine( "6 - Cancel transaction" );
screen.displayMessage( "
Choose a withdrawal option (1-6): " );
int input = keypad.getInput();
switch ( input )
{
case 1:
case 2:
case 3: 
case 4:
case 5:
userChoice = amounts[ input ];
break;
case CANCELED: 
userChoice = CANCELED; 
break;
default: 
screen.displayMessageLine("Ivalid selection. Try again." );
}
return userChoice;
}

#ifndef DEPOSIT_H
#define DEPOSIT_H
#include "Transaction.h"
	class Keypad;
	class DepositSlot;
 	class Deposit : public Transaction
	{
	public:
	Deposit( int, Screen &, BankDatabase &, Keypad &, DepositSlot & );
	virtual void execute(); 
	private:
	double amount; 
	Keypad &keypad; 
	DepositSlot &depositSlot; 
	double promptForDepositAmount() const;
	}; 
#endif
#include "Deposit.h"
#include "Screen.h"
#include "BankDatabase.h"
#include "Keypad.h"
#include "DepositSlot.h"
	const static int CANCELED = 0;
	Deposit::Deposit( int userAccountNumber, Screen &atmScreen,
	BankDatabase &atmBankDatabase, Keypad &atmKeypad,
	DepositSlot &atmDepositSlot )
	: Transaction( userAccountNumber, atmScreen, atmBankDatabase ),
	keypad( atmKeypad ), depositSlot( atmDepositSlot )
	{
		
	}
	void Deposit::execute()
	{
BankDatabase &bankDatabase = getBankDatabase();
Screen &screen = getScreen();
amount = promptForDepositAmount();
if ( amount != CANCELED )
{
screen.displayMessage("Please insert a deposit envelope containing " );
screen.displayDollarAmount( amount );
screen.displayMessageLine( " in the deposit slot." );
bool envelopeReceived = depositSlot.isEnvelopeReceived();
if ( envelopeReceived )
{
screen.displayMessageLine( "Your envelope has been received \nNOTE: The money just will not be available until we verify the amount of any enclosed cash, and any enclosed checks clear." );
bankDatabase.credit( getAccountNumber(), amount );
}
els
{
screen.displayMessageLine( "You did not insert an \n envelope, so the ATM has canceled your transaction." );
} 
}
else
{
screen.displayMessageLine( "Canceling transaction..." );
}
}
double Deposit::promptForDepositAmount() const
{
Screen &screen = getScreen();
screen.displayMessage( "Please enter a deposit amount in CENTS (or 0 to cancel): " );
int input = keypad.getInput();
if ( input == CANCELED )
return CANCELED;
else
{
return static_cast< double >( input ) / 100;
}
}
#include "ATM.h"
 int main()
 {
 ATM atm;
 atm.run();
return 0;
}
