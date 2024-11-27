#include "DatasetReader.h"
#include "Book.h"
#include <cstdint>
#include <iostream>
#include <regex>
#include <set>
#include <string>
#include <utility>
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

uint32_t DatasetReader::getBookCountByAuthor(const std::string &author) const {
  uint32_t count = 0;
  for (const Book &book : m_Books) {
    if (book.getAuthor() == author)
      count++;
  }
  return count;
}

void DatasetReader::printAllAuthors() const {
  std::set<std::string> set;

  for (const Book &book : m_Books) {
    set.insert(book.getAuthor());
  }

  for (auto it = set.begin(); it != set.end(); it++) {
    std::cout << *it << '\n';
  }
}

std::vector<Book>
DatasetReader::getBooksByAuthor(const std::string &author) const {
  std::vector<Book> books;

  for (const Book &book : m_Books) {
    if (book.getAuthor() == author)
      books.emplace_back(book);
  }

  return books;
}

std::vector<Book>
DatasetReader::getBooksByRating(const std::string &rating) const {
  std::vector<Book> books;

  for (const Book &book : m_Books) {
    if (book.getUserRating() == rating)
      books.emplace_back(book);
  }

  return books;
}

std::vector<std::pair<std::string, std::string>>
DatasetReader::getBookNameAndPriceByAuthor(const std::string &author) const {
  std::vector<std::pair<std::string, std::string>> books;

  for (const Book &book : m_Books) {
    if (book.getAuthor() == author)
      books.emplace_back(std::make_pair(book.getTitle(), book.getPrice()));
  }

  return books;
}
