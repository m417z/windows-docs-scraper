typedef struct _CERT_PHYSICAL_STORE_INFO {
  DWORD           cbSize;
  LPSTR           pszOpenStoreProvider;
  DWORD           dwOpenEncodingType;
  DWORD           dwOpenFlags;
  CRYPT_DATA_BLOB OpenParameters;
  DWORD           dwFlags;
  DWORD           dwPriority;
} CERT_PHYSICAL_STORE_INFO, *PCERT_PHYSICAL_STORE_INFO;