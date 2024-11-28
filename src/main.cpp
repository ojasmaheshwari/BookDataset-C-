#include "includes/DatasetReader.h"
#include <iostream>

int main(int argc, const char **argv) {
  DatasetReader reader("test.csv");
  auto books = reader.getBooks();

  for (auto const &book : books) {
    book.printDetails();
  }

  /* auto jordanBooksCount = reader.getBookCountByAuthor("Jordan B. Peterson");
   */
  /* std::cout << "Jordan Peterson has written " << jordanBooksCount */
  /*           << " books.\n"; */
  /* std::cout << '\n'; */

  /* auto booksByJordan = reader.getBooksByAuthor("Jordan B. Peterson"); */
  /* std::cout << "These are:- \n"; */
  /* for (const auto &book : booksByJordan) { */
  /*   std::cout << book.getTitle() << '\n'; */
  /* } */

  /* std::cout << '\n'; */

  /* auto nameAndPrices = reader.getBookNameAndPriceByAuthor("Jordan B.
   * Peterson"); */
  /* std::cout << "Their names and prices:- \n"; */
  /* for (auto const &p : nameAndPrices) { */
  /*   std::cout << p.first << " -> " << p.second << " dollars\n"; */
  /* } */

  /* std::cout << '\n'; */

  /* auto booksByRating = reader.getBooksByRating("4.7"); */
  /* std::cout << "Books with 4.7 rating are:- \n"; */
  /* for (auto const &book : booksByRating) { */
  /*   std::cout << book.getTitle() << '\n'; */
  /* } */

  /* std::cout << '\n'; */

  /* std::cout << "All authors are:- \n"; */
  /* reader.printAllAuthors(); */
}
