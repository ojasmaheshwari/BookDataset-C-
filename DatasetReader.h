#pragma once

#include "Book.h"
#include <fstream>
#include <vector>

class DatasetReader {
public:
  DatasetReader(const std::string &filePath);
  ~DatasetReader();

  std::vector<Book> getBooks() const;

private:
  std::vector<Book> m_Books;
  std::ifstream m_FileStream;
  std::string m_FilePath;
  BookData m_BookData;
};
