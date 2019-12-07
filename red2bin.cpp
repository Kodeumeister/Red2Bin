/*
	Name: Red2Bin (Readable To Binary)
	Author: William Kimberley (Kodeumeister)
	Date Modified: 2019-12-07
	Date Created: 2019-12-07
*/

// C++ Libs
#include <iostream>
#include <fstream>
#include <string>
// C Libs
#include <cstdlib>
// Author's Libs
// NONE!!!

// I usually don't use the "using namespace" statement but
// I thought I should since there'll be no namespace
// clashes and it makes the code easier to read.
using namespace std;

int main(int argc, char* argv[]) {
	if (argc < 2) {
		cout << "\nUsage: red2bin <file>\n";
	} else if (argc > 2) {
		cout << "\nToo many arguments.\n";
	} else {
		// Initialising objects;
		fstream in, out;
		
		// Setting exceptions.
		in.exceptions(fstream::failbit);
		out.exceptions(fstream::failbit);
		
		// Settting up output stuff.
		string output;
		size_t found = string::npos;
		char byte = 0x00;
		size_t pos = 0x00;
		
		// Converting filename to string.
		string filename(argv[1]);
		
		try {
			// Opening files.
			in.open(filename, ios::in);
			
			// Creating "binary" file.
			out.open(filename + ".bin", ios::binary | ios::out);
			
			// Converting text to binary.
			do {
				in >> output;
				found = output.find(";");
				output.erase(4,4);
				byte = stoi(output, &pos, 16);
				out.write(&byte, sizeof(byte));
			} while (found == string::npos);
			
			cout << "\nSuccessfully reconstructed binary.\n";
			
		} catch (const fstream::failure& e) {
			// Showing error.
			cerr << "\nFailed to read and write to files.\n";
			
			// Making sure files get closed.
			if (in.is_open()) {
				in.close();
			}
			if (out.is_open()) {
				out.close();
			}
			
			// Returning that the program has failed.
			return EXIT_FAILURE;
		}
		
		// Closing files.
		in.close();
		out.close();
	}
	
	return EXIT_SUCCESS;
}