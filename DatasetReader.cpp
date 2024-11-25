#include "DatasetReader.h"
#include "Book.h"
#include <regex>
#include <string>
#include <vector>

DatasetReader::DatasetReader(const std::string &filePath)
    : m_FilePath(filePath) {
  m_FileStream.open(m_FilePath);

  std::string line;
  std::regex delimeter(", ");
  std::regex rule(".+,\\ .+,\\ .+,\\ .+,\\ .+,\\ .+,\\ .+");

  while (getline(m_FileStream, line)) {
    bool isValid = std::regex_match(line.c_str(), rule);

    if (!isValid)
      continue;

    std::sregex_token_iterator it(line.begin(), line.end(), delimeter, -1);
    std::sregex_token_iterator end;

    std::vector<std::string> dataVec;
    while (it != end) {
      dataVec.emplace_back(*it);
      ++it;
    }

    m_BookData = {dataVec[0], dataVec[1], dataVec[2], dataVec[3],
                  dataVec[4], dataVec[5], dataVec[6]};
    Book book(m_BookData);

    m_Books.emplace_back(book);
  }
}

DatasetReader::~DatasetReader() { m_FileStream.close(); }

std::vector<Book> DatasetReader::getBooks() const { return m_Books; }
