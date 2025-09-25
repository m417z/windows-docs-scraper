typedef struct _CRYPT_PROVIDER_DATA {
  DWORD                               cbStruct;
  WINTRUST_DATA                       *pWintrustData;
  BOOL                                fOpenedFile;
  HWND                                hWndParent;
  GUID                                *pgActionID;
  HCRYPTPROV                          hProv;
  DWORD                               dwError;
  DWORD                               dwRegSecuritySettings;
  DWORD                               dwRegPolicySettings;
  struct _CRYPT_PROVIDER_FUNCTIONS    *psPfns;
  DWORD                               cdwTrustStepErrors;
  DWORD                               *padwTrustStepErrors;
  DWORD                               chStores;
  HCERTSTORE                          *pahStores;
  DWORD                               dwEncoding;
  HCRYPTMSG                           hMsg;
  DWORD                               csSigners;
  struct _CRYPT_PROVIDER_SGNR         *pasSigners;
  DWORD                               csProvPrivData;
  struct _CRYPT_PROVIDER_PRIVDATA     *pasProvPrivData;
  DWORD                               dwSubjectChoice;
  union {
#if ...
    _PROVDATA_SIP        *pPDSip;
#else
    struct _PROVDATA_SIP *pPDSip;
#endif
  };
  char                                *pszUsageOID;
  BOOL                                fRecallWithState;
  FILETIME                            sftSystemTime;
  char                                *pszCTLSignerUsageOID;
  DWORD                               dwProvFlags;
  DWORD                               dwFinalError;
  PCERT_USAGE_MATCH                   pRequestUsage;
  DWORD                               dwTrustPubSettings;
  DWORD                               dwUIStateFlags;
  struct _CRYPT_PROVIDER_SIGSTATE     *pSigState;
  struct WINTRUST_SIGNATURE_SETTINGS_ *pSigSettings;
} CRYPT_PROVIDER_DATA, *PCRYPT_PROVIDER_DATA;