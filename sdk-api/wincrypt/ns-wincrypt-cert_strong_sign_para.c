typedef struct _CERT_STRONG_SIGN_PARA {
  DWORD cbSize;
  DWORD dwInfoChoice;
  union {
    void                              *pvInfo;
    PCERT_STRONG_SIGN_SERIALIZED_INFO pSerializedInfo;
    LPSTR                             pszOID;
  } DUMMYUNIONNAME;
} CERT_STRONG_SIGN_PARA, *PCERT_STRONG_SIGN_PARA;