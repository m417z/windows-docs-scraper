typedef struct _CRYPT_PROVIDER_PRIVDATA {
  DWORD cbStruct;
  GUID  gProviderID;
  DWORD cbProvData;
  void  *pvProvData;
} CRYPT_PROVIDER_PRIVDATA, *PCRYPT_PROVIDER_PRIVDATA;