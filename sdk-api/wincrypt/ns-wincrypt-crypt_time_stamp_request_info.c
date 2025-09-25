typedef struct _CRYPT_TIME_STAMP_REQUEST_INFO {
  LPSTR            pszTimeStampAlgorithm;
  LPSTR            pszContentType;
  CRYPT_OBJID_BLOB Content;
  DWORD            cAttribute;
  PCRYPT_ATTRIBUTE rgAttribute;
} CRYPT_TIME_STAMP_REQUEST_INFO, *PCRYPT_TIME_STAMP_REQUEST_INFO;