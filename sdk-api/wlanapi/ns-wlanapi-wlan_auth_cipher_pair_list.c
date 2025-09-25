typedef struct _WLAN_AUTH_CIPHER_PAIR_LIST {
  DWORD                  dwNumberOfItems;
#if ...
  DOT11_AUTH_CIPHER_PAIR *pAuthCipherPairList[];
#else
  DOT11_AUTH_CIPHER_PAIR pAuthCipherPairList[1];
#endif
} WLAN_AUTH_CIPHER_PAIR_LIST, *PWLAN_AUTH_CIPHER_PAIR_LIST;