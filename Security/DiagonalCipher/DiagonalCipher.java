/*
   Author: Kevin Costello
   Assignment #2 for CPE321
   Due Date: 10/13/2016
*/

import java.io.*;
import java.util.ArrayList;
import java.util.Scanner;
import java.nio.file.*;

public class DiagonalCipher {
  // Contains the contents of the file given by the user.
  // Where index 0 is the file's first line,
  // index 1 is the file's second line and so on.
  private static ArrayList<String> lineList;

  // Prints out the matrix
  private static void printMatrix(char[][] matrix) {
    String currLine;
    // Formatting, add space before printing the matrix out
    System.out.println();
    for (int r = 0; r < matrix.length; r++) {
      //Construct strings for each row of the matrix
      currLine = new String(matrix[r]);
      System.out.println(currLine);
    }
  }

  // Initializes the matrix to be filled with '.'s
  private static void fillWithPeriods(char[][] matrix) {

    for (int r = 0; r < matrix.length; r++) {
      for (int c = 0; c < matrix[r].length; c++) {
        matrix[r][c] = '.';
      }
    }
  }

  private static void readMatrix(char[][] matrix) {
    String currLine = "";
    String entireText = "";
    char myChar;

    System.out.print("\nReading off the ciphered text: ");
    for (int r = 0; r < matrix.length; r++) {
      for (int c = 0; c < matrix[r].length; c++) {
        myChar = matrix[r][c];
        // Only add non period characters to the output
        if (myChar != '.') {
          currLine += Character.toString(myChar);
        }

      }
      entireText += currLine;
    }
    System.out.println(currLine);

  }

  private static void buildMatrix(int lineNum, int numRows) {
    if (lineNum < 1 || lineNum > lineList.size()) {
      System.out.println("!***Sorry that line is not in the file***! Try again!\n");
      return;
    }

    // Include spaces in the matrix; spaces accounted for with line.length();
    String line = lineList.get(lineNum - 1);
    int numCols = line.length();
    char[][] matrix = new char[numRows][numCols];
    // TODO fill matrix with '.'s
    // Cannot have a case for every possible row number in while
    // loop to fill every other spot with '.'s for each iteration
    fillWithPeriods(matrix);

    int index = 0;
    int currRow = 0;
    boolean increasing = true;

    while (index < numCols) {

      if (currRow == 0) {
        increasing = true;
      }

      else if (currRow == numRows - 1) {
        increasing = false;
      }

      matrix[currRow][index] = line.charAt(index);

      if (increasing == true) {
        currRow++;
      }
      else if (increasing == false) {
        currRow--;
      }

      index++;
    }

    // Print the resulting matrix when finished creating it
    printMatrix(matrix);
    // Read off the rail-ciphered text
    readMatrix(matrix);

    //return matrix;
  }

  /* Prompts the user for a line number and number of rows */
  private static void cipher() {
    Scanner s;
    int lineNum;
    int numRows;

    try {
      /* Prompt for line number in the file */
      System.out.print("\nEnter a line number from the file to cipher.\n" +
        "(The first line in the file is line 1)\nOr enter 0 to exit\n\n> ");
      s = new Scanner(System.in);
      lineNum = s.nextInt();
      if (lineNum == 0) {
        System.exit(1);
      }

      /* Prompt for number of rows in the output matrix */
      System.out.print("\nEnter the number of rows for the matrix.\n" +
        "Or enter 0 to exit\n\n> ");
      numRows = s.nextInt();
      if (numRows == 0) {
        System.exit(1);
      }
      else {
        // We have a line in the file and the number of rows
        // for the desired matrix, so make it!
        buildMatrix(lineNum, numRows);
      }

    }
    catch (Exception e) {
      System.out.println(e.toString());
    }

  }

  /*  This function takes the file name given by the user and tries to read
   *  from that file. Should anything not work, the program exits
   *  and prints an error message.
  */
  private static void parseInputFile(String fileName) {

    try {
      for (String line : Files.readAllLines(Paths.get(fileName))) {
        lineList.add(line);
      }
    }
    catch (IOException e) {
      System.out.println("Unable to locate that file. Exiting.");
      System.exit(0);
    }

  }

  public static void main (String args[]) {
    String greeting;
    String fileName;
    int lineNum;
    Scanner myScanner;

    /* Greet the user and display simple insructions */
    greeting =  "\nWelcome to DiagonalCipher! ";
    greeting += "\nPlease provide a path to a file to begin.";
    greeting += "\n\n> ";
    System.out.print(greeting);

    lineList = new ArrayList<String>();

    try {
      myScanner = new Scanner(System.in);
      fileName = myScanner.next();
      myScanner.nextLine();

      // Why does removing this line allow cipher() to
      // read from System.in?
      // Cool answer: http://stackoverflow.com/questions/26245468/what-does-scanner-close-do
      // myScanner.close();

      parseInputFile(fileName);
    }
    catch (Exception e) {
      System.out.println(e.toString());
      System.exit(0);
    }

    // The file was read from and the contents of the file are in the lineList
    // ArrayList Object. Begin asking for line numbers and number of rows
    // The program exits when the user enters a 0 for a line number or for
    // number of rows in the matrix.
    while (true) {
      cipher();
    }


  }

}

/* Sample Output:
  Welcome to DiagonalCipher!
  Please provide a path to a file to begin.

  > input.txt

  Enter a line number from the file to cipher.
  (The first line in the file is line 1)
  Or enter 0 to exit

  > 5

  Enter the number of rows for the matrix.
  Or enter 0 to exit

  > 4

  W.....e.....p.....t.....n.....?.....?.....?.....
  .h...v.r...p.e... .o...o.g...b.?...?.?...?.?...?
  ..a.e... .a...n.d... .p...e.o...?.?...?.?...?.?.
  ...t.....h.....e.....s.....b.....?.....?.....?..

  Reading off the ciphered text: Weptn???hvrpe oogb??????ae and peo??????thesb???

  Enter a line number from the file to cipher.
  (The first line in the file is line 1)
  Or enter 0 to exit

  > 3

  Enter the number of rows for the matrix.
  Or enter 0 to exit

  > 3

  I...V...A..
  . .O.E.C.K.
  ..L... ...E

  Reading off the ciphered text: IVA OECKL E

  Enter a line number from the file to cipher.
  (The first line in the file is line 1)
  Or enter 0 to exit

  > 0
*/

