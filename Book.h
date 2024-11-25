#pragma once

#include <cstdint>
#include <string>
#include <vector>

struct BookData {
  std::string title, author, year, genre, userRating, reviews, price;
};

class Book {
public:
  Book(BookData &data);

  // Getters
  inline std::string getTitle() const;
  inline std::string getAuthor() const;
  inline std::string getYear() const;
  inline std::string getGenre() const;
  inline std::string getUserRating() const;
  inline std::string getReviewsCount() const;
  inline std::string getPrice() const;

  // Setters
  void setTitle(const std::string &title);
  void setAuthor(const std::string &author);
  void setYear(const std::string &year);
  void setGenre(const std::string &genre);
  void setUserRating(const std::string rating);
  void setReviewsCount(const std::string count);
  void setPrice(const std::string price);

  void printDetails() const;
  uint32_t getBookCountByAuthor(std::string &author) const;
  void printAllAuthors() const;
  std::vector<std::string> getBooksByAuthor(std::string &author) const;
  std::vector<Book> getBooksByRating(std::string &rating) const;

private:
  BookData &m_Data;
};
