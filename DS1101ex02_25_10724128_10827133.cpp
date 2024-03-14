// 10724128 吳宇哲 10827133 鄧梓岑
// 【工具】–【編譯選項】–【編譯器】勾選【編譯時加入以下命令】
// 加入【-std=c++11】 ，即可運作。

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

void oneGoal ( char**  buffer, int line , int column  ) { // 走到一個目標的一條路徑
    char printBuffer[line][column] ;
    int acrossCount[line][column] ;
    int record[100] ;
    int loopCount =0 ;
    int recordCount = -1 ;
    bool check = false, moveCheck = false, returnCheck = true, anotherWay = true ;
    int runLine = 0, runColumn = 0 ;
    for ( int i = 0 ; i < column ; i++ ) { // 以原本的迷宮buffer(所有走過的位置)為模板建立另一個迷宮printBuffer(走到目標的一條路徑)
        for ( int j = 0 ; j < line ; j++ ) {
            printBuffer[j][i] = buffer[j][i] ;
            acrossCount[j][i] = 0 ;
    	}
    }
    for ( int i = 0 ; i < 100 ; i++ ) record[i] = 0 ; // 將record[]初始化
    if ( buffer[runLine][runColumn] == 'E' ) printBuffer[runLine][runColumn] = 'V' ;
	// 如果buffer現在位置是E(空格)，則printBuffer現在位置標示為V(走過)

    while ( check == false && anotherWay) {
        loopCount ++ ;
        if ( anotherWay ) { // 到達目標G
            if ( printBuffer[runLine+1][runColumn] == 'G' ) { // 右方
                check = true ;
                moveCheck = true ;
            }
            if ( printBuffer[runLine][runColumn+1] == 'G' ) { // 下方
                check = true ;
                moveCheck = true ;
            }
            if ( printBuffer[runLine-1][runColumn] == 'G' ) { // 左方
                check = true ;
                moveCheck = true ;
            }
            if ( printBuffer[runLine][runColumn-1] == 'G' ) { // 上方
                check = true ;
                moveCheck = true ;
            }
        }

        if ( !check ) { // 如果還未達到目標G

        	if ( runLine < line ) {
           		if ( printBuffer[runLine+1][runColumn] == 'E' ) { // 該位置是E
                	printBuffer[runLine+1][runColumn] = 'V' ;  // 標示為V
                	acrossCount[runLine+1][runColumn] ++ ;
                	runLine++ ;
                	moveCheck = true ;
                	recordCount++ ;
                	record[recordCount] = 1 ; // 紀錄路徑，以便回頭
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

    	if ( moveCheck == false && check == false ) { // 如果是死路(沒有E也沒有G)
       		while ( returnCheck ) {
                    returnCheck = false ;
               for ( int i = 0 ; i < 100 ; i++ ) {
                   if ( record[i] != 0)
                       returnCheck = true ;
               } //檢查是否還有紀錄
        	    if ( record[recordCount] == 1 ) { // 往回
            	    record[recordCount] = 0 ;
                	runLine-- ;
                	recordCount-- ;
            	}
            	else if ( record[recordCount] == 2 ) { // 往回
                	record[recordCount] = 0 ;
                	runColumn-- ;
                	recordCount-- ;
            	}
            	else if ( record[recordCount] == 3 ) { // 往回
                	record[recordCount] = 0 ;
                	runLine++ ;
                	recordCount-- ;
            	}
            	else if ( record[recordCount] == 4 ) { // 往回
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
        
        for ( int i = 0 ; i < column ; i++ ) { //檢查是否還有尚未走過的路徑
        	for ( int j = 0 ; j < line ; j++ ) {
            	if ( printBuffer[j][i] == 'E' )
              		anotherWay = true ;
         	}
        } // 檢查是否還有沒走過的路


        if ( loopCount >( line *column*4) )
            anotherWay = false ;

    } // while


    runColumn = 0;
    runLine = 0 ;
    buffer[0][0] = 'R' ;
    for ( int i = 0 ; i < 100 ; i++ ) { // 建立可到達標的路徑buffer
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
    for ( int i = 0 ; i < column ; i++ ) { // 輸出第一個矩陣(以V表示所有走過的位置)
        for ( int j = 0 ; j < line ; j++ ) {
            cout << printBuffer[j][i] ;
        }
        cout << endl ;
    }

    cout << endl ;
    if ( check == true ) {
    for ( int i = 0 ; i < column ; i++ ) { // 輸出第二個矩陣(以R表示走到目標的一條路徑)
        for ( int j = 0 ; j < line ; j++ ) {
            cout << buffer[j][i] ;
        }
        cout << endl ;
    }
    }


} // oneGoal()

void NGoal ( char**  buffer, int line , int column  ) { // 經過多個目標的一條路徑
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
        for ( int i = 0 ; i < column ; i++ ) { //檢查是否還有尚未走過的路徑
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
    for ( int i = 0 ; i < column ; i++ ) { // 輸出第二個矩陣(以R表示走到目標的一條路徑)
        for ( int j = 0 ; j < line ; j++ ) {
            cout << printBuffer2 [j][i] ;
        }
        cout << endl ;
    }
    }

    } // else

} // NGoal()

void readTheFile( int command ) { // 讀檔
    int input = 1 , line = 0, column = 0;
    string lineSet;
    bool check = false ;
    char inputChar ;
  	cout << endl << "Input a file number (e.g., 201, 202, ...):  " ;
  	input = getNum() ; // 讀入檔名
  	string inputString = to_string( input ) ; // 將int檔名轉成string
  	fstream theFile;
  	theFile.open( "input"+inputString+".txt" ); // 開啟指定檔案

  	if ( theFile.is_open() ) { // 如果有打開檔案
    	getline( theFile, lineSet ) ; // 讀入第一行的橫軸寬&縱軸長
    	for ( int i = 0 ; i < lineSet.length() ; i++ ) {
    		if ( !check ) { // 第一個是橫軸寬 (行line|)
        		if ( lineSet[i] >= '0' && lineSet[i] <= '9') {
           		 	line *= 10 ;
          			line = line + (lineSet[i] - '0') ;
        		}
        		else check = true ;

    		} // if
       		else { // 第二個是縱軸長 (列column--)
        		if ( lineSet[i] >= '0' && lineSet[i] <= '9') {
        			column *= 10 ;
        			column = column + (lineSet[i] - '0') ;
           		}
       		} // else
    	}

    	char buffer[line][column] ; // 建立迷宮大小
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
        	} // 計算有多少列
        	else {
            	buffer[lineCount][columnCount] = inputChar ;
            	lineCount++ ;
        	} // 把指定的放入該位置
    	} // 把讀入的資料放進迷宮(buffer[])

    	theFile.close();


    	if ( command == 1 ) { // 任務一
        	oneGoal( forFunction, line, column ) ; // 走到一個目標的一條路徑
    	}
    	else if ( command == 2 ) { // 任務二
        	NGoal( forFunction, line, column ) ; // 經過多個目標的一條路徑
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
        readTheFile( command ); // 讀檔( 順便分別任務1,2 )
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
