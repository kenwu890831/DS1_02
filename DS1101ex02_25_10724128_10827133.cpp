// 10724128 �d�t�� 10827133 �H���
// �i�u��j�V�i�sĶ�ﶵ�j�V�i�sĶ���j�Ŀ�i�sĶ�ɥ[�J�H�U�R�O�j
// �[�J�i-std=c++11�j �A�Y�i�B�@�C

#include <iostream>
#include <string>
#include <cstdlib>
#include <iomanip>
#include <cmath>
#include <new>
#include <cmath>
#include <vector>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>

using namespace std ;
int getNum() ;

void oneGoal ( char**  buffer, int line , int column  ) { // ����@�ӥؼЪ��@�����|
    char printBuffer[line][column] ;
    int acrossCount[line][column] ;
    int record[100] ;
    int loopCount =0 ;
    int recordCount = -1 ;
    bool check = false, moveCheck = false, returnCheck = true, anotherWay = true ;
    int runLine = 0, runColumn = 0 ;
    for ( int i = 0 ; i < column ; i++ ) { // �H�쥻���g�cbuffer(�Ҧ����L����m)���ҪO�إߥt�@�Ӱg�cprintBuffer(����ؼЪ��@�����|)
        for ( int j = 0 ; j < line ; j++ ) {
            printBuffer[j][i] = buffer[j][i] ;
            acrossCount[j][i] = 0 ;
    	}
    }
    for ( int i = 0 ; i < 100 ; i++ ) record[i] = 0 ; // �Nrecord[]��l��
    if ( buffer[runLine][runColumn] == 'E' ) printBuffer[runLine][runColumn] = 'V' ;
	// �p�Gbuffer�{�b��m�OE(�Ů�)�A�hprintBuffer�{�b��m�Хܬ�V(���L)

    while ( check == false && anotherWay) {
        loopCount ++ ;
        if ( anotherWay ) { // ��F�ؼ�G
            if ( printBuffer[runLine+1][runColumn] == 'G' ) { // �k��
                check = true ;
                moveCheck = true ;
            }
            if ( printBuffer[runLine][runColumn+1] == 'G' ) { // �U��
                check = true ;
                moveCheck = true ;
            }
            if ( printBuffer[runLine-1][runColumn] == 'G' ) { // ����
                check = true ;
                moveCheck = true ;
            }
            if ( printBuffer[runLine][runColumn-1] == 'G' ) { // �W��
                check = true ;
                moveCheck = true ;
            }
        }

        if ( !check ) { // �p�G�٥��F��ؼ�G

        	if ( runLine < line ) {
           		if ( printBuffer[runLine+1][runColumn] == 'E' ) { // �Ӧ�m�OE
                	printBuffer[runLine+1][runColumn] = 'V' ;  // �Хܬ�V
                	acrossCount[runLine+1][runColumn] ++ ;
                	runLine++ ;
                	moveCheck = true ;
                	recordCount++ ;
                	record[recordCount] = 1 ; // �������|�A�H�K�^�Y
            	}
        	} // right

        	if ( (runColumn < column )  && ( !moveCheck ) ){

            	if ( printBuffer[runLine][runColumn+1] == 'E' ) {
                	printBuffer[runLine][runColumn+1] = 'V' ;
                	acrossCount[runLine][runColumn+1]++ ;
                	runColumn++ ;
                	moveCheck = true ;
                	recordCount++ ;
                	record[recordCount] = 2 ;
            	}
        	} // down

        	if ( runLine > 0 && ( !moveCheck ) ) {

            	if ( printBuffer[runLine-1][runColumn] == 'E' ) {
                	printBuffer[runLine-1][runColumn] = 'V' ;
                	acrossCount[runLine-1][runColumn]++ ;
                	runLine-- ;
                	moveCheck = true ;
                	recordCount++ ;
                	record[recordCount] = 3 ;
            	}

        	} // lift

        	if ( runColumn > 0 && ( !moveCheck ) ) {

            	if ( printBuffer[runLine][runColumn-1] == 'E' ) {
                	printBuffer[runLine][runColumn-1] = 'V' ;
                	acrossCount[runLine][runColumn-1]++ ;
                	runColumn-- ;
                	moveCheck = true ;
                	recordCount++ ;
                	record[recordCount] = 4 ;
            	}

        	} // up
    	} //if

    	if ( moveCheck == false && check == false ) { // �p�G�O����(�S��E�]�S��G)
       		while ( returnCheck ) {
                    returnCheck = false ;
               for ( int i = 0 ; i < 100 ; i++ ) {
                   if ( record[i] != 0)
                       returnCheck = true ;
               } //�ˬd�O�_�٦�����
        	    if ( record[recordCount] == 1 ) { // ���^
            	    record[recordCount] = 0 ;
                	runLine-- ;
                	recordCount-- ;
            	}
            	else if ( record[recordCount] == 2 ) { // ���^
                	record[recordCount] = 0 ;
                	runColumn-- ;
                	recordCount-- ;
            	}
            	else if ( record[recordCount] == 3 ) { // ���^
                	record[recordCount] = 0 ;
                	runLine++ ;
                	recordCount-- ;
            	}
            	else if ( record[recordCount] == 4 ) { // ���^
                	record[recordCount] = 0 ;
                	runColumn++ ;
                	recordCount-- ;
            	}

    			if ( runLine < line ) {
            		if ( printBuffer[runLine+1][runColumn] == 'E' ) {
                		moveCheck = true ;
                		returnCheck = false ;
            		}
        		} // right

        		if ( (runColumn < column )  && ( !moveCheck ) ){
           			if ( printBuffer[runLine][runColumn+1] == 'E' ) {
                		moveCheck = true ;
                		returnCheck = false ;
            		}
        		} // down

        		if ( runLine > 0 && (!moveCheck )) {
            		if ( printBuffer[runLine-1][runColumn] == 'E' ) {
                		moveCheck = true ;
                		returnCheck = false ;
            		}

        		} // lift

        		if ( runColumn > 0 && (!moveCheck )) {
            		if ( printBuffer[runLine][runColumn-1] == 'E' ) {
                		moveCheck = true ;
                		returnCheck = false ;
            		}

        		} // up

        	} // while

    	} // if

        returnCheck = true ;
        moveCheck = false ;
        anotherWay = false ;
        
        for ( int i = 0 ; i < column ; i++ ) { //�ˬd�O�_�٦��|�����L�����|
        	for ( int j = 0 ; j < line ; j++ ) {
            	if ( printBuffer[j][i] == 'E' )
              		anotherWay = true ;
         	}
        } // �ˬd�O�_�٦��S���L����


        if ( loopCount >( line *column*4) )
            anotherWay = false ;

    } // while


    runColumn = 0;
    runLine = 0 ;
    buffer[0][0] = 'R' ;
    for ( int i = 0 ; i < 100 ; i++ ) { // �إߥi��F�Ъ����|buffer
        if ( record[i] == 0)
            i = 100 ;
        else if ( record[i] == 1 ){
            runLine++ ;
            buffer[runLine][runColumn]  = 'R' ;
        }
        else if ( record[i] == 2 ){
            runColumn++ ;
            buffer[runLine][runColumn]  = 'R' ;
        }
        else if ( record[i] == 3 ){
            runLine-- ;
            buffer[runLine][runColumn]  = 'R' ;
        }
        else if ( record[i] == 4 ){
            runColumn-- ;
            buffer[runLine][runColumn]  = 'R' ;
        }

    }

    cout << endl ;
    for ( int i = 0 ; i < column ; i++ ) { // ��X�Ĥ@�ӯx�}(�HV��ܩҦ����L����m)
        for ( int j = 0 ; j < line ; j++ ) {
            cout << printBuffer[j][i] ;
        }
        cout << endl ;
    }

    cout << endl ;
    if ( check == true ) {
    for ( int i = 0 ; i < column ; i++ ) { // ��X�ĤG�ӯx�}(�HR��ܨ���ؼЪ��@�����|)
        for ( int j = 0 ; j < line ; j++ ) {
            cout << buffer[j][i] ;
        }
        cout << endl ;
    }
    }


} // oneGoal()

void NGoal ( char**  buffer, int line , int column  ) { // �g�L�h�ӥؼЪ��@�����|
    char printBuffer[line][column] ;
    char printBuffer2[line][column] ;
    int acrossCount[line][column] ;
    int record[100] ;
    int recordCount = -1, loopCount = 0 ;
    bool  moveCheck = false, returnCheck = true, anotherWay = true ;
    int check = 0, maxGoal = 0 ;
    int runLine = 0, runColumn = 0 ;

    for ( int i = 0 ; i < column ; i++ ) {
        for ( int j = 0 ; j < line ; j++ ) {
            printBuffer[j][i] = buffer[j][i] ;
            printBuffer2[j][i] = buffer[j][i] ;
            if ( printBuffer[j][i] == 'G' )
                maxGoal++ ;
            acrossCount[j][i] = 0 ;
        }
    } // copy the buffer and reset acrossCount array

    cout << "Number of G (goals): "  ;
    int numOfGoal = getNum() ;
    if ( numOfGoal > maxGoal )
        cout << "goals  not enought!!"<< endl ;
    else {
    int recordGoal[numOfGoal][2] ;
    int goalCount = 0 ;
    for ( int i = 0 ; i < 100 ; i++ )
        record[i] = 0 ; // reset record

    if ( printBuffer[runLine][runColumn] == 'E' )
        printBuffer[runLine][runColumn] = 'V' ;
    bool alreadyHaveG = false ;
    while ( check < numOfGoal && anotherWay ) {
        loopCount ++ ;
        if ( anotherWay) {
            if ( printBuffer[runLine+1][runColumn] == 'G' && runLine < line) {
                for ( int i = 0 ; i < numOfGoal ; i++ ) {
                    if ( recordGoal[i][0] == (runLine +1) && recordGoal[i][1] == runColumn )
                        alreadyHaveG = true ;
                }
                if ( !alreadyHaveG ) {
                  check ++ ;
                  recordGoal[goalCount][0] = runLine+1 ;
                  recordGoal[goalCount][1] =runColumn ;
                  goalCount++ ;

                }

            }
            if ( printBuffer[runLine][runColumn+1] == 'G' && runColumn < column) {
                for ( int i = 0 ; i < numOfGoal ; i++ ) {
                    if ( recordGoal[i][0] == runLine && recordGoal[i][1] == (runColumn+1) )
                        alreadyHaveG = true ;
                }
            	if ( !alreadyHaveG ) {
               		check ++ ;
                	recordGoal[goalCount][0] = runLine ;
                	recordGoal[goalCount][1] =runColumn +1;
                	goalCount++ ;
            	}

            }
            if ( printBuffer[runLine-1][runColumn] == 'G' && runLine > 0) {
                for ( int i = 0 ; i < numOfGoal ; i++ ) {
                    if ( recordGoal[i][0] == (runLine -1 )&& recordGoal[i][1] == runColumn )
                        alreadyHaveG = true ;
                }
            	if ( !alreadyHaveG ) {
                	check ++ ;
                	recordGoal[goalCount][0] = runLine -1;
                	recordGoal[goalCount][1] =runColumn ;
                	goalCount++ ;
            	}
            }
            if ( printBuffer[runLine][runColumn-1] == 'G'&& runColumn > 0 ) {
                for ( int i = 0 ; i < numOfGoal ; i++ ) {
                    if ( recordGoal[i][0] == runLine && recordGoal[i][1] == ( runColumn -1 ) )
                        alreadyHaveG = true ;
                }
                if ( !alreadyHaveG ) {
                	check ++ ;
                	recordGoal[goalCount][0] = runLine ;
                	recordGoal[goalCount][1] =runColumn -1;
                	goalCount++ ;
                }
            }
        }
        if ( !moveCheck ) {

        	if ( runLine < line ) {
            	if ( printBuffer[runLine+1][runColumn] == 'E' || printBuffer[runLine+1][runColumn] == 'G' ) {
                	printBuffer[runLine+1][runColumn] = 'V' ;
                	acrossCount[runLine+1][runColumn] ++ ;
                	runLine++ ;
                	moveCheck = true ;
                	recordCount++ ;
                	record[recordCount] = 1 ;
            	}
        	} // right

        	if ( (runColumn < column )  && (!moveCheck ) ){

            	if ( printBuffer[runLine][runColumn+1] == 'E' || printBuffer[runLine][runColumn+1] == 'G') {
                	printBuffer[runLine][runColumn+1] = 'V' ;
                	acrossCount[runLine][runColumn+1]++ ;
                	runColumn++ ;
                	moveCheck = true ;
                	recordCount++ ;
                	record[recordCount] = 2 ;
            	}
        	} // down

        	if ( runLine > 0 && (!moveCheck )) {

            	if ( printBuffer[runLine-1][runColumn] == 'E' || printBuffer[runLine-1][runColumn] == 'G' ) {
                	printBuffer[runLine-1][runColumn] = 'V' ;
                	acrossCount[runLine-1][runColumn]++ ;
                	runLine-- ;
                	moveCheck = true ;
                	recordCount++ ;
                	record[recordCount] = 3 ;
            	}

        	} // left

        	if ( runColumn > 0 && (!moveCheck )) {

            	if ( printBuffer[runLine][runColumn-1] == 'E' || printBuffer[runLine][runColumn-1] == 'G' ) {
                	printBuffer[runLine][runColumn-1] = 'V' ;
                	acrossCount[runLine][runColumn-1]++ ;
                	runColumn-- ;
                	moveCheck = true ;
                	recordCount++ ;
                	record[recordCount] = 4 ;
            	}

        	} // up

    	} //if

    	if ( moveCheck == false ) {
            while ( returnCheck ) {
                returnCheck = false ;
               for ( int i = 0 ; i < 100 ; i++ ) {
                   if ( record[i] != 0)
                       returnCheck = true ;
               }
                if ( record[recordCount] == 1 ) {
                    record[recordCount] = 0 ;
                    runLine-- ;
                    recordCount-- ;
                }
                else if ( record[recordCount] == 2 ) {
                    record[recordCount] = 0 ;
                    runColumn-- ;
                    recordCount-- ;
                }
                else if ( record[recordCount] == 3 ) {
                    record[recordCount] = 0 ;
                    runLine++ ;
                    recordCount-- ;
                }
                else if ( record[recordCount] == 4 ) {
                    record[recordCount] = 0 ;
                    runColumn++ ;
                    recordCount-- ;
                }

        		if ( runLine < line ) {
            		if ( printBuffer[runLine+1][runColumn] == 'E' ) {
                		moveCheck = true ;
                		returnCheck = false ;
            		}
        		} // right

        		if ( (runColumn < column )  && (!moveCheck ) ){
            		if ( printBuffer[runLine][runColumn+1] == 'E' ) {
                		moveCheck = true ;
                		returnCheck = false ;
            		}
        		} // down

        		if ( runLine > 0 && (!moveCheck )) {
            		if ( printBuffer[runLine-1][runColumn] == 'E' ) {
                		moveCheck = true ;
                		returnCheck = false ;
            		}

        		} // lift

        		if ( runColumn > 0 && (!moveCheck )) {
            		if ( printBuffer[runLine][runColumn-1] == 'E' ) {
                		moveCheck = true ;
                		returnCheck = false ;
            		}

        		} // up

        	}

    	}

       	alreadyHaveG = false ;
        returnCheck = true ;
        moveCheck = false ;
        anotherWay = false ;
        for ( int i = 0 ; i < column ; i++ ) { //�ˬd�O�_�٦��|�����L�����|
        for ( int j = 0 ; j < line ; j++ ) {
            if ( printBuffer[j][i] == 'E' )
              anotherWay = true ;
        if ( loopCount > ( line* column * 4) )
            anotherWay = false ;
         }
        }

    }

    runColumn = 0;
    runLine = 0 ;
    printBuffer2[0][0] = 'R' ;
    for ( int i = 0 ; i < 100 ; i++ ) {
        if ( record[i] == 0)
            i = 100 ;
        else if ( record[i] == 1 ){
            runLine++ ;
            if ( printBuffer2[runLine][runColumn] != 'G' ) printBuffer2[runLine][runColumn]  = 'R' ;
        }
        else if ( record[i] == 2 ){
            runColumn++ ;
            if ( printBuffer2[runLine][runColumn] != 'G' ) printBuffer2[runLine][runColumn]  = 'R' ;
        }
        else if ( record[i] == 3 ){
            runLine-- ;
            if ( printBuffer2[runLine][runColumn] != 'G' ) printBuffer2[runLine][runColumn]  = 'R' ;
        }
        else if ( record[i] == 4 ){
            runColumn-- ;
            if ( printBuffer2[runLine][runColumn] != 'G' ) printBuffer2[runLine][runColumn]  = 'R' ;
        }

    }

    cout << endl ;

    for ( int i = 0 ; i < goalCount ; i++ ) {
        printBuffer[recordGoal[i][0]][recordGoal[i][1]]  = 'G' ;
    }
    for ( int i = 0 ; i < column ; i++ ) {
        for ( int j = 0 ; j < line ; j++ ) {
            cout << printBuffer[j][i] ;
        }
        cout << endl ;
    }

    cout << endl ;
    if ( check == numOfGoal ) {
    for ( int i = 0 ; i < column ; i++ ) { // ��X�ĤG�ӯx�}(�HR��ܨ���ؼЪ��@�����|)
        for ( int j = 0 ; j < line ; j++ ) {
            cout << printBuffer2 [j][i] ;
        }
        cout << endl ;
    }
    }

    } // else

} // NGoal()

void readTheFile( int command ) { // Ū��
    int input = 1 , line = 0, column = 0;
    string lineSet;
    bool check = false ;
    char inputChar ;
  	cout << endl << "Input a file number (e.g., 201, 202, ...):  " ;
  	input = getNum() ; // Ū�J�ɦW
  	string inputString = to_string( input ) ; // �Nint�ɦW�নstring
  	fstream theFile;
  	theFile.open( "input"+inputString+".txt" ); // �}�ҫ��w�ɮ�

  	if ( theFile.is_open() ) { // �p�G�����}�ɮ�
    	getline( theFile, lineSet ) ; // Ū�J�Ĥ@�檺��b�e&�a�b��
    	for ( int i = 0 ; i < lineSet.length() ; i++ ) {
    		if ( !check ) { // �Ĥ@�ӬO��b�e (��line|)
        		if ( lineSet[i] >= '0' && lineSet[i] <= '9') {
           		 	line *= 10 ;
          			line = line + (lineSet[i] - '0') ;
        		}
        		else check = true ;

    		} // if
       		else { // �ĤG�ӬO�a�b�� (�Ccolumn--)
        		if ( lineSet[i] >= '0' && lineSet[i] <= '9') {
        			column *= 10 ;
        			column = column + (lineSet[i] - '0') ;
           		}
       		} // else
    	}

    	char buffer[line][column] ; // �إ߰g�c�j�p
   		char* forFunction[line] ; // ??

    	for( int j = 0; j < line; ++j ) {
        	forFunction[j] = buffer[j] ;
        	for(int i = 0; i < column; ++i) {
            	forFunction[j][i] = 1 ;
        	}
    	}

    	int lineCount = 0 , columnCount = 0 ;
    	while ( theFile.get( inputChar ) ) {
        	if ( inputChar == '\n'){
            	columnCount++ ;
            	lineCount = 0 ;
        	} // �p�⦳�h�֦C
        	else {
            	buffer[lineCount][columnCount] = inputChar ;
            	lineCount++ ;
        	} // ����w����J�Ӧ�m
    	} // ��Ū�J����Ʃ�i�g�c(buffer[])

    	theFile.close();


    	if ( command == 1 ) { // ���Ȥ@
        	oneGoal( forFunction, line, column ) ; // ����@�ӥؼЪ��@�����|
    	}
    	else if ( command == 2 ) { // ���ȤG
        	NGoal( forFunction, line, column ) ; // �g�L�h�ӥؼЪ��@�����|
    	}

    } // if
    else {
        cout << "input" +inputString + ".txt does not exist!" << endl ;
    }

} // readTheFile


int main(void) {
  int command = 0 ; // user command
  do {
  	int M = 1,M2 ;  // last index of Fibonacci Series

  	cout << endl << "*** Path Finding ***" ;
  	cout << endl << "* 0. Quit          *" ;
  	cout << endl << "* 1. One goal      *" ;
  	cout << endl << "* 2. More goals    *" ;
  	cout << endl << "********************" ;
  	cout << endl << "Input a command( 0, 1, 2 ) :" ;
  	cin >> command ; // get the command
  	if ( command == 1 || command == 2 ) {
        readTheFile( command ); // Ū��( ���K���O����1,2 )
  	}
  	else {
        cout << "Input the wrong command!!" << endl ;
  	}

  } while ( command != 0 ) ;

  system( "pause") ; // pause the display
  return 0 ;
} // main()

int getNum() {
	int temp ;
	string inputS ;
	bool isNum ;

	do {
		cin >> inputS ;
		isNum = true ;
		for ( int i = 0; ( i < inputS.length()) && ( isNum ) ; i++ )
		  if( ( inputS[i] > '9') || ( inputS[i] < '0') )
		    isNum = false ;
		if ( !isNum )
		  continue ;
		temp = strtoul( inputS.c_str(), NULL, 10 ) ;

		  break ;


	} while( true );// end do-while

	return temp ;
} // getNum()
