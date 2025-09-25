typedef struct _CERT_NAME_VALUE {
  DWORD               dwValueType;
  CERT_RDN_VALUE_BLOB Value;
} CERT_NAME_VALUE, *PCERT_NAME_VALUE;