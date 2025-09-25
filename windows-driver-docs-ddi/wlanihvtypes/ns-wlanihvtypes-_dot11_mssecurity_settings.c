typedef struct _DOT11_MSSECURITY_SETTINGS {
  DOT11_AUTH_ALGORITHM   dot11AuthAlgorithm;
  DOT11_CIPHER_ALGORITHM dot11CipherAlgorithm;
  BOOL                   fOneXEnabled;
  EAP_METHOD_TYPE        eapMethodType;
  DWORD                  dwEapConnectionDataLen;
  BYTE                   *pEapConnectionData;
} DOT11_MSSECURITY_SETTINGS, *PDOT11_MSSECURITY_SETTINGS;