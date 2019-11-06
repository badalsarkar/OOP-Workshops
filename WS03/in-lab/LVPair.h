
namespace sdds{
    template <class L, class V>
    class LVPair{
        L Lkey;
        V Lvalue;
        public:
        LVPair():Lkey(L()),Lvalue(V()){}
        LVPair(const L& aa, const V& bb){
           Lkey=aa;
           Lvalue=bb;
        }
        const L& key() const{
            return Lkey;
        }
        const V& value() const{
            return Lvalue;
        }
        void display(std::ostream& os)const{
            os<<Lkey<<" : "<<Lvalue<<std::endl;
        }
    };

    template<class L, class V>
    std::ostream& operator<<(std::ostream& os, const sdds::LVPair<L, V>& pair){
        pair.display(std::cout);
        return os;
    }
  
}
