#include "includes/Book.h"
#include <iostream>
#include <string>

Book::Book(BookData data) : m_Data(data) {}

std::string Book::getTitle() const { return m_Data.title; }
std::string Book::getAuthor() const { return m_Data.author; }
std::string Book::getYear() const { return m_Data.year; }
std::string Book::getGenre() const { return m_Data.genre; }
std::string Book::getUserRating() const { return m_Data.userRating; }
std::string Book::getReviewsCount() const { return m_Data.reviews; }
std::string Book::getPrice() const { return m_Data.price; }

void Book::setTitle(const std::string &title) { m_Data.title = title; }
void Book::setAuthor(const std::string &author) { m_Data.author = author; }
void Book::setYear(const std::string &year) { m_Data.year = year; }
void Book::setGenre(const std::string &genre) { m_Data.genre = genre; }
void Book::setUserRating(const std::string rating) {
  m_Data.userRating = rating;
}
void Book::setReviewsCount(const std::string count) { m_Data.reviews = count; }
void Book::setPrice(const std::string price) { m_Data.price = price; }

void Book::printDetails() const {
  std::cout << "Title: " << m_Data.title << '\n';
  std::cout << "Author: " << m_Data.author << '\n';
  std::cout << "Year: " << m_Data.year << '\n';
  std::cout << "Genre: " << m_Data.genre << '\n';
  std::cout << "User Rating: " << m_Data.userRating << '\n';
  std::cout << "Reviews Count: " << m_Data.reviews << '\n';
  std::cout << "Price: " << m_Data.price << '\n';
}
