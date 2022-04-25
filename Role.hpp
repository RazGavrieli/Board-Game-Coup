
namespace coup
{
    class Role {
        int amountOfCoins;

        public:        
        int coins();
        void income();
        void foreign_aid();
        void coup(Role);
        
        /*specific role actions*/
        void transfer(Role, Role);
        void tax();
        void steal(Role);
        void block(Role);
        


    };
} // namespace coup