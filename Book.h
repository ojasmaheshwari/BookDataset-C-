#pragma once

#include <cstdint>
#include <string>
#include <utility>
#include <vector>

struct BookData {
  std::string title, author, userRating, reviews, price, year, genre;
};

class Book {
public:
  Book(BookData data);

  // Getters
  std::string getTitle() const;
  std::string getAuthor() const;
  std::string getYear() const;
  std::string getGenre() const;
  std::string getUserRating() const;
  std::string getReviewsCount() const;
  std::string getPrice() const;

  // Setters
  void setTitle(const std::string &title);
  void setAuthor(const std::string &author);
  void setYear(const std::string &year);
  void setGenre(const std::string &genre);
  void setUserRating(const std::string rating);
  void setReviewsCount(const std::string count);
  void setPrice(const std::string price);

  void printDetails() const;

private:
  BookData m_Data;
};
