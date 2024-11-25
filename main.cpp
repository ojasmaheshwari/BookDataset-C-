#include "DatasetReader.h"

int main(int argc, const char **argv) {
  DatasetReader reader("data.csv");
  auto books = reader.getBooks();

  for (auto book : books) {
    book.printDetails();
  }
}
