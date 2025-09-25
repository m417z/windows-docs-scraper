typedef struct _CERT_STORE_PROV_INFO {
  DWORD             cbSize;
  DWORD             cStoreProvFunc;
  void              **rgpvStoreProvFunc;
  HCERTSTOREPROV    hStoreProv;
  DWORD             dwStoreProvFlags;
  HCRYPTOIDFUNCADDR hStoreProvFuncAddr2;
} CERT_STORE_PROV_INFO, *PCERT_STORE_PROV_INFO;