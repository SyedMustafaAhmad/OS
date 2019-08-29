//Class Definitions
#include "Header.h"


//          ###     Functions   ###
//Setters
//Getters
//Functions
void Functions::RunFunction(int FN)
{
	switch (FN)
	{
	case 0:
		VA.ClearAll();
		break;
	case 1:
		VA.LogoutScreen();
		break;
	case 2:
		MS.DisplayMachineState();
		break;
	case 3:
		D.CreateFile();
		break;
	case 4:
		D.EditFile();
		break;
	case 5:
		D.DeleteFile();
		break;
	case 6:
		D.DisplayFileData();
		break;
	case 7:
		AA.PlayMusic();
		break;
	case 8:
		VA.Credits();
		break;
	case 9:
		VA.HelpCommands();
		break;
	case 10:
		VA.Help();
		break;
	}
}
void Functions::Mathematics()
{
	cout << endl << endl;
	//Elements
	char option;
	int x, y;
	int answer = 0;

	cout << "Enter Value of X : ";
	cin >> x;
	cout << "Enter Value of Y : ";
	cin >> y;

	cout << endl;
	cout << "Press :" << endl;
	cout << "\t\" + \" to add" << endl;
	cout << "\t\" - \" to subtract" << endl;
	cout << "\t\" * \" to multiply" << endl;
	cout << "\t\" / \" to divide" << endl;
	cout << "\t:  ";
	cin >> option;

	switch (option)
	{
	case '+':
		answer = x + y;
		break;
	case '-':
		answer = x - y;
		break;
	case '*':
		answer = x * y;
		break;
	case '/':
		answer = x / y;
		break;
	default:
		cout << "Error : Input not recognized" << endl;
	}

	cout << endl << "= " << answer << endl << endl;
}
//Constructors
Functions::Functions()
{}
//Destructors
Functions::~Functions()
{}


//          ###     Relay    ###
//Setters
//Getters
//Functions
void Relay::CreateCall(bool CI, int FI, int EI)
{
	MS.set_CommandIntegrity(CI);
	if (CI)
		F.RunFunction(FI);
	else
		L.DisplayErrorMessage(EI);
}
//Constructors
Relay::Relay()
{
	Relay::Checker = false;
}
//Destructors
Relay::~Relay()
{}

//          ###     Interpreter    ###
//Setters
void Interpreter::set_Input(string I)
{
	Input = I;
}
//Getters
string Interpreter::get_Input()
{
	//TO TEST - RETURNS NULL FOR SOME REASONS
	//cout << Input << endl;
	return Input;
}
//Functions
void Interpreter::SetAllValues(string I)
{
	Input = I;
	InputLength = I.length();
}
void Interpreter::Interpret(string I)
{
	SetAllValues(I);

	/*
	cout << "Input : " << I << endl;
	cout << "Saved Input : " << Input << endl;
	*/

	//Assigning & Distributing
	Digits = new char[InputLength];
	for (int i = 0; i < InputLength; i++)
	{
		Digits[i] = Input[i];
	}

	RecognizeCommand();


	//cout << "First Character : " << Digits[1] << endl;
	//Printing Pigits
	/*
	cout << "Digit by Digit : ";
	for (int i = 0; i < InputLength; i++)
	{
		cout << Digits[i];
	}
	cout << endl;
	*/

	//Maybe CreateLogs(Input);
}
void Interpreter::RecognizeCommand()
{
	//Elements
	int NumberOfSpaces = 0;
	int SpaceIndex;

	if (Digits[1] == ':' || Digits[1] == '?' || Digits[1] == '=')
	{
		FirstDigit = Digits[1];

		//Checking Number of Spaces
		for (int i = 1; i < InputLength; i++)
		{
			if (Digits[i] == ' ')
			{
				NumberOfSpaces++;
				SpaceIndex = i;
			}
		}
		//cout << "Number of Spaces : " << NumberOfSpaces << endl;

		//Dividing Input
		if (NumberOfSpaces == 0)
		{
			string I;
			I = Input.substr(2, InputLength - 2);
			//cout << "Substring : " << I << endl;

			Compare(Digits[1], I);
		}
		else if (NumberOfSpaces == 1)
		{
			string I;
			string F;

			I = Input.substr(2, SpaceIndex - 2);
			F = Input.substr(SpaceIndex + 1, InputLength - SpaceIndex);

			/*
			cout << "First Part : " << I << endl;
			cout << "Second Part : " << F << endl;
			*/

			Compare(Digits[1], I, F);
		}
		else
		{
			L.DisplayErrorMessage(2);
		}

	}
	else
	{
		L.DisplayErrorMessage(2);
	}

	//Calculate Number of spaces from Digit[1] to end
	//Should be 1 or 0
	//if 1 then split string
	//if 0 then send directly to check for recognition
	//Recognize(string) or Recognize(string, string)


	//Check for Digits[1]
	//Split commands
	//Impliment
}
void Interpreter::Compare(char S, string I)
{
	switch (S)
	{
	case ':':
		if (I == "cls")
		{
			R.CreateCall(true, 0, 0);
		}
		else if (I == "exit")
		{
			R.CreateCall(true, 1, 0);
		}
		else if (I == "dms")
		{
			R.CreateCall(true, 2, 0);
		}
		else
		{
			R.CreateCall(false, 0, 1);
		}
		break;
	case '=':
		if (I == "math")
		{
			F.Mathematics();
		}
		break;
	case '?':
		if (I == "help")
		{
			R.CreateCall(true, 10, 0);
		}
		else if (I == "credits")
		{
			R.CreateCall(true, 8, 0);
		}
		else
		{
			R.CreateCall(false, 0, 1);
		}
		break;
	default:
		L.DisplayErrorMessage(2);		//COMMAND NOT RECOGNIZED
	}
}
void Interpreter::Compare(char S, string I, string F)
{
	switch (S)
	{
	case ':':
		if (I == "create" && F == "file")
		{
			R.CreateCall(true, 3, 0);
		}
		else if (I == "edit" && F == "file")
		{
			R.CreateCall(true, 4, 0);
		}
		else if (I == "delete" && F == "file")
		{
			R.CreateCall(true, 5, 0);
		}
		else if (I == "display" && F == "file")
		{
			R.CreateCall(true, 6, 0);
		}
		else if (I == "play" && F == "music")
		{
			R.CreateCall(true, 7, 0);
		}
		else
		{
			R.CreateCall(false, 0, 1);
		}
		break;
	case '=':
		R.CreateCall(false, 0, 1);
		break;
	case '?':
		if (I == "help" && F == "commands")
		{
			R.CreateCall(true, 9, 0);
		}
		else
		{
			R.CreateCall(false, 0, 1);
		}
		break;
	default:
		L.DisplayErrorMessage(2);		//COMMAND NOT RECOGNIZED
	}
}
//Constructors
Interpreter::Interpreter()
{
	Input = "NULL";
	InputLength = 0;
}
//Destructors
Interpreter::~Interpreter()
{
	delete Digits;
}


//          ###     VisualArtifacts     ###
//Setters
//Getters
//Functions
void VisualArtifacts::Introduction()
{
	cout << endl;
	cout << "Welcome to *** OS!" << endl;
	cout << "The pupose of this Operating System is to :" << endl;
	cout << "\t> Emulate Legacy OS around 1980s" << endl;
	cout << "\t> To respect them and understand their functionality" << endl;
	cout << "\t> Impliment OOP concepts with C++ to perform basic tasks" << endl << endl;
	cout << "Enjoy!" << endl << endl;
}
void VisualArtifacts::LineBreak()
{
	cout << endl;
	cout << "------------------------------------------------------------------------------------------------" << endl;
	cout << endl;
}
void VisualArtifacts::LoadingScreen()
{
	cout << endl << endl << endl;
	cout << "\t\tLOADING ... " << endl;
	cout << endl << endl << endl;
}
void VisualArtifacts::LoginScreen()
{
	Introduction();
	LineBreak();
}
string VisualArtifacts::TakeUsername()
{
	string UserName;

	cout << endl << endl;
	cout << "\t*UserName :\t";
	getline(cin, UserName, '.');
	cin.ignore();
	return UserName;
}
string VisualArtifacts::TakePassword()
{
	string Password;

	cout << "\t*Password :\t";
	getline(cin, Password, '.');
	cin.ignore();
	cout << endl << endl << endl;
	return Password;
}
void VisualArtifacts::LogoutScreen()
{
	while (true)
	{
		ClearAll();
		cout << endl << endl << endl;
		cout << "\t\tLOGGED OUT - BYE!" << endl;
		cout << endl << endl << endl;
		system("pause");
	}

}
void VisualArtifacts::Help()
{
	cout << endl << endl;
	cout << "HELP :" << endl;
	cout << "1) Input \"?help commands\" see available commands" << endl;
	cout << "2) Make sure you end every command/input with a delimator \'.\'" << endl;
	cout << "3) Check logs in C:\\Operating_System\\Files\\Logs.txt in case of crashes/errors" << endl;
	cout << endl << endl;
}
void VisualArtifacts::HelpCommands()
{
	cout << endl << endl;
	cout << "Help :" << endl;
	cout << "1) Commands are case sensitive" << endl;
	cout << "2) Make sure you use appropriate initializer i.e" << endl;
	cout << "\t> \":\" for commands" << endl;
	cout << "\t> \"=\" for Basic Mathematics" << endl;
	cout << "\t> \"?\" for help" << endl << endl;
	cout << "Commands :" << endl;
	cout << ":cls" << "\t\t-\t" << "clears screen" << endl;
	cout << ":dms" << "\t\t-\t" << "displays machine state" << endl;
	cout << ":cls" << "\t\t-\t" << "clear screen" << endl;
	cout << ":exit" << "\t\t-\t" << "exit / logout from the OS" << endl;
	cout << ":create file" << "\t-\t" << "creates a file in user directory" << endl;
	cout << ":edit file" << "\t-\t" << "edits a file in user directory" << endl;
	cout << ":delete file" << "\t-\t" << "deletes file data in user directory" << endl;
	cout << ":play music" << "\t-\t" << "plays music" << endl;
	cout << "=math" << "\t\t-\t" << "can make mathematical calculations" << endl;
	cout << "?help" << "\t\t-\t" << "for help" << endl;
	cout << "?help commands" << "\t-\t" << "help with commands" << endl;
	cout << "?credits" << "\t-\t" << "about and credits section" << endl;
	cout << endl << endl;
}
void VisualArtifacts::Credits()
{
	ClearAll();
	cout << endl << endl;
	cout << "*** CREDITS ***" << endl;
	cout << "Syed Mustafa Ahmed   -   BCS183102" << endl;
	cout << endl << endl;
	system("pause");
	ClearAll();
}
void VisualArtifacts::ClearAll()
{
	system("CLS");
}
//Constructors
VisualArtifacts::VisualArtifacts()
{}
//Destructors
VisualArtifacts::~VisualArtifacts()
{}

//          ###     AudioArtifacts     ###
//Setters
//Getters
//Functions
void AudioArtifacts::StartSound()
{
	PlaySound(TEXT("C:\\Operating_System\\Files\\System\\StartSound.wav"), NULL, SND_SYNC);
}
void AudioArtifacts::PlayMusic()
{
	//Elements
	int option;

	cout << endl << endl;
	cout << "Which tune do you wish to play?" << endl;
	cout << "\t1) Bass" << endl;
	cout << "\t2) Beat" << endl;
	cout << "\t3) Pattern" << endl;
	cout << "\t:  ";
	cin >> option;

	switch (option)
	{
	case 1:
		cout << "Playing ..." << endl;
		PlaySound(TEXT("C:\\Operating_System\\Files\\User\\Bass.wav"), NULL, SND_SYNC);
		break;
	case 2:
		cout << "Playing ..." << endl;
		PlaySound(TEXT("C:\\Operating_System\\Files\\User\\Beat.wav"), NULL, SND_SYNC);
		break;
	case 3:
		cout << "Playing ..." << endl;
		PlaySound(TEXT("C:\\Operating_System\\Files\\User\\Pattern.wav"), NULL, SND_SYNC);
		break;
	default:
		cout << "Wrong Choice" << endl;
	}


	cout << endl << endl;
}
//Constructors
AudioArtifacts::AudioArtifacts()
{}
//Destructors
AudioArtifacts::~AudioArtifacts()
{}

//          ###     MachineState     ###
//Setters
void MachineState::set_InputNumber(int IPN)
{
	ReadMachineState();
	InputNumber = IPN;
	RefreshState(Input, AdminAccess);
}
void MachineState::set_Input(string I)
{
	ReadMachineState();
	Input = I;
	RefreshState(Input, AdminAccess);
}
void MachineState::set_AdminAccess(bool AA)
{
	ReadMachineState();
	AdminAccess = AA;
	RefreshState(Input, AdminAccess);
}
void MachineState::set_CommandIntegrity(bool CI)
{
	ReadMachineState();
	CommandIntegrity = CI;
	RefreshState(Input, AdminAccess);
}
void MachineState::set_ErrorIndex(int EI)
{
	ReadMachineState();
	ErrorIndex = EI;
	RefreshState(Input, AdminAccess);
}
void MachineState::set_FunctionIndex(int FI)
{
	ReadMachineState();
	FunctionIndex = FI;
	RefreshState(Input, AdminAccess);
}
void MachineState::set_Exit(bool E)
{
	ReadMachineState();
	Exit = E;
	RefreshState(Input, AdminAccess);
}
//Getters
int MachineState::get_InputNumber()
{
	ReadMachineState();
	return InputNumber;
}
string MachineState::get_Input()
{
	ReadMachineState();
	return Input;
}
bool MachineState::get_AdminAccess()
{
	ReadMachineState();
	return AdminAccess;
}
bool MachineState::get_CommandIntegrity()
{
	ReadMachineState();
	return CommandIntegrity;
}
int MachineState::get_ErrorIndex()
{
	ReadMachineState();
	return ErrorIndex;
}
int MachineState::get_FunctionIndex()
{
	ReadMachineState();
	return FunctionIndex;
}
bool MachineState::get_Exit()
{
	ReadMachineState();
	return Exit;
}
//Functions
void MachineState::ReadMachineState()
{
	Machine.open(D.Machine_State, ios::in | ios::out);
	Machine >> InputNumber;
	Machine >> Input;
	Machine >> AdminAccess;
	Machine >> CommandIntegrity;
	Machine >> ErrorIndex;
	Machine >> FunctionIndex;
	Machine >> Exit;
	Machine.close();
}
void MachineState::DisplayMachineState()
{
	ReadMachineState();

	cout << endl;
	cout << "Input Number : " << InputNumber << endl;
	cout << "Input : " << Input << endl;
	cout << "Admin Access : " << AdminAccess << endl;
	cout << "Command Integrity : " << CommandIntegrity << endl;
	cout << "Error Index : " << ErrorIndex << endl;
	cout << "Function Index : " << FunctionIndex << endl;
	cout << "Exit : " << Exit << endl;

	cout << endl;

}
void MachineState::RefreshState(string I, bool AA)
{
	InputNumber++;
	Input = I;
	AdminAccess = AA;
	Machine.open(D.Machine_State, ios::in | ios::out);

	//Setting Values
	Machine << InputNumber << endl;
	Machine << Input << endl;
	Machine << AdminAccess << endl;
	Machine << CommandIntegrity << endl;
	Machine << ErrorIndex << endl;
	Machine << FunctionIndex << endl;
	Machine << Exit << endl;

	Machine.close();
}
//Constructors
MachineState::MachineState()
{
	InputNumber = 0;
	Input = "NULL";
	AdminAccess = false;
	CommandIntegrity = false;
	ErrorIndex = 0;
	FunctionIndex = 0;
	Exit = false;
}
//Destructors
MachineState::~MachineState()
{}


//          ###     Logs     ###
//Setters
//Getters
//Functions
void Logs::CreateLogs(int IPN, string I, bool AA)
{
	//MS.RefreshState();
	fstream Logs;
	Logs.open(D.Logs, ios::in | ios::out | ios::app);

	Logs << "Input Number : " << IPN << endl;
	Logs << "Input : " << I << endl;
	Logs << "Admin Access : " << AA << endl << endl;

	Logs.close();

}
//Constructors
Logs::Logs()
{}
//Destructors
Logs::~Logs()
{}


//          ###     Data     ###
//Setters
//Getters
//Functions
void Data::CreateFile()
{
	//Taking FileName
	cout << endl;
	cout << "File Name : ";
	cin.ignore();
	getline(cin, FileName, '.');

	//Creating FileName
	string temp;
	temp = Dir.CurrentDirectory + FileName + ".txt";

	cout << endl << "Created file Here : " << temp << endl << endl;

	Files.open(temp, ios::in | ios::out | ios::app);
	Files << "NULL" << endl;
	Files.close();
}
void Data::EditFile()
{
	//Taking FileName
	cout << endl;
	cout << "File Name : ";
	cin.ignore();
	getline(cin, FileName, '.');

	//Creating FileName
	string temp;
	string edit;
	temp = Dir.CurrentDirectory + FileName + ".txt";

	//Taking Option
	int option;
	cout << endl << "Do you want to :" << endl;
	cout << "\t1) Append to file?" << endl;
	cout << "\t2) Rewrite file?" << endl;
	cout << "\t  : ";
	cin >> option;

	cout << endl << "End edit with \" $ \"" << endl;
	switch (option)
	{
	case 1:
		Files.open(temp, ios::in | ios::out | ios::app);
		getline(cin, edit, '$');
		Files << edit;
		Files.close();
		break;
	case 2:
		Files.open(temp, ios::trunc | ios::in | ios::out);
		getline(cin, edit, '$');
		Files << edit;
		Files.close();
		break;
	default:
		cout << endl << "Wrong Input" << endl << endl;
		break;
	}
}
void Data::DeleteFile()
{
	//Taking FileName
	cout << endl;
	cout << "File Name : ";
	cin.ignore();
	getline(cin, FileName, '.');

	//Creating FileName
	string temp;
	temp = Dir.CurrentDirectory + FileName + ".txt";

	//Deleting File
	Files.open(temp, ios::trunc | ios::in | ios::out);
	Files << "NULL";
	cout << endl;
}
void Data::DisplayFileData()
{
	//Taking FileName
	cout << endl;
	cout << "File Name : ";
	cin.ignore();
	getline(cin, FileName, '.');

	//Creating FileName
	string temp;
	string display;
	temp = Dir.CurrentDirectory + FileName + ".txt";

	//Displaying File Data
	Files.open(temp, ios::out | ios::in);

	cout << endl << "Display :" << endl;
	while (!Files.eof())
	{
		Files >> display;
		cout << display << endl;
	}

	cout << endl;
	Files.close();
}
//Constructors
Data::Data()
{}
//Destructors
Data::~Data()
{}


//          ###     Library     ###
//Setters
//Getters
//Functions
void Library::DisplayErrorMessage(int EN)
{
	cout << endl;
	cout << "Error " << EN << " : " << NE[EN] << endl;
	cout << endl;
}
void Library::DisplayMessage(int MN)
{
	cout << endl;
	cout << "Message : " << MN << " : " << NM[MN] << endl;
	cout << endl;
}
//Constructors
Library::Library()
{
	//Error Messages
	NE[0] = "INCORRECT LOGIN USERNAME/PASSWORD";
	NE[1] = "INVALID INPUT (For Help, Enter : ?help)";
	NE[2] = "COMMAND NOT RECOGNIZED";
	NE[3] = "FAILED OPERATION DUE TO SOME REASON (See Logs)";
	NE[4] = "OPERATION BROKE FOR SOME REASON";
	NE[5] = "TASK FAILED";
	NE[6] = "NULL";
	NE[7] = "NULL";
	NE[8] = "NULL";
	NE[9] = "NULL";

	//Messages
	NM[0] = "TASK COMPLETED SUCCESSFULLY";
	NM[1] = "FILE CREATED SUCCESSFULLY";
	NM[2] = "FILE DELETED SUCCESSFULLY";
	NM[3] = "FILE EDITED SUCCESSFULLY";
	NM[4] = "FILE DISPLAYED SUCCESSFULLY";
	NM[5] = "CALCULATED SUCCESSFULLY";
	NM[6] = "NULL";
	NM[7] = "NULL";
	NM[8] = "NULL";
	NM[9] = "NULL";
}
//Destructors
Library::~Library()
{}


//          ###     Encryption     ###
//Setters
//Getters
//Functions
string Encryption::Encrypt(string X)
{
	return X;
}
string Encryption::DeEncrypt(string X)
{
	//Elements
	temp_str = X;
	int length = temp_str.length();
	char c_temp;
	int i_temp;
	char* Digits;
	Digits = new char[length];

	//Assigning Array
	for (int i = 0; i < length; i++)
	{
		Digits[i] = temp_str[i];

		//Decryption
		c_temp = Digits[i];
		i_temp = static_cast<int>(c_temp);
		i_temp = i_temp - 10;
		c_temp = static_cast<char>(i_temp);
		Digits[i] = c_temp;
		temp_str[i] = Digits[i];
	}

	/*
	cout << "TEMP : " << temp_str << endl;
	system("pause");
	*/

	return temp_str;
}
//Constructors
Encryption::Encryption()
{}
//Destructors
Encryption::~Encryption()
{}


//          ###     Security     ###
//Setters
void Security::set_Username(string UN)
{}
void Security::set_Password(string P)
{}
//Getters
//Functions
void Security::ReadData()
{
	S.open(D.Secuirity, ios::in | ios::out);
	S >> Username;
	S >> Password;
	S.close();

	/*
	cout << endl;
	cout << "USERNAME : " << Username << endl;
	cout << "PASSWORD : " << Password << endl;
	cout << endl;
	*/
}
bool Security::Check_UsernamePassword(string UN, string P)
{
	ReadData();
	Username = E.DeEncrypt(Username);
	Password = E.DeEncrypt(Password);


	if (UN == Username || P == Password)
	{
		return true;
	}
	else
	{
		return false;
	}
}
bool Security::Check_UserName(string CUN)
{
	return true;
}
bool Security::Check_Password(string CP)
{
	return true;
}
bool Security::Check_Credentials(string CUN)
{
	return true;
}
//Constructors
Security::Security()
{}
//Destructors
Security::~Security()
{}


//          ###     Directory     ###
//Functions
//Constructors
Directory::Directory()
{
	CurrentDirectory = "C:\\Operating_System\\Files\\User\\";
	Machine_State = "C:\\Operating_System\\Files\\System\\Machine_State.txt";
	Logs = "C:\\Operating_System\\Files\\Logs.txt";
	Encryption = "C:\\Operating_System\\Files\\System\\Encryption.txt";
	Secuirity = "C:\\Operating_System\\Files\\System\\Security.txt";
	User = "C:\\Operating_System\\Files\\User\\---.txt";
	Songs = "C:\\Operating_System\\Files\\User\\Songs";
}
//Destructors
Directory::~Directory()
{}


//          ###     kernal    ###
//Setters
//Getters
//Functions
//Constructors
Kernal::Kernal()
{
	//PP = new _preprocesses;
	//MM = new _memorymanagement;
}
//Destructors
Kernal::~Kernal()
{}


//          ###     OperatingSystem    ###
//Setters
//Getters
//Functions
void OperatingSystem::Start()
{
	//Elements
	string U;
	string P;

	K->MM.VA->LoadingScreen();
	K->MM.AA->StartSound();
	K->MM.VA->ClearAll();


	do
	{
		K->MM.VA->LoginScreen();
		U = K->MM.VA->TakeUsername();
		P = K->MM.VA->TakePassword();

		if (K->MM.S->Check_UsernamePassword(U, P) == true)
		{
			K->MM.MS->set_AdminAccess(true);
		}
		else
		{
			K->MM.MS->set_AdminAccess(false);
		}

		K->MM.VA->ClearAll();

	} while (!K->MM.MS->get_AdminAccess());


	/*
	VA.LoginScreen();
	U = VA.TakeUsername();
	P = VA.TakePassword();
	VA.ClearAll();
	*/
}
void OperatingSystem::Run()
{
	//Elements
	string input;

	do
	{
		//Current Directory
		cout << K->PP.D->CurrentDirectory << "> ";

		//Taking & Sending Input
		getline(cin, input, '.');
		K->MM.I->Interpret(input);

		//Refreshing MachineState Data
		K->MM.MS->RefreshState(input, true);

		//MS.DisplayMachineState();
		K->MM._L->CreateLogs(K->MM.MS->get_InputNumber(), K->MM.MS->get_Input(), K->MM.MS->get_AdminAccess());

	} while (K->MM.MS->get_Exit() == false);
}
void OperatingSystem::End()
{
	K->MM.VA->LogoutScreen();
}
//Constructors
OperatingSystem::OperatingSystem()
{
	K = new Kernal;
}
//Destructors
OperatingSystem::~OperatingSystem()
{}


//          ###     _preprocesses    ###
//Setters
//Getters
//Functions
void _preprocesses::CreateDirectories()
{
	//system("mkdir\abc\def\ghi\jkl");
}
//Constructors
_preprocesses::_preprocesses()
{
	D = new Directory;
}
//Destructors
_preprocesses::~_preprocesses()
{
	delete D;
}


//          ###     memorymanagement    ###
//Setters
//Getters
//Functions
//Constructors
_memorymanagement::_memorymanagement()
{
	I = new Interpreter;
	_L = new Logs;
	S = new Security;
	L = new Library;
	F = new Functions;
	MS = new MachineState;
	VA = new VisualArtifacts;
	AA = new AudioArtifacts;
}
//Destructors
_memorymanagement::~_memorymanagement()
{
	delete I;
	delete _L;
	delete S;
	delete L;
	delete F;
	delete MS;
	delete VA;
	delete AA;
}