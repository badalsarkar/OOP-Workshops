// Workshop 8 - Smart Pointers
// 2019/11 - Cornel

// Name:Badal Sarkar
// Seneca Student ID: 137226189
// Seneca email:bsarkar2@myseneca.ca
// Date of completion:November 19, 2019
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.


#include <memory>
#include "List.h"
#include "Element.h"
#include "Utilities.h"

using namespace std;

namespace sdds {
	List<Product> mergeRaw(const List<Description>& desc, const List<Price>& price) {
		List<Product> priceList;
		// TODO: Add your code here to build a list of products
		//         using raw pointers
        for(size_t i=0; i<desc.size(); i++){
            for (size_t j=0; j<price.size();j++){
                if(desc[i].code==price[j].code){
                    Product* tempProduct=new Product(desc[i].desc, price[j].price);
                    tempProduct->validate();
                    priceList+=tempProduct;
                    delete tempProduct;
                }
            }
        }
		return priceList;
	}

	List<Product> mergeSmart(const List<Description>& desc, const List<Price>& price) {
		List<Product> priceList;
		// TODO: Add your code here to build a list of products
		//         using smart pointers
        for(size_t i=0; i<desc.size(); i++){
            for (size_t j=0; j<price.size();j++){
                if(desc[i].code==price[j].code){
                    std::unique_ptr<Product> tempProduct(new Product(desc[i].desc,price[j].price));
                    tempProduct->validate();
                    priceList+=tempProduct;
                }
            }
        }


		return priceList;
	}
}
