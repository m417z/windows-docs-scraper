typedef struct _CERT_RDN_ATTR {
  LPSTR               pszObjId;
  DWORD               dwValueType;
  CERT_RDN_VALUE_BLOB Value;
} CERT_RDN_ATTR, *PCERT_RDN_ATTR;