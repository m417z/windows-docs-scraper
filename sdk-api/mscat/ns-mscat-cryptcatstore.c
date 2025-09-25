typedef struct CRYPTCATSTORE_ {
  DWORD      cbStruct;
  DWORD      dwPublicVersion;
  LPWSTR     pwszP7File;
  HCRYPTPROV hProv;
  DWORD      dwEncodingType;
  DWORD      fdwStoreFlags;
  HANDLE     hReserved;
  HANDLE     hAttrs;
  HCRYPTMSG  hCryptMsg;
  HANDLE     hSorted;
} CRYPTCATSTORE;