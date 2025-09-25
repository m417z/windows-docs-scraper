typedef struct _CERT_ALT_NAME_ENTRY {
  DWORD dwAltNameChoice;
  union {
    PCERT_OTHER_NAME pOtherName;
    LPWSTR           pwszRfc822Name;
    LPWSTR           pwszDNSName;
    CERT_NAME_BLOB   DirectoryName;
    LPWSTR           pwszURL;
    CRYPT_DATA_BLOB  IPAddress;
    LPSTR            pszRegisteredID;
  } DUMMYUNIONNAME;
} CERT_ALT_NAME_ENTRY, *PCERT_ALT_NAME_ENTRY;