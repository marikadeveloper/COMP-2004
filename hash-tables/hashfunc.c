/* Here are some of the hash functions */
/* for strings that are in the text */

typedef unsigned int Index;


        Index
        Hash1( const char *Key, int TableSize )
        {
            unsigned int HashVal = 0;

/* 1*/      while( *Key != '\0' )
/* 2*/          HashVal += *Key++;

/* 3*/      return HashVal % TableSize;
        }

        Index
        Hash2( const char *Key, int TableSize )
        {
            return ( Key[ 0 ] + 27 * Key[ 1 ] + 729 * Key[ 2 ] )
                        % TableSize;
        }

        Index
        Hash3( const char *Key, int TableSize )
        {
            unsigned int HashVal = 0;

/* 1*/      while( *Key != '\0' )
/* 2*/          HashVal = ( HashVal << 5 ) + *Key++;

/* 3*/      return HashVal % TableSize;
        }

