#pragma once

#include "Book.h"
#include <fstream>
#include <vector>

class DatasetReader {
public:
  DatasetReader(const std::string &filePath);
  ~DatasetReader();

  std::vector<Book> getBooks() const;

  uint32_t getBookCountByAuthor(const std::string &author) const;
  void printAllAuthors() const;
  std::vector<Book> getBooksByAuthor(const std::string &author) const;
  std::vector<Book> getBooksByRating(const std::string &rating) const;
  std::vector<std::pair<std::string, std::string>>
  getBookNameAndPriceByAuthor(const std::string &author) const;

private:
  std::vector<Book> m_Books;
  std::ifstream m_FileStream;
  std::string m_FilePath;
  BookData m_BookData;
};
