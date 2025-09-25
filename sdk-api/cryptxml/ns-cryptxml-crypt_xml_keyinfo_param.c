typedef struct _CRYPT_XML_KEYINFO_PARAM {
  LPCWSTR   wszId;
  LPCWSTR   wszKeyName;
  CERT_BLOB SKI;
  LPCWSTR   wszSubjectName;
  ULONG     cCertificate;
  CERT_BLOB *rgCertificate;
  ULONG     cCRL;
  CERT_BLOB *rgCRL;
} CRYPT_XML_KEYINFO_PARAM;