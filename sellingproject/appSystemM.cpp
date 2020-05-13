#include "appSystem.h"
#include"shoppingCart.h"

using namespace std;
//___________________________________________________________________
appSystem::~appSystem()
{
	for (int i = 0; i < AS_logic; i++)
		delete AS_arrayOfUsers[i];
	delete[] AS_arrayOfUsers;
	
}
//______________________________________________________________________
appSystem::appSystem()
{
	AS_updateArrays();
}
//___________________________________________________________________________________________________________________________________________________________
user* appSystem::returnExistUser(const char*name, const char*password)const //the function will return the seller which has the username and password as ask for
{
	int i = 0;
	while (i < AS_logic)
	{
		if (strcmp(name, AS_arrayOfUsers[i]->U_getName()) == 0)
			break;
		i++;
	}
	if (i == AS_logic)
	{
		cout << "the User isnt exist" << endl;
		return nullptr;
	}
	else
	{
		if (strcmp(password, AS_arrayOfUsers[i]->U_getPassword()) == 0)
			return AS_arrayOfUsers[i];
		else
			cout << "the password is Inncorect" << endl;
		return nullptr;
	}

}
//_________________________________________________________________________________________________________________________
void appSystem::AS_displayForSeller()// if the user is a seller that is his menu
{
	bool stop = false;
	int i;
	system("cls");//clear the screen
	cout << "for main menue -0   for new seller -1              for old seller -2       " << endl;
	cin >> i;
	switch (i)
	{
	case 0:
	{
		stop = true;
		break;
	}
	case 1:
	{
		user *newptr = nullptr;
		while (newptr == nullptr && stop == false)
		{
			newptr= AS_createNewUser(2);
			seller* sellerGlasses = dynamic_cast<seller*>(newptr);
			if (sellerGlasses != nullptr)// if the input is valid 
			{
				(*this) += newptr;
				AS_menuForSeller(sellerGlasses);// sending him to the seller menu
			}
			else
			{
				system("cls");
				cout << "the input is not valid .  try again-0    exit-1" << endl;

				cin >> stop;
			}
		}
		break;
	}
	case 2://the userName is already exist
	{
		user *newptr = nullptr;
		while (stop != true)
		{
			cout << "Type your userName" << endl;
			char Username[appSystem::MAXSIZEINPUT];
			cin.ignore();
			cin.getline(Username, MAXSIZEINPUT);
			cout << "ttpe your password" << endl;
			char password[appSystem::MAXSIZEINPUT];
			cin.getline(password, MAXSIZEINPUT);
			newptr = returnExistUser(Username, password);
			seller* SellerG = dynamic_cast<seller*>(newptr);
			if (SellerG == nullptr)
			{
				cout << "the input is not valid would you like to try again?   1-no     0- yes" << endl;
				cin >> stop;
			}
			else
			{
				AS_menuForSeller(SellerG);
				stop = true;
			}
		}
		break;
	}
		
	default:
		break;
	}

}

//___________________________________________________________________________________________________
void appSystem::AS_updateArrays()
{
	AS_logic = 0;
	AS_physic = 2;
	
	AS_arrayOfUsers = new user*[2];
}
//__________________________________________________________________________________________________
void appSystem::AS_addUser(user *ptr)
{
	if (AS_logic == AS_physic)
	{
		AS_physic *= 2;
		user **tempArray = new user*[AS_physic];
		for (int i = 0; i <= AS_logic; i++)
			tempArray[i] = AS_arrayOfUsers[i];
		delete[] AS_arrayOfUsers;
		AS_arrayOfUsers = tempArray;
	}
	AS_arrayOfUsers[AS_logic] = ptr;
	AS_logic++;
}


//____________________________________________________________________________________________________________________
user * appSystem::AS_createNewUser(int i)
{
	cout << "enter Your UserName,which supposed to contain at least 5 digits and less than 20" << endl;
	char userName[appSystem::MAXSIZEINPUT];
	cin.ignore();
	cin.getline(userName,MAXSIZEINPUT);
	cout << "enter you password supposed,which supposed to contain at least 5 digits and less than 20" << endl;
	char password[appSystem::MAXSIZEINPUT];
	cin.getline(password,MAXSIZEINPUT);
	cout << "enter your city of residence" << endl;
	char city[adress::MAX_LENGTH_CITY_STREET];
	cin.getline(city,MAXSIZEINPUT);
	cout << "enter your street of residence" << endl;
	char street[adress::MAX_LENGTH_CITY_STREET];
	cin.getline( street,MAXSIZEINPUT);
	int number;
	cout << "your home number is only digits " << endl;
	cin >> number;
	seller* newSeller = nullptr;
	consumer* newConsumer = nullptr;
	consumerAndseller* newConsumerAndSeller = nullptr;
	user*y = nullptr;
	adress *checkValidityByPtr = nullptr;
	if (checkValidityByPtr->A_checkValidity(city, street, number) == true)
	{
		adress ad(city, street, number);
		if (y->U_checkValidity(ad, userName,password) == true && AS_existUser(userName) == false)
		{
			switch (i)
			{
			case 1:
				newConsumer = new consumer(ad, userName, password);
				return newConsumer;
			case 2:
				newSeller = new seller(userName, password, ad);
				return newSeller;
			case 3:
				newConsumerAndSeller = new consumerAndseller(userName, password, ad);
				return newConsumerAndSeller;
			default: 
					break;
			}
		}
		else
			cout << "invalid input  password  or user name is inncorrect... or the username is already taken" << endl;
	}
	else cout << "the adrees is not valid" << endl;
	return nullptr;
}
//__________________________________________________________________________________________________________________________________

//_________________________________________________________________________________________________________________________________
void appSystem::AS_display()// the main menu throgh that menu the program will guide the user
{
	int i;
	bool exitApp = false,returnMainMenu=false;
	cout << "					welcome TO SELL,XOR,BUY      " << endl;
	_sleep(2000);
	system("cls");
	while (exitApp == false) 
	{
		while (returnMainMenu == false) 
		{
			
			cout << "///////////////////////////////////////////////////////////////////////////////////////////////////" << endl;
			cout << "///enter 0- return main menue///  enter 1-to seller////////////////////////////////////////////////" << endl;
			cout << "///enter - 2 to consumer///////// enter 3 - seller And consumer ////////// 4 - print all consumer//////" << endl;
			cout << "///5-print all seller//////6-print all  consumerAndSeller users/////7- check the operator/////////////" << endl;
			cin >> i;
			
			switch (i)
			{
			case 0:
				cin.clear();
				cin.ignore(256, '\n');
				returnMainMenu = true;
				continue;
			case 1:
				AS_displayForSeller();
				break;
			case 2:
				AS_displayForConsumer();
				break;
			case 3:
				AS_consumerAndSellerMenue();
				break;
			case 4:
				
				cout << "-------all consumer names are-------" << endl;

				AS_printAllConsumer();
				break;
			case 5:
				cout << "-------all seller names are-------" << endl;
				AS_printAllSellerUserName();
				break;
			case 6:
				AS_printConsumerAndSellerUsers();
				break;
			case 7:
				operatorCheck();
				break;
			default:
				cout << "wrong input";
				break;
			}
			
		}
		cout << "						continue-0 exit-1      " << endl;
		cin >> exitApp;
		returnMainMenu = false;
	}
	system("cls");
	cout << "--------------thank you for using sell.XOR.buy-----------------" << endl;

}
//__________________________________________________________________________________
void appSystem::AS_displayForConsumer()// when entering for consumer you have to options new/old 
{
	bool stop = false;
	int i;
	system("cls");
	cout << "for main menue -0   for new consumer -1              for old consumer -2" << endl;
	cin >> i;
	switch (i)
	{
	case 0:
	{
		stop = true;
		break;
	}
	case 1:
	{
		user *newptr = nullptr;
		while (newptr == nullptr && stop == false)
		{
			newptr = AS_createNewUser(1);
			consumer* consumerGlasses = dynamic_cast<consumer*>(newptr);
			if (consumerGlasses != nullptr)
			{
				(*this) += consumerGlasses;//add the user to the array
				AS_cosumerMenu(consumerGlasses);
			}
			else
			{
				system("cls");
				cout << "the input is not valid . for try again-0    exit-1" << endl;

				cin >> stop;
			}
		}
		break;
	}
	case 2://the userName is already exist
	{
		user *newptr = nullptr;
		while (stop != true)
		{
			cout << "Type your userName" << endl;
			char Username[appSystem::MAXSIZEINPUT];
			cin.ignore();
			cin.getline(Username, MAXSIZEINPUT);
			cout << "ttpe your password" << endl;
			char password[appSystem::MAXSIZEINPUT];
			cin.getline(password, MAXSIZEINPUT);
			newptr = returnExistUser(Username, password);
			consumer* consumerG = dynamic_cast<consumer*>(newptr);
			if (consumerG == nullptr)
			{
				cout << "the input is not valid would you like to try again?   1-no     0- yes" << endl;
				cin >> stop;
			}
			else
			{
				AS_cosumerMenu(consumerG);
				stop = true;
			}
		}
		break;
	}
	default: 
		break;
	}
	
}

//____________________________________________________________________________________________________
void appSystem::AS_cosumerMenu(consumer * cons)// the menu for the consumer
{
	
	int choose;
	bool stop = false;
	while (stop != true)
	{
		cout << "------thinking...------" << endl;
		_sleep(2000);
		system("cls");
		cout << "0- for exit    , 1-for print all product ,  2-print all of the product with specific name     3-show shopping cart "<<endl;
		cout << "4- add feedbackTo specific seller,  5-order" << endl;
		cin >> choose;
		switch (choose)
		{
		case 0:
		{
			stop = true;
			break;
		}
		case 1:
		{
			bool exitproductshow = false;
			int addOrNot;
			AS_printAllProduct();
			while (exitproductshow != true)
			{
				cout << "//////////////////////////////////////////////" << endl;
				cout << "			0-for exit		1-add product to shopping cart     " << endl;
				cin >> addOrNot;
				if (addOrNot == 1)
				{
					int se;
					cout << "type the serial number you want" << endl;
					cin >> se;
					product *productAddtoCart = AS_getProductBySerialNumber(se);
					if (productAddtoCart != nullptr)
						cons->C_addProductToCart(productAddtoCart);
					else
					{
						cout << "serial number isnt exist" << endl;
						_sleep(2000);
						exitproductshow = true;
					}
				}
				else
				{
					exitproductshow = true;
				}
			}
			system("cls");
			break;
		}
		case 2:
		{
			cout << "enter the product name you would like to search" << endl;
			char nameForSearch[product::MAX_LENGTH_PRODUCT_NAME];
			cin.ignore();
			cin.getline(nameForSearch, product::MAX_LENGTH_PRODUCT_NAME);
			if (AS_printProductSpecificName(nameForSearch) == false)
			{
				cout << "the product name dosnt exist " << endl;
				continue;
			}
			
			bool exitproductshow = false;
			int addOrNot;
			while (exitproductshow != true)
			{
				cout << "//////////////////////////////////////////////" << endl;
				cout << "			0-for exit		1-add product to shopping cart     " << endl;
				cin >> addOrNot;
				if (addOrNot == 1)
				{
					int se;
					cout << "type the serial number you want" << endl;
					cin >> se;
					product *productAddtoCart = AS_getProductBySerialNumber(se);
					if (productAddtoCart != nullptr)
						cons->C_addProductToCart(productAddtoCart);
					else
					{
						cout << "serial number isnt exist" << endl;
						exitproductshow = true;
					}
				}
				else if(addOrNot==0)
				{
					exitproductshow = true;
				}
			}
			break;
		}
		case 3:
		{
			
			cons->s_printConsumerShoppingCart();
			_sleep(1000);
			break;
		}
		case 4:
		{
			cout << "-------------username of all of the sellers are in the system:---------" << endl;
			if (AS_printAllSellerUserName() == false)//there are no seller
			{
				cout << "there are no seller at the system yet" << endl;
				continue;
			}
			else
			{
				cout << "type the seller username you want to write feedback to" << endl;
				char nameOfSeller[consumer::USER_NAME_LENGTH];
				cin.ignore();
				cin.getline(nameOfSeller,MAXSIZEINPUT);
				user *ptr = AS_findSellerForFeedback(nameOfSeller);
				seller * sellerGlasses = dynamic_cast<seller*>(ptr);
				consumerAndseller* CAS = dynamic_cast<consumerAndseller*>(ptr);
				if (ptr != nullptr || CAS!=nullptr)
				{
					if (sellerGlasses != nullptr)
					{
						if (sellerGlasses->AS_findIfConsumerPurchase(cons) == false)
						{
							cout << "you havnt purchase nothing from this seller you cant write feedback" << endl;
							continue;
						}

						else
						{
							feedback newfeedBack = AS_getFeedback(cons);
							if (newfeedBack.C_getConsumer() != nullptr)
								sellerGlasses->SE_Addfeedback(newfeedBack);
						}
					}
					else
					{
						if (CAS->AS_findIfConsumerPurchase(cons) == false)
						{
							cout << "you havnt purchase nothing from this seller you cant write feedback" << endl;
							continue;
						}

						else
						{
							feedback newfeedBack = AS_getFeedback(cons);
							if (newfeedBack.C_getConsumer() != nullptr)
								CAS->SE_Addfeedback(newfeedBack);
						}
					}
				}
				else 
				{
					cout << "the seller is not exist" << endl;
					_sleep(1500);
					continue;
				}
			}
			break;
			}
		case 5:
		{
			AS_OrderMenuForConsumer(cons);
			
			break;
		}
		default:
			cout << "you must choose the opptions 0-5" << endl;
			break;
		
		}
	}
}
//_________________________________________________________________________________________________________
void appSystem::AS_printAllProduct()											const
{
	for (int i = 0; i < AS_logic; i++)
	{
		seller* sellerGlasses = dynamic_cast<seller*>(AS_arrayOfUsers[i]);
		if (sellerGlasses)
		{
			int sizeofProductArray = sellerGlasses->SE_getLogicProduct();
			product** temp = sellerGlasses->SE_getArrayOfProduct();
			for (int j = 0; j < sizeofProductArray; j++)
				cout << temp[j] << endl;
		}
		else	
		{
			consumerAndseller*CASGlasses = dynamic_cast<consumerAndseller*>(AS_arrayOfUsers[i]);
			if (CASGlasses)
			{
				int sizeofProductArray = CASGlasses->SE_getLogicProduct();
				product** temp = CASGlasses->SE_getArrayOfProduct();
				for (int j = 0; j < sizeofProductArray; j++)
					cout << temp[j] << endl;
			}
		}
	}
}
//_____________________________________________________________________________________________________
bool appSystem::AS_printProductSpecificName(char *name)					const
{
	bool exist = false;
		for (int i = 0; i < AS_logic; i++)
		{
			seller* sellerGlasses = dynamic_cast<seller*>(AS_arrayOfUsers[i]);
			if (sellerGlasses)
			{
				int sizeofProductArray = sellerGlasses->SE_getLogicProduct();
				product** temp = sellerGlasses->SE_getArrayOfProduct();
				for (int j = 0; j < sizeofProductArray; j++)
					if (strcmp(temp[i]->P_getname(), name) == 0)
					{
						cout << temp[i] << endl;
						exist = true;
					}
			}
			else
			{
				consumerAndseller*CASGlasses = dynamic_cast<consumerAndseller*>(AS_arrayOfUsers[i]);
				if (CASGlasses)
				{
					int sizeofProductArray = CASGlasses->SE_getLogicProduct();
					product** temp = CASGlasses->SE_getArrayOfProduct();
					for (int j = 0; j < sizeofProductArray; j++)
						if (strcmp(temp[i]->P_getname(), name) == 0)
						{
							cout << temp[i] << endl;
							exist = true;
						}
				}
			}
		}
	return exist;
}
//________________________________________________________________________________________________________________________________
product * appSystem::AS_getProductBySerialNumber(int ser)									const
{
	for (int i = 0; i < AS_logic; i++)
	{
		seller* sellerGlasses = dynamic_cast<seller*>(AS_arrayOfUsers[i]);
		if (sellerGlasses)
		{
			int sizeofProductArray =sellerGlasses ->SE_getLogicProduct();
			product** temp = sellerGlasses->SE_getArrayOfProduct();
			for (int j = 0; j < sizeofProductArray; j++)
			{
				if (temp[j]->P_getSerialNumber() == ser)
					return temp[j];
			}
		}
		else 
		{
			consumerAndseller* cAsGlasses = dynamic_cast<consumerAndseller*>(AS_arrayOfUsers[i]);
				if (cAsGlasses)
				{
					int sizeofProductArray = cAsGlasses->SE_getLogicProduct();
					product** temp = cAsGlasses->SE_getArrayOfProduct();
					for (int j = 0; j < sizeofProductArray; j++)
					{
						if (temp[j]->P_getSerialNumber() == ser)
							return temp[j];
					}
				}
		}
	}
	return nullptr;
}
//_______________________________________________________________________________________________________________________
bool appSystem::AS_printAllSellerUserName()													const
{
	bool exist = false;
	for (int i = 0; i < AS_logic; i++)
	{
		seller* sellerGlasses = dynamic_cast<seller*>(AS_arrayOfUsers[i]);
		if (sellerGlasses)
		{
			exist = true;
			//sellerGlasses->print();
			cout << AS_arrayOfUsers[i] << endl;
		}
		}
	return exist;
}
//______________________________________________________________________________________________________________________________________
user* appSystem::AS_findSellerForFeedback(char *name)			const // the function will return the adress of the asked seller if he exist
{
	for (int i = 0; i < AS_logic; i++)
	{
		seller* sellerGlasses = dynamic_cast<seller*>(AS_arrayOfUsers[i]);
		if (sellerGlasses)
		{
			if (strcmp(sellerGlasses->U_getName(), name) == 0)
				return sellerGlasses;
		}
		else 
		{
			consumerAndseller* cAsGlasses = dynamic_cast<consumerAndseller*>(AS_arrayOfUsers[i]);
			if (cAsGlasses)
			{
				if (strcmp(cAsGlasses->U_getName(), name) == 0)
					return cAsGlasses;
			}
		}
	}
	return nullptr;
}
//__________________________________________________________________________________________________
feedback appSystem::AS_getFeedback(consumer *cons)// will get the feddback from the consumer and will return it 
{
	int eval;
	char date[MAXSIZEINPUT];
	system("cls");
	cout<<"type the date you purchased from the seller"<<endl;
	cout << "the date supposed to contain 10 digits for example 02.05.1995" << endl;
	cin.getline(date, MAXSIZEINPUT);
	cout << "type your evaluation for the seller" << endl;
	cout << "   0-worst  1- bad  2- average,   3-nice,   4-good,   5-best" << endl;
	cin >> eval;
	if (eval < 0 || eval>5 ||AS_checlValidityOfDate(date)==false )
		return feedback(date, nullptr, (feedback::F_evaluaton)eval, cons->U_getName());//in case of invalid input
	feedback newFeedback(date, cons, (feedback::F_evaluaton)eval, cons->U_getName());
	return newFeedback;
}
//________________________________________________________________________________________________________________________________
void appSystem::AS_printAllConsumer()				const
{
	for (int i = 0; i < AS_logic; i++)
	{
		consumer* consumerGlasses = dynamic_cast<consumer*>(AS_arrayOfUsers[i]);
		if (consumerGlasses!=nullptr)
		{
			cout << AS_arrayOfUsers[i] << endl;;
		}
	}
}
//________________________________________________________________
bool appSystem::AS_existUser(char*name)										const
{
	for (int i = 0; i < AS_logic; i++)
	{
		if (strcmp(AS_arrayOfUsers[i]->U_getName(), name) == 0)
			return true;
	}
	return false;
}
//________________________________________________________________________________________________________________________________
void appSystem::AS_menuForSeller(seller *currSeller)
{
	int acttion;
	system("cls");
	cout << "/////////////////////////////////////////////////" << endl;
	cout << "--------- hello seller:  " << currSeller->U_getName() <<"---------"<< endl;
	
	bool stop = false;
	while (stop != true)
	{
		_sleep(1500);
		system("cls");
		cout << "0-for exit	 1- for add product     2- for print all of your Feedbacks     3-for print all of your product " << endl;
		cin >> acttion;

		switch (acttion)
		{
		case 0:
		{
			stop = true;
			break;
		}
		case 1:
		{
			cout << "product name is" << endl;
			char P_name[product::MAX_LENGTH_PRODUCT_NAME];
			cin.ignore();
			cin.getline( P_name,product::MAX_LENGTH_PRODUCT_NAME);
			cout << "		0-kids,		1-office,		2-electricity,  3-clothing" << endl;
			int kind;
			cin >> kind;
			float price;
			cout << "the price is? type only digits " << endl;
			cin >> price;
			product* ptr = nullptr;
			if (ptr->P_checkValadity(P_name, (product::P_type)kind, price) == true)
			{
				ptr = new product(P_name, (product::P_type)kind, price, currSeller);
				currSeller->SE_addProduct(ptr);
				cout << "-----added----" << endl;
			}
			else
				cout << "the product is invalid product length supposed tocontain 20 digits max, the descriootion 0-3 " << endl;
			break;
		}
		case 2:
		{
			cout << "--------the feedbacks are-------------" << endl;
			int logicSize = currSeller->SE_getLogicfeedback();
			for (int i = 0; i <logicSize ; i++)
				currSeller->SE_ArrayOfFeedbacks[i].print();
			_sleep(1000);
			break;
		}
		case 3:
			cout << "----------the product are---------------" << endl;
			currSeller->SE_printAllProduct();
			_sleep(1000);
			break;
		default:
			break;
		}

	}

}
//________________________________________________________________________________________________
void appSystem::AS_OrderMenuForConsumer(consumer *consumerC)
{
	consumerC->C_setOrder();
	order *currentOrder = consumerC->C_getOrder();
	
	shoppingCart *ptr = consumerC->C_getShoppingcart();
	ptr->S_shoppingCartPrint();
	bool exitproductshow = false;
	int addOrNot;
	while (exitproductshow != true)
	{
		cout << "//////////////////////////////////////////////" << endl;
		cout << "			0-for exit		1-add product to order" << endl;
		cin >> addOrNot;
		if (addOrNot == 1)
		{
			int se;
			cout << "type the number of you want" << endl;
			cin >> se;
			product* newproduct = ptr->S_getproductByserialNumber(se);
			if (newproduct != nullptr)
			{
				if (currentOrder->O_checkifProductAlreadyChoose(se) == false)
					currentOrder->O_addItems(newproduct);
				else
					continue;
			}
			else
			{
				cout << "serial number isnt exist" << endl;
				return;

			}
		}
		else if (addOrNot == 0)
		{
			exitproductshow = true;
		}
	}
	system("cls");
	cout << "the product you choose are:" << endl;
	currentOrder->O_print();
	cout << "the price is:   " << currentOrder->O_getPrice() << "$" << endl;
	cout << "are you sure you want to purchase? 1-yes 0-no" << endl;
	int answer;
	cin >> answer;
	if (answer == 1)
	{
		cout << "  -------thank you for tour purchase-----" << endl;
		for (int i = 0; i < AS_logic; i++)
		{
			consumer* consumerGlasses = dynamic_cast<consumer*>(AS_arrayOfUsers[i]);
			if (consumerGlasses != nullptr)
			{
				consumerGlasses->C_getShoppingcart()->removeProductFromCart(currentOrder->O_getArrayOfProduct(), currentOrder->O_getLogic());
			}
		}
		currentOrder->O_deleteProductFromSeller(consumerC);
		delete (consumerC->C_getShoppingcart());
		consumerC->C_setShoppingCart();
	}
	else
	{
		delete currentOrder;
	}
}
//____________________________________________________________________________
bool appSystem::AS_checlValidityOfDate(char *date)
{
	if (strlen(date) != (feedback::DATE_LENGTH - 1) || date[2] != '.' || date[5] != '.')
		cout << " errorr -- the date isnt valid follow the instructions " << endl;
	_sleep(2000);
		return false;
	return true;
}
//___________________________________________________________________________________________
void appSystem::AS_consumerAndSellerMenue()
{
	user *existConsumr = nullptr;
	bool stop = false;
	int i;
	system("cls");
	cout << " main menue?  -0   new user?  -1               old user? -2" << endl;
	cin >> i;
	switch (i)
	{
	case 0:
	{
		stop = true;
		break;
	}
	case 1:
	{
		
		while (existConsumr == nullptr && stop == false)
		{
			existConsumr = AS_createNewUser(3);
			consumerAndseller* consumerAndSellerGlasses = dynamic_cast<consumerAndseller*>(existConsumr);
			if (consumerAndSellerGlasses != nullptr)
			{
				(*this) += consumerAndSellerGlasses;
			}
			else
			{
				system("cls");
				cout << "the input is not valid . for try again-0    exit-1" << endl;

				cin >> stop;
			}
		}
		break;
	}
	case 2://the userName is already exist
	{
		while (existConsumr == nullptr && stop != true)
		{
			cout << "Type your userName" << endl;
			char Username[appSystem::MAXSIZEINPUT];
			cin.ignore();
			cin.getline(Username, MAXSIZEINPUT);
			cout << "ttpe your password" << endl;
			char password[appSystem::MAXSIZEINPUT];
			cin.getline(password, MAXSIZEINPUT);
			existConsumr = returnExistUser(Username, password);
			consumerAndseller* consumerAndSellerGlasses = dynamic_cast<consumerAndseller*>(existConsumr);
			if (consumerAndSellerGlasses == nullptr)
			{
				existConsumr = nullptr;
				cout << "the input is not valid would you like to try again?   1-no     0- yes" << endl;
				cin >> stop;
			}
		}
		break;
	}
	default:
		break;
	}
	int choice;
	consumerAndseller* consumerAndSellerGlasses = dynamic_cast<consumerAndseller*>(existConsumr);
	if (consumerAndSellerGlasses != nullptr)
	{
		system("cls");
		cout << "hello consumer and seller" << endl;
		bool exitMenue = false;
		while (exitMenue!=true)
		{
			cout << "exit? -0   sellerMenu-1    consumer menue?-2"<<endl;
			cin >> choice;
			switch (choice)
			{
			case 0:
				exitMenue = true;
				break;
			case 1:
				AS_menuForSeller(consumerAndSellerGlasses);
				break;
			case 2:
				AS_cosumerMenu(consumerAndSellerGlasses);
				break;
			default:
				break;
			}
		}
	}
}
//__________________________________________________________________________________________________________________________________________________
void appSystem::operatorCheck()// the function for checks the operattors												
{
	char FUserName[MAXSIZEINPUT], SUserName[MAXSIZEINPUT];
	int choice;
	bool exitFunc = false;
	while (exitFunc == false)
	{
		_sleep(2000);
		system("cls");
		cout << "0-Exit   1- (operator '<')   2-(operator '+=')   3-(opertator'<<' for product)  "<<endl;
			cout<<"4-(opertator'<<' for Adress)   5-(opertator'<<' for user) " << endl;
		
			
		cin >> choice;
		switch (choice)
		{
		case 0:
			exitFunc = true;
			break;
		case 1:
		{
			AS_printAllConsumer();
			cout << "type the user name of the first consumer you want to compare to" << endl;
			cin.ignore();
			cin.getline(FUserName, MAXSIZEINPUT);
			consumer* firstComp = returnConsumerByUserName(FUserName);
			cout << "type the user name of the Second consumer you want to compare " << endl;
			cin.getline(SUserName, MAXSIZEINPUT);
			consumer* SecComp = returnConsumerByUserName(SUserName);
			if (firstComp != nullptr && SecComp != nullptr)
				cout << (firstComp < SecComp ? "true" : "flase") << endl;
			else
				cout << "--- errorr -- at least one of the consumer dosnt exist" << endl;
			break;
		}
		case 2:
		{
			cout << "you are now in the option of chcecking the += operator , you will add a new user to the user array" << endl;
			cout << "which user are you?    1-consumer    2-seller    3- consumer and seller?" << endl;
			int i;
			cin >> i;
			user* newUser = AS_createNewUser(i);
			if (newUser != nullptr)
			{
				(*this) += newUser;
				if (i == 1)
				{
					cout << "all consumer are" << endl;
					AS_printAllConsumer();
				}
				else if (i == 2)
				{
					cout << " all sellers are" << endl;
					AS_printAllSellerUserName();
				}
				else if (i == 3)
				{
					cout << " all consumer and seller users name are" << endl;
					AS_printConsumerAndSellerUsers();
				}
			}
			else
				cout << " the input isnt valid" << endl;
			break;
		}
		case 3:
		{
			cout << "in order to check the operator << for product , we will create an fictive product for example and print it using the << operator" << endl;
			product productForExample("sony 4", product::P_type(1), 13, nullptr);
			cout << (&productForExample) << endl;
			break;
		}
		case 4:
		{
			cout << "in order to check the operator << for adress, we will create anfictive  adress  and print it using the << operator" << endl;
			adress ad("tel aviv ", "jaffa ", 1);
			cout << ad << endl;
			break;
		}
		case 5:
		{
			cout << "in order to check the operator << for user, we will create an fictive user  and print it using the << operator" << endl;
			cout << "our user class is abstract so we cant make user variable , for our example we will create fictive  consumer " << endl;
			adress ad("tel aviv ", "jaffa ", 1);
			consumer fictiveConsumer(ad, "FictiveUserName", "FictivePassword");
			cout << (&fictiveConsumer) << endl;
			break;
		}
		default:
			break;
		}
	}

}
//_________________________________________________________________________________________________________________________________
consumer* appSystem::returnConsumerByUserName(const char*name) const
{
	for (int i = 0; i < AS_logic; i++)
	{
		if (strcmp(AS_arrayOfUsers[i]->U_getName(), name) == 0)
		{
			consumer* CGlasses = dynamic_cast<consumer*>(AS_arrayOfUsers[i]);
			return CGlasses;
		}
	}
	return nullptr;

}
//_____________________________________________________________________________________________________________________________________
const user* appSystem::operator+=( user*newuser)// addind the user to the array using the += operator
{
	AS_addUser(newuser);
	return newuser;
}
//__________________________________________________________________________________________________________________________________
void appSystem::AS_printConsumerAndSellerUsers()								const
{
	for (int i = 0; i < AS_logic; i++)
	{
		consumerAndseller* CASGlasses = dynamic_cast<consumerAndseller*>(AS_arrayOfUsers[i]);
		if (CASGlasses != nullptr)
		{
			cout << AS_arrayOfUsers[i] << endl;
		}
	}
}