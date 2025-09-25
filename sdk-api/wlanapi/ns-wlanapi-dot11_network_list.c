typedef struct _DOT11_NETWORK_LIST {
  DWORD         dwNumberOfItems;
  DWORD         dwIndex;
#if ...
  DOT11_NETWORK *Network[];
#else
  DOT11_NETWORK Network[1];
#endif
} DOT11_NETWORK_LIST, *PDOT11_NETWORK_LIST;