int GetValues(int forKey) { 
using namespace GS_Structs;

	GSharpStructs::ToneTable Core;
    FileObj::CommandLine::LaunchApp AddApp;

			int index = 1;
			int* point = &index;

			cout << "Values in Key:" << endl;

			string pathmaker = "C:\\Users\\sintax\\masm\\solo\\gsharp\\valsheet\\values.txt";
			string* opener = &pathmaker;

			if (forKey >= -4 && forKey <= 7) {
				ofstream ValueSheet(*opener, ios_base::out);

				if (ValueSheet.is_open()) {
					// six rows of 21 -- make 5 sets of variables that point to x,y; add 21; and substitute to each row
					unsigned short int cOne = 1;
					unsigned short int cTwo = 22;
					unsigned short int cThree = 43;
					unsigned short int cFour = 64;
					unsigned short int cFive = 85;
					unsigned short int cSix = 106;

					do {
						for (int x = 0; x < 1; ++x) {
							for (int y = 0; y < 21; ++y) {
								GSharpStructs::ToneTable gs;
								int a = x;
								int b = y + 21;
								int c = x;
								int d = y + 42;
								int e = x;
								int f = y + 63;
								int g = x;
								int h = y + 84;
								int i = x;
								int j = y + 105;
								ValueSheet << "tone[" << cOne << "]  " << &gs.fretBoard[x][y] << "  tone[" << cTwo << "]  " << &gs.fretBoard[a][b] << "  tone[" << cThree << "]  " << \
									& gs.fretBoard[c][d] << "  tone[" << cFour << "]  " << &gs.fretBoard[e][f] << "  tone[" << cFive << "]  " << &gs.fretBoard[g][h] << "  tone[" << cSix << "]  " \
									<< &gs.fretBoard[i][j] << endl;

								++cOne;
								++cTwo;
								++cThree;
								++cFour;
								++cFive;
								++cSix;
							}
						}
					} while (cOne < 21);

					do {
						for (int x = 0; x < 6; ++x) {
							for (int y = 0; y < 21; ++y) {
								int* toKey = &forKey;
								int values = { Core.fretBoard[x][y] + (*toKey) };
								int* valuePoint = &values;
								ValueSheet << "tone[" << *point << "]   \t" << *valuePoint <<                                                       endl;
								++index;
							}
						}
					} while (index < 126);
					ValueSheet.close();
				}
				else
					cout << "Failed" << endl;

				ifstream SameSheet(*opener, ios_base::in);

				if (SameSheet.is_open()) {
					string sheetContent;
					while (SameSheet.good()) {
						getline(SameSheet, sheetContent);
						cout << sheetContent << endl;
					}
					SameSheet.close();
				}
				else
					cout << "File open failed" << endl;
			}
			else {
				cout << "Invalid entry." << endl;
				cout << "GetValues function" << endl;
				cout << "Enter Key Value (-4 through 7): ";
				int repeat = 0;
				cin >> repeat;
    
				AddApp.GetValues(repeat);
			}

			return 0;
}