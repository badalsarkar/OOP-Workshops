// Workshop 8 - Smart Pointers
// 2019/11 - Cornel


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
        //use for_each algorithm to loop through desc list
        //use find algorithm to find the code in desc list in the price list
        //if found, create a product and push to priceList
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
}
