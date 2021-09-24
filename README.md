
[<img src="/regex.jpeg" width="320" height="180">]


# Project Summary 

<hr>

- [SourceCode](#sourcecode)
    - [Main](#main)
    - [Threading](#threading)
    - [Parser](#parser)
- [Build](#build)
    - [Executable](#exe)
    - [Test File](#testtext)

<a name="sourcecode"></a>
## 1. Source Code
<a name="main"></a>

### 1.1 Main.cpp
Main.cpp is the first point of contact when the executable is ran:

* Serves as the main thread.
 
* Asks user for the input of the file that will get processed.
   
* Starts a separate thread that opens and processes the file.
   
* Displays valid matches (if the file was provided and if there are valid matches)


<a name="threading"></a>
### 1.2 Threading.cpp
This class is called serves as a sepparate thread

* Opens the file with the path provided by the user in the main thread.

* Stores the entries from the file in a new variable and sends it to Parser function for processing


<a name="parser"></a>
### 1.3 Parser.cpp

Is a processing class that uses RegEx to validate the file entries

 * Accepts input from sent from threading.cpp

 * Validates the entries using ReGex patterns


 <a name="build"></a>
## 2. Build

<a name="exe"></a>

### 2.1 Executable

* Built executable ready for testing text files
	> Accepts entire file path or filename in the same folder as the executable

<a name="testtext"></a>

### 2.2 test.txt

* Stores entries that will be tested using RegEx patterns

