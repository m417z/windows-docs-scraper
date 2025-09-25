typedef struct _CRYPT_ATTRIBUTE {
  LPSTR            pszObjId;
  DWORD            cValue;
  PCRYPT_ATTR_BLOB rgValue;
} CRYPT_ATTRIBUTE, *PCRYPT_ATTRIBUTE;