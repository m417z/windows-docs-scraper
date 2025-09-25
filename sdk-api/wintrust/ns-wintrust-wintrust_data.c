typedef struct _WINTRUST_DATA {
  DWORD                               cbStruct;
  LPVOID                              pPolicyCallbackData;
  LPVOID                              pSIPClientData;
  DWORD                               dwUIChoice;
  DWORD                               fdwRevocationChecks;
  DWORD                               dwUnionChoice;
  union {
#if ...
    WINTRUST_FILE_INFO_                *pFile;
#else
    struct WINTRUST_FILE_INFO_         *pFile;
#endif
#if ...
    WINTRUST_CATALOG_INFO_             *pCatalog;
#else
    struct WINTRUST_CATALOG_INFO_      *pCatalog;
#endif
#if ...
    WINTRUST_BLOB_INFO_                *pBlob;
#else
    struct WINTRUST_BLOB_INFO_         *pBlob;
#endif
#if ...
    WINTRUST_SGNR_INFO_                *pSgnr;
#else
    struct WINTRUST_SGNR_INFO_         *pSgnr;
#endif
#if ...
    WINTRUST_CERT_INFO_                *pCert;
#else
    struct WINTRUST_CERT_INFO_         *pCert;
#endif
#if ...
    WINTRUST_DETACHED_SIG_INFO_        *pDetachedSig;
#else
    struct WINTRUST_DETACHED_SIG_INFO_ *pDetachedSig;
#endif
  };
  DWORD                               dwStateAction;
  HANDLE                              hWVTStateData;
  WCHAR                               *pwszURLReference;
  DWORD                               dwProvFlags;
  DWORD                               dwUIContext;
  struct WINTRUST_SIGNATURE_SETTINGS_ *pSignatureSettings;
} WINTRUST_DATA, *PWINTRUST_DATA;