typedef struct _CERT_EXTENSION {
  LPSTR            pszObjId;
  BOOL             fCritical;
  CRYPT_OBJID_BLOB Value;
} CERT_EXTENSION, *PCERT_EXTENSION;