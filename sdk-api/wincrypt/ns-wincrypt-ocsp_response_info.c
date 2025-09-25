typedef struct _OCSP_RESPONSE_INFO {
  DWORD            dwStatus;
  LPSTR            pszObjId;
  CRYPT_OBJID_BLOB Value;
} OCSP_RESPONSE_INFO, *POCSP_RESPONSE_INFO;