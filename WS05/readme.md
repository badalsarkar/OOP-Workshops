<<<<<<< HEAD
jj:# Workshop 5: Functions and Error Handling
=======
# Workshop 5: Functions and Error Handling
>>>>>>> 5ec349c8fa80c6c972d27d722ee135d09aedfa87


In this workshop, you code a function object, a lambda expression, and exception handling. 

You are to create a template class that manages a collection of objects of type `T`. The client of this class will be able to register a callback function (an observer) that will be called every time a new item has been added successfully.

You are to work with a collection of books and another collection of movies, both loaded from files. The information about books/movies contains mistakes:
- You are to create a lambda expression that fixes the price information about a book
- You are to create a function object (functor) that will fix some spelling mistakes in the description and titles for books/movies.

In case of exceptional situations, you are to generate and handle exceptions
- the functor will load the misspelled words from a file, but if the file is missing, and exception should be generated.
- iterating over the collection using indices, should generate an exception if the index is not valid.



## Learning Outcomes

Upon successful completion of this workshop, you will have demonstrated the abilities to:

- design and code a templated class that allocates and deallocates dynamic memory
- design and code a function object
- design and code a lambda expression
- code a member function that receives the address of another function to execute 
- throw exceptions of different types
- distinguish exception types



## Submission Policy

The *in-lab* section is to be completed during your assigned lab section.  It is to be completed and submitted by the end of the workshop period.  If you attend the lab period and cannot complete the *in-lab* portion of the workshop during that period, ask your instructor for permission to complete the *in-lab* portion after the period.  If you do not attend the workshop, you can submit the *in-lab* section along with your *at-home* section (see penalties below).  **In order to get credit for the *in-lab* portion, you must be present in the lab for the entire duration of the lab.**

The *at-home* portion of the workshop is due on the day that is four days after your scheduled *in-lab* workshop (@ 23:59:59), **even if that day is a holiday**.

All your work (all the files you create or modify) must contain your name, Seneca email, student number and the date of completion (use the following template):

```cpp
// Name:
// Seneca Student ID:
// Seneca email:
// Date of completion:
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.
```

You are responsible to back up your work regularly.



### Late Submission Penalties

The workshop can be submitted up to **1 (one) day** late (the day that is 5 days after the lab period); submissions received on this day are considered **late** and are subject to penalties:

- only *in-lab* portion submitted late (after the end of the lab period): 0 for *in-lab* portion, max 7/10 for the entire workshop.
- only *at-home* portion submitted late (more than 4 days after the lab period): max 4 for the *at-home* portion, max 7/10 for the entire workshop.
- both *in-lab* **and** *at-home* portions submitted late: max 4/10 for the entire workshop.
- when the submission closes, if the workshop is not complete, the mark for the entire workshop will be 0/10. The workshop is considered complete if there are two separate submissions (*in-lab* submission and *at-home* submission) containing the *in-lab code*, *at-home code* and *reflection*.

The submission is considered closed at the end of the day that is 5 (five) days after the lab period.



## *In-Lab*

The in-lab portion of this workshop consists of modules:
- `w5` (partially supplied)
- `Book`

Enclose all your source code within the `sdds` namespace and include the necessary guards in each header file.





### `Book` Module

This module defines a class that holds information about a single book.

Design and code a class named `Book` that should be able to store the following information (for each attribute, you can chose any type you think it's appropriate--you must be able to justify the decisions you have made):

- **author**
- **title**
- **the country of publication**
- **the year of publication**
- **the price of the book**
- **the description**: the summary of the book


***Public Members***
- a default constructor
- `const std::string& title() const`: a query that returns the title of the book
- `const std::string& country() const`: a query that returns the publication country
- `const size_t& year() const`: a query that returns the publication year
- `double& price()`: a function that returns the price **by referene**, allowing you to update the price
- `Book(const std::string& strBook)`: A constructor that receives the book as a string; this constructor is responsible to extract the information about the book from the parameter and store it in the attributes of the instance. The parameter will always have the following format:
```
AUTHOR,TITLE,COUNTRY,PRICE,YEAR,DESCRIPTION
```
  This constructor should remove all spaces from the **beginning and end** of any token in the string.

  When implementing the constructor, consider the following functions:
  - [std::string::substr()](https://en.cppreference.com/w/cpp/string/basic_string/substr)
  - [std::string::find()](https://en.cppreference.com/w/cpp/string/basic_string/find)
  - [std::string::erase()](https://en.cppreference.com/w/cpp/string/basic_string/erase)
  - [std::stoi()](https://en.cppreference.com/w/cpp/string/basic_string/stol)
  - [std::stod()](https://en.cppreference.com/w/cpp/string/basic_string/stof)

**Add any other function that is required by your design!**


***Friend Helpers***
- overload the insertion operator to insert the content of a book object into an **ostream** object, in the following format:
```
AUTHOR | TITLE | COUNTRY | YEAR | PRICE | DESCRIPTION
```
  - the **author** should be printed on a field of size 20;
  - the **title** should be printed on a field of size 22;
  - the **country** should be printed on a field of size 5;
  - the **year** should be printed on a field of size 4;
  - the **price** should be printed on a field of size 6, and should have 2 digits;
  - see alignment in the sample output.






### `w5` Module (partially supplied)


This module has some missing parts. The missing parts are marked with `TODO`, describing what code you should add and where. **Do not modify the existing code, only add what is missing!**


### Sample Output

When the program is started with the command (the file `book.txt` is provided):
```
w5.exe book.txt
```
the output should look like the one from the `sample_output.txt` file.



### Submission (30%)

To test and demonstrate execution of your program use the same data as shown in the output example.

Upload your source code to your `matrix` account. Compile and run your code using the latest version of the `g++` compiler (available at `/usr/local/gcc/9.1.0/bin/g++`) and make sure that everything works properly.

Then, run the following command from your account (replace `profname.proflastname` with your professor’s Seneca userid):
```
~profname.proflastname/submit 345XXX_w5_lab
```
and follow the instructions. Replace XXX with the section letter(s) specified by your instructor.

**:warning:Important:** Please note that a successful submission does not guarantee full credit for this workshop. If the professor is not satisfied with your implementation, your professor may ask you to resubmit. Resubmissions will attract a penalty.



 
## *At-Home*

The *at-home* part of this workshop upgrades your *in-lab* solution to include more modules:
- `Movie`
- `SpellChecker`
- `Collection`




### `SpellChecker` Module (functor)


Add a `SpellChecker` module to your project. This module should maintain two arrays of strings, both of size 5 (statically allocated):
- `m_badWords`: an array with 5 misspelled words
- `m_goodWords`: an array with the correct spelling of those 5 words


***Public Members***

- `SpellChecker(const char* filename);`: a constructor that receives as a parameter the name of the file that contains the misspelled words. If the file is missing, this constructor should generate an exception of type `const char*`, with the message `Bad file name!`
  - this constructor should load the content of the file. Each line from the file is in the format `BAD_WORD  GOOD_WORD`; the two fields can be separated by any number of spaces.

- `void operator()(std::string& text) const`
  - this operator should search in `text` if any of the misspelled words appear and replace them with the correct version.

When implementing the operator, consider the following functions:
  - [std::string::find()](https://en.cppreference.com/w/cpp/string/basic_string/find)
  - [std::string::replace()](https://en.cppreference.com/w/cpp/string/basic_string/replace)




### `Book` Module


Add to the `Book` class a public template function:
- `void fixSpelling(T spellChecker)`: this function should call the overloaded `operator()` on instance `spellChecker`, passing to it the book description.

  In this design, type `T` must have an overload of the `operator()` that accepts a string as a parameter.

  **Since this is a template function, it must be implemented in the header!** The class is not a template.




### `Movie` Module

Design and code a class named `Movie` that should be able to store the following information (for each attribute, you can chose any type you think it's appropriate--you must be able to justify the decisions you have made):

- **title**
- **the year of release**
- **the description**


***Public Members***
- a default constructor
- `const std::string& title() const`: a query that returns the title of the movie
- `Movie(const std::string& strMovie)`: A constructor that receives the movie as a string; this constructor is responsible to extract the information about the movie from the parameter and store it in the attributes of the instance. The parameter will always have the following format:
```
TITLE,YEAR,DESCRIPTION
```
  This constructor should remove all spaces from the **beginning and end** of any token in the string.

  When implementing the constructor, consider the following functions:
  - [std::string::substr()](https://en.cppreference.com/w/cpp/string/basic_string/substr)
  - [std::string::find()](https://en.cppreference.com/w/cpp/string/basic_string/find)
  - [std::string::erase()](https://en.cppreference.com/w/cpp/string/basic_string/erase)
  - [std::stoi()](https://en.cppreference.com/w/cpp/string/basic_string/stol)

- `void fixSpelling(T spellChecker)`: a template function. This function should call the overloaded `operator()` on instance `spellChecker`, passing to it the movie title and description.

  In this design, type `T` must have an overload of the `operator()` that accepts a string as a parameter.

  **Since this is a template function, it must be implemented in the header!** The class is not a template.

**Add any other function that is required by your design!**


***Friend Helpers***
- overload the insertion operator to insert the content of a movie object into an **ostream** object, in the following format:
```
TITLE | YEAR | DESCRIPTION
<<<<<<< HEAD
```:
=======
```
>>>>>>> 5ec349c8fa80c6c972d27d722ee135d09aedfa87
  - the **title** should be printed on a field of size 40;
  - the **year** should be printed on a field of size 4;




### `Collection` Module


Add a `Collection` module to your project. The purpose of this class is to manage a collection items of template type `T`. Since this is template class, it doesn't need a `.cpp` file.

This module should manage a **dynamically allocated** array of objects of type `T`, resizing it when a new item is added. Using a callback function, this class will inform the client when a new item has been added to the collection.

The class collection will provide two overloads for `operator[]` to access the stored item. 


***Private Data***

- the name of the collection;
- a dynamically allocated array of items `T`
- the size of the array
- a pointer to a function that returns `void` and receives two parameters of type `const Collection<T>&` and `const T&`.

  This is the **observer** function (it *observes* an event): when an item has been added to the collection, the class `Collection<T>` will call this function informing the client about the adition.


***Public Members***

- `Collection(std::string name)`: sets the name of the collection to the parameter and all other attributes to their default value
- this class doesn't support copy operations; delete them.
- a destructor
- `const std::string& name() const`: a query that returns the name of the collection.
- `size_t size() const`: a query that returns how many items are in the collection.

- `void setObserver(void (*observer)(const Collection<T>&, const T&))`: stores the parameter into an attribute, to be used when an item is added to the collection. The parameter is a pointer to a function that returns `void` and accepts two parameters: a collection and an item that has just been added to the collection.

- `Collection<T>& operator+=(const T& item)`: adds a copy of `item` to the collection, only if the collection doesn't contain an item with the same title (type `T` has a member function called `title()` that returns the title of the item). If `item` is already in the collection, this function does nothing.  If the item is not already in the collection, this function:
  - resize the array to accomodate the new item
  - if there is an observer registered, call the observer function passing `*this` and the new item as parameters.

- `T& operator[](size_t idx) const`: returns the item at index `idx`.
  - if the index is out of range, this function throws an exception of type `std::out_of_range` with the message `Bad index [IDX]. Collection has [SIZE] items.`. Use operator `+` to concatenate strings.

  When implementing this operator, consider the following:
  - [std::to_string()](https://en.cppreference.com/w/cpp/string/basic_string/to_string)
  - [std::out_of_range](https://en.cppreference.com/w/cpp/error/out_of_range)

- `T* operator[](std::string title) const`: returns the address of the item with title `title` (type `T` has a member function called `title()` that returns the title of the item). If no such item exists, this function returns `nullptr`.


***FREE Helpers***

- overload the insertion operator to insert the content of a `Collection` object into an **ostream** object. Iterate over all elements in the collection and insert each one into the `ostream` object (do not add newlines).


**:warning:Important: The class `Collection` should have no knowledge of any of the custom types you have defined (`Book`, `Movie`, `SpellChecker`).** 



### Sample Output

When the program is started with the command (the files are provided):
```
w5.exe books.txt movies.txt missing_file.txt words.txt
```
the output should look like the one from the `sample_output.txt` file.




### Reflection

Study your final solution, reread the related parts of the course notes, and make sure that you have understood the concepts covered by this workshop. **This should take no less than 30 minutes of your time.**

Create a **text** file named `reflect.txt` that contains your detailed description of the topics that you have learned in completing this particular workshop and mention any issues that caused you difficulty and how you solved them. Include in your explanation—**but do not limit it to**—the following points:
- the difference between the implementations/utilizations of a functor and a lambda expression.  When is appropriate to use each one?
- the constructor for `SpellChecker` generates an exception in certain conditions.  How would you change your code to achieve the same result, but without exceptions (both on the constructor and on the client side)? Compare the two solutions.
- the classes `Movie` and `Book` contain almost identical logic in loading data from the file. How would you redesign the classes in order **not** to duplicate that logic?
- the classes `Movie` and `Book` are instantiated from the `main()` function using a custom constructor, but they also contain a default constructor.  Is the default constructor necessary? Could you remove it? Justify your answer.



#### Quiz Reflection

Add a section to `reflect.txt` called **Quiz X Reflection**. Replace the **X** with the number of the last quiz that you received and list all questions that you answered incorrectly.

Then for each incorrectly answered question write your mistake and the correct answer to that question. If you have missed the last quiz, then write all the questions and their answers.




### Submission (30% for code, 40% for reflection)

To test and demonstrate execution of your program use the same data as shown in the output example above.

Upload the source code and the reflection file to your `matrix` account. Compile and run your code using the latest version of the `g++` compiler (available at `/usr/local/gcc/9.1.0/bin/g++`) and make sure that everything works properly.

Then, run the following command from your account (replace `profname.proflastname` with your professor’s Seneca userid):
```
~profname.proflastname/submit 345XXX_w5_home
```
and follow the instructions. Replace XXX with the section letter(s) specified by your instructor.

**:warning:Important:** Please note that a successful submission does not guarantee full credit for this workshop. If the professor is not satisfied with your implementation, your professor may ask you to resubmit. Resubmissions will attract a penalty.
