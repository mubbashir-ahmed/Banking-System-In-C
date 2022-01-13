#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void Options();
void openAccount();
void accountDetails();
void cashWithdrawal();
void cashDeposit();
void utilityBills();

struct acc_info 
{
	char BankName[50];
	char BranchName[50];
	int BranchCode;
	char AccHolderName[50];
	int AccNumber;
	char AccHolderAddress[100];
	float Balance;
};
struct acc_info info[30] = {{"Mezan", "Clifton", 0107, "Ali", 1, "Defence", 15000}, {"Mezan", "Gulistan-e-Jauhar", 0115, "Imran", 2, "Gulistan-e-Jauhar", 10000}, {"Mezan", "North-Karachi", 0117, "Hasan", 3, "North-Karachi", 5000}};
int Acc;

main()
{
	while(1)
	{
		printf("\t\t\t\t\tBANK ACCOUNT MANAGEMENT SYSYTEM APPLICATION\n");
		printf("\t\t\t\t\t===========================================\n");
		Options();
	}
}

void Options()
{
	int op;
	printf("\nACCOUNT OPTIONS");
	printf("\n==>1. Open An Account\n==>2. Account Details\n==>3. Cash Withdrawal\n==>4. Cash Deposit\n==>5. Utility Bills Payment\n==>6. Exit");
	printf("\nPlease Choose from the given Options (1-6): ");
	scanf("%d", &op);
	
	switch(op)
	{
		case 1:
			openAccount();
			main();
			break;
		case 2:
			accountDetails();
			break;
		case 3:
			cashWithdrawal();
			break;
		case 4:
			cashDeposit();
			break;
		case 5:
			utilityBills();
			break;
		case 6:
			exit(0);
	}
}

void openAccount()
{
	char BankName[50];
	char BranchName[50];
	int BranchCode;
	char AccHolderName[50];
	int AccNumber;
	char AccHolderAddress[100];
	float Balance;
	
	printf("\nCREATE A NEW ACCOUNT");
	printf("\nEnter Bank Name: ");
	scanf("%s", &BankName);
	printf("Enter Branch Name: ");
	scanf("%s", &BranchName);
	printf("Enter Branch Code: ");
	scanf("%d", &BranchCode);
	printf("Enter Account Holder Name: ");
	scanf("%s", &AccHolderName);
	printf("Enter Account Number(1 to 50): ");
	scanf("%d", &AccNumber);
	printf("Enter Account Holder Address: ");
	scanf("%s", &AccHolderAddress);
	printf("Enter Balance for Opening Account: ");
	scanf("%f", &Balance);

	strcpy(info[AccNumber-1].BankName, BankName);
	strcpy(info[AccNumber-1].BranchName, BranchName);
	info[AccNumber-1].BranchCode = BranchCode;
	strcpy(info[AccNumber-1].AccHolderName, AccHolderName);
	info[AccNumber-1].AccNumber = AccNumber;
	strcpy(info[AccNumber-1].AccHolderAddress, AccHolderAddress);
	info[AccNumber-1].Balance = Balance;
	
	printf("\nBank Name: %s", info[AccNumber-1].BankName);
	printf("\nBranch Name: %s", info[AccNumber-1].BranchName);
	printf("\nBranch Code: %d", info[AccNumber-1].BranchCode);
	printf("\nAccount Holder Name: %s", info[AccNumber-1].AccHolderName);
	printf("\nAccount Number: %d", info[AccNumber-1].AccNumber);
	printf("\nAccount Holder Address: %s", info[AccNumber-1].AccHolderAddress);
	printf("\nBalance: %0.1f", info[AccNumber-1].Balance);
	
	printf("\nACCOUNT SUCCESSFULLY CREATED!\n\n");
}

void accountDetails()
{
	int AccNum = 0;
	while(info[AccNum].AccNumber>0)
	{
		printf("\nBank Name: %s", info[AccNum].BankName);
		printf("\nBranch Name: %s", info[AccNum].BranchName);
		printf("\nBranch Code: %d", info[AccNum].BranchCode);
		printf("\nAccount Holder Name: %s", info[AccNum].AccHolderName);
		printf("\nAccount Number: %d", info[AccNum].AccNumber);
		printf("\nAccount Holder Address: %s", info[AccNum].AccHolderAddress);
		printf("\nBalance: %0.1f\n\n", info[AccNum].Balance);
		AccNum++;
	}
}

void cashWithdrawal()
{
	int AccNum;
	float wdwAmount;
	printf("\nCASH WITHDRAWAL");
	printf("\nEnter Account Number: ");
	scanf("%d", &AccNum);
	printf("The Current Balance is: %0.1f", info[AccNum-1].Balance);
	printf("\nEnter Amount to Withdraw: ");
	scanf("%f", &wdwAmount);
	
	while(AccNum = info[AccNum-1].AccNumber)
	{
		if(wdwAmount <= info[AccNum-1].Balance)
		{
			info[AccNum-1].Balance = info[AccNum-1].Balance - wdwAmount;
			printf("The New Balance is: %0.1f\n\n", info[AccNum-1].Balance);
			
			FILE *WAptr;
			WAptr = (fopen("Withdrawal Reciept.txt", "a"));
			fprintf(WAptr, "\nBank Name: %s", info[AccNum-1].BankName);
			fprintf(WAptr, "\nBranch Name: %s", info[AccNum-1].BranchName);
			fprintf(WAptr, "\nBranch Code: %d", info[AccNum-1].BranchCode);
			fprintf(WAptr, "\nAccount Holder Name: %s", info[AccNum-1].AccHolderName);
			fprintf(WAptr, "\nAccount Number: %d", info[AccNum-1].AccNumber);
			fprintf(WAptr, "\nAccount Holder Address: %s", info[AccNum-1].AccHolderAddress);
			fprintf(WAptr, "\nBalance: %0.1f\n\n", info[AccNum-1].Balance);
			
			fclose(WAptr);
			
			printf("RECEIPT GENERATED!\n\n");
			break;
		}
		else
		{
			printf("Not Enough Amount!");
			cashWithdrawal();
		}
	}
	AccNum++;
}

void cashDeposit()
{
	int AccNum;
	float depAmount;
	
	printf("\nCASH DEPOSIT");
	printf("\nEnter Account Number: ");
	scanf("%d", &AccNum);
	printf("The Current Balance is: %0.1f", info[AccNum-1].Balance);
	printf("\nEnter Amount to Deposit: ");
	scanf("%f", &depAmount);
	
	while(AccNum = info[AccNum-1].AccNumber)
	{
		info[AccNum-1].Balance = info[AccNum-1].Balance + depAmount;
		printf("The New Balance is: %0.1f\n\n", info[AccNum-1].Balance);
		break;
	}
	AccNum++;
}

void utilityBills()
{
	int billOp, AccNum, billAmount;
	
	printf("\nUTILITY BILLS PAYMENT:");
	printf("\n==>1. Electricity Bill Payment\n==>2. Water Bill Payment\n==>3. Gas Bill Payment");
	printf("\nPlease Choose from the given Options (1-3): ");
	scanf("%d", &billOp);
	
	if(billOp == 1)
	{
		printf("Enter Account Number: ");
		scanf("%d", &AccNum);
		printf("Enter Amount of Electricity Bill to be Paid: ");
		scanf("%d", &billAmount);
	
		while(AccNum = info[AccNum-1].AccNumber)
		{
			info[AccNum-1].Balance = info[AccNum-1].Balance - billAmount;
			printf("You have Paid a Electricity Bill of %d", billAmount);
			printf("\nThe New Balance of your Account is: %0.1f\n\n", info[AccNum-1].Balance);
			break;
		}
		AccNum++;
	}
	else if(billOp == 2)
	{
		printf("Enter Account Number: ");
		scanf("%d", &AccNum);
		printf("Enter Amount of Water Bill to be Paid: ");
		scanf("%d", &billAmount);
	
		while(AccNum = info[AccNum-1].AccNumber)
		{
			info[AccNum-1].Balance = info[AccNum-1].Balance - billAmount;
			printf("You have Paid a Water Bill of %d", billAmount);
			printf("\nThe New Balance of your Account is: %0.1f\n\n", info[AccNum-1].Balance);
			break;
		}
		AccNum++;
	}
	else if(billOp == 3)
	{
		printf("Enter Account Number: ");
		scanf("%d", &AccNum);
		printf("Enter Amount of Gas Bill to be Paid: ");
		scanf("%d", &billAmount);
	
		while(AccNum = info[AccNum-1].AccNumber)
		{
			info[AccNum-1].Balance = info[AccNum-1].Balance - billAmount;
			printf("You have Paid a Gas Bill of %d", billAmount);
			printf("\nThe New Balance of your Account is: %0.1f\n\n", info[AccNum-1].Balance);
			break;
		}
		AccNum++;
	}
}
