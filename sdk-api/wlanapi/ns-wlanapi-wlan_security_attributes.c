typedef struct _WLAN_SECURITY_ATTRIBUTES {
  BOOL                   bSecurityEnabled;
  BOOL                   bOneXEnabled;
  DOT11_AUTH_ALGORITHM   dot11AuthAlgorithm;
  DOT11_CIPHER_ALGORITHM dot11CipherAlgorithm;
} WLAN_SECURITY_ATTRIBUTES, *PWLAN_SECURITY_ATTRIBUTES;