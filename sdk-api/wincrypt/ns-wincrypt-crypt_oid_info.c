typedef struct _CRYPT_OID_INFO {
  DWORD           cbSize;
  LPCSTR          pszOID;
  LPCWSTR         pwszName;
  DWORD           dwGroupId;
  union {
    DWORD  dwValue;
    ALG_ID Algid;
    DWORD  dwLength;
  } DUMMYUNIONNAME;
  CRYPT_DATA_BLOB ExtraInfo;
  LPCWSTR         pwszCNGAlgid;
  LPCWSTR         pwszCNGExtraAlgid;
} CRYPT_OID_INFO, *PCRYPT_OID_INFO;