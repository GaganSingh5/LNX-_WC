#include <stdio.h>
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

/**
 * Returns the size of the file specified by fileName.
 *
 * @param fileName The path to the file whose size is to be determined.
 * @return The size of the file in bytes, or -1 if the file cannot be opened.
 */
int getFileSize(std::string fileName)
{
  // Open the file in binary mode for reading
  ifstream in_file(fileName, ios::binary);

  // Check if the file was opened successfully
  if (!in_file.is_open())
  {
    // Return -1 to indicate failure to open the file
    return -1;
  }

  // Move the file pointer to the end of the file
  in_file.seekg(0, ios::end);

  // Get the current position of the file pointer, which is the file size
  int fileSize = in_file.tellg();

  // Close the file
  in_file.close();

  // Return the file size
  return fileSize;
}

/**
 * Counts the number of lines in the file specified by fileName.
 *
 * @param fileName The path to the file whose lines are to be counted.
 * @return The number of lines in the file, or -1 if the file cannot be opened.
 */
int getLineCount(std::string fileName)
{
  // Initialize a variable to store the line count
  int number_of_lines = 0;

  // Initialize a string variable to store each line read from the file
  string line;

  // Open the file in binary mode for reading
  ifstream in_file(fileName, ios::binary);

  // Check if the file was opened successfully
  if (!in_file.is_open())
  {
    // Return -1 to indicate failure to open the file
    return -1;
  }

  // Loop through each line in the file
  while (getline(in_file, line))
  {
    // Increment the line count
    ++number_of_lines;
  }

  // Close the file
  in_file.close();

  // Return the total number of lines
  return number_of_lines;
}

/**
 * Counts the number of words in the file specified by fileName.
 *
 * @param fileName The path to the file whose words are to be counted.
 * @return The number of words in the file, or -1 if the file cannot be opened.
 */
int getWordCount(std::string fileName)
{
  // Initialize a variable to store the current line being read from the file
  string line;

  // Initialize a variable to store the total word count
  int wordCount = 0;

  // Open the file in binary mode for reading
  ifstream in_file(fileName, ios::binary);

  // Check if the file was opened successfully
  if (!in_file.is_open())
  {
    // Return -1 to indicate failure to open the file
    return -1;
  }

  // Loop through each line in the file
  while (getline(in_file, line))
  {
    // Create a stringstream from the current line to extract words
    std::stringstream ss(line);

    // Initialize a variable to store each word extracted from the line
    string word;

    // Loop through each word in the line
    while (ss >> word)
    {
      // Increment the word count
      wordCount++;
    }
  }

  // Close the file
  in_file.close();

  // Return the total number of words
  return wordCount;
}

/**
 * Counts the number of characters in the file specified by fileName.
 *
 * @param fileName The path to the file whose characters are to be counted.
 * @return The number of characters in the file, or -1 if the file cannot be opened.
 */
int getCharacterCount(std::string fileName)
{
  // Initialize a variable to store the current character being read from the file
  char ch;

  // Initialize a variable to store the total character count
  int charCount = 0;

  // Open the file in binary mode for reading
  ifstream in_file(fileName, ios::binary);

  // Check if the file was opened successfully
  if (!in_file.is_open())
  {
    // Return -1 to indicate failure to open the file
    return -1;
  }

  // Loop through each character in the file
  while (in_file.get(ch))
  {
    // Increment the character count
    charCount++;
  }

  // Close the file
  in_file.close();

  // Return the total number of characters
  return charCount;
}

/**
 * The main function of the program.
 *
 * @param argc The number of command-line arguments.
 * @param argv An array of command-line arguments.
 * @return 0 upon successful execution.
 */
int main(int argc, char const *argv[])
{
  // Initialize variables to store command-line option and file name
  string option;
  string fileName;

  // Check if no option or file name is provided
  if (argc == 1)
  {
    // Print usage message
    cout << "Usage: " << argv[0] << " [-c|-l|-w|-m] <file_name>" << endl;
    cout << "Options:" << endl;
    cout << "  -c    Display file size" << endl;
    cout << "  -l    Display line count" << endl;
    cout << "  -w    Display word count" << endl;
    cout << "  -m    Display character count" << endl;
    return 0;
  }

  // Check the number of command-line arguments
  if (argc == 3)
  {
    // If there are 3 arguments, assume the first one is the option and the second one is the file name
    option = argv[1];
    fileName = argv[2];
  }
  else if (argc == 2)
  {
    // If there are 2 arguments, check if the first argument is an option or a file name
    if (*argv[1] == '-')
    {
      // If the first argument starts with '-', it's an option
      option = argv[1];
      fileName = ""; // Empty string for file name
    }
    else
    {
      // Otherwise, it's a file name
      option = ""; // Empty string for option
      fileName = argv[1];
    }
  }
  else if (argc == 1)
  {
  }

  // Switch-case statement for handling different options
  switch (option[1]) // Check the first character of the option (excluding '-')
  {
  case 'c':
    // Display file size
    cout << getFileSize(fileName) << " " << fileName;
    break;
  case 'l':
    // Display line count
    cout << getLineCount(fileName) << " " << fileName;
    break;
  case 'w':
    // Display word count
    cout << getWordCount(fileName) << " " << fileName;
    break;
  case 'm':
    // Display character count
    cout << getCharacterCount(fileName) << " " << fileName;
    break;
  default:
    // Print error message for invalid option
    cout << "Invalid option: " << option << endl;
  }

  return 0;
}