//Header File
#include <iostream>
#include <string>
//#include <ctime>
#include <fstream>
#include<Windows.h>
#include<MMSystem.h>
using namespace std;

//Forward Declaration
class OperatingSystem;
class Kernal;	
class _preprocesses;
class _memorymanagement;
class Security;
class Encryption;
class Directory;
class Interpreter;
class MachineState;
class Logs;
class Library;
class Data;
class Relay;
class Functions;
class VisualArtifacts;
class AudioArtifacts;

//Classes
class Directory
{
public:
	string CurrentDirectory;
	string User;
	string Machine_State;
	string Logs;
	string Encryption;
	string Secuirity;
	string Songs;
	//Setters
	//Getters
	//Functions
	//Constructors
	Directory();
	//Destructors
	~Directory();
};


//May or not end up as part of Interpreter. Or be inherited into it
class Library
{
protected:
	int static const NumberOfErrors = 10;
	string NE[NumberOfErrors];
	int static const NumberOfMessages = 10;
	string NM[NumberOfMessages];
public:
	//Setters
	//Getters
	//Functions
	void DisplayMessage(int);
	void DisplayErrorMessage(int);
	//Constructors
	Library();
	//Destructors
	~Library();
};

class Logs
{
protected:
	Directory D;
public:
	//Setters
	//Getters
	//Functions
	void CreateLogs(int, string, bool);
	//Constructors
	Logs();
	//Destructors
	~Logs();
};

class Data
{
protected:
	Directory Dir;
	fstream Files;
	string FileName;
public:
	//Setters
	//Getters
	//Functions
	void CreateFile();
	void EditFile();
	void DisplayFileData();
	void DeleteFile();
	//Constructors
	Data();
	//Destructors
	~Data();
};

class VisualArtifacts
{
protected:
public:
	//Setters
	//Getters
	//Functions
	void Introduction();
	void LineBreak();
	void LoadingScreen();
	void LoginScreen();
	string TakeUsername();
	string TakePassword();
	void LogoutScreen();
	void Help();
	void HelpCommands();
	void Credits();
	void ClearAll();
	//Constructors
	VisualArtifacts();
	//Destructors
	~VisualArtifacts();
};

class AudioArtifacts
{
protected:
	Directory D;
	//Files
public:
	//Setters
	//Getters
	//Functions
	void StartSound();
	void PlayMusic();
	//void LoginSound();
	//void ErrorSound();
	//void SuccessSound();
	//Constructors
	AudioArtifacts();
	//Destructors
	~AudioArtifacts();
};

/*
#include <iostream>

//these two libraries to be included.
#include<Windows.h>
#include<MMSystem.h>


using namespace std;

void main()
{
	cout << "Enjoy music\n";
	PlaySound(TEXT("file.wav"), NULL, SND_SYNC); 	//sound must be of ".wav" extension and music file should have to be in your project folder
	cout << "hope you enjoyed :) \n";


	system("pause");
}

*/

class MachineState
{
protected:
	fstream Machine;
	Directory D;
	int InputNumber;
	string Input;
	bool AdminAccess;
	bool CommandIntegrity;
	int ErrorIndex;
	int FunctionIndex;
	bool Exit;
public:
	//Setters
	void set_InputNumber(int);
	void set_Input(string);
	void set_AdminAccess(bool);
	void set_CommandIntegrity(bool);
	void set_ErrorIndex(int);
	void set_FunctionIndex(int);
	void set_Exit(bool);
	//Getters
	int get_InputNumber();
	string get_Input();
	bool get_AdminAccess();
	bool get_CommandIntegrity();
	int get_ErrorIndex();
	int get_FunctionIndex();
	bool get_Exit();
	//Functions
	void ReadMachineState();
	void DisplayMachineState();
	void RefreshState(string, bool);
	//Constructors
	MachineState();
	//Destructors
	~MachineState();
};


class Encryption
{
protected:
	string temp_str;
	string in;
public:
	//Setters
	//Getters
	//Functions
	string Encrypt(string);
	string DeEncrypt(string);
	//Constructors
	Encryption();
	//Destructors
	~Encryption();
};

class Security
{
protected:
	fstream S;
	MachineState MS;
	Encryption E;
	Directory D;
	string Username;
	string Password;
public:
	//Setters
	void set_Username(string);
	void set_Password(string);
	//Getters
	//Functions
	void ReadData();
	bool Check_UsernamePassword(string, string);
	bool Check_UserName(string);
	bool Check_Password(string);
	bool Check_Credentials(string);
	//Constructors
	Security();
	//Destructors
	~Security();
};

class Functions
{
protected:
	VisualArtifacts VA;
	AudioArtifacts AA;
	MachineState MS;
	Data D;
public:
	//Setters
	//Getters
	//Functions
	void RunFunction(int);
	void Mathematics();
	//Constructors
	Functions();
	//Destructors
	~Functions();
};

class Relay
{
protected:
	Library L;
	Functions F;
	MachineState MS;
	bool Checker;
	//Data D;
public:
	//Setters
	//Getters
	//Functions
	void CreateCall(bool, int, int);
	//Constructors
	Relay();
	//Destructors
	~Relay();
};

class Interpreter
{
protected:
	Library L;
	Relay R;
	Functions F;
	string Input;
	char* Digits;
	int InputLength;
	char FirstDigit;
public:
	//Setters
	void set_Input(string);
	//Getters
	string get_Input();
	//Functions
	void SetAllValues(string);
	void Interpret(string);
	void RecognizeCommand();
	void Compare(char, string);
	void Compare(char, string, string);
	//Constructors
	Interpreter();
	//Destructors
	~Interpreter();
};

class _preprocesses				//Will create empty folder structure and files
{
public:
	Directory *D;
	//Setters
	//Getters
	//Functions
	void CreateDirectories();
	//Constructors
	_preprocesses();
	//Destructors
	~_preprocesses();
};

class _memorymanagement		//Creation of necessary dynamic objects and deletion
{
public:
	Interpreter *I;
	Logs *_L;
	Security *S;
	Library *L;
	Functions *F;
	MachineState *MS;
	VisualArtifacts *VA;
	AudioArtifacts *AA;
	//Setters
	//Getters
	//Functions
	//Constructors
	_memorymanagement();
	//Destructors
	~_memorymanagement();
};


class Kernal
{
public:
	_preprocesses PP;
	_memorymanagement MM;
	//Setters
	//Getters
	//Functions
	//Constructors
	Kernal();
	//Destructors
	~Kernal();
};

class OperatingSystem
{
public:
	Kernal *K;
	//Setters
	//Getters
	//Functions
	void Start();
	void Run();
	void End();
	//Constructors
	OperatingSystem();
	//Destructors
	~OperatingSystem();
};