typedef struct _CRYPT_PROVIDER_SGNR {
  DWORD                       cbStruct;
  FILETIME                    sftVerifyAsOf;
  DWORD                       csCertChain;
  struct _CRYPT_PROVIDER_CERT *pasCertChain;
  DWORD                       dwSignerType;
  CMSG_SIGNER_INFO            *psSigner;
  DWORD                       dwError;
  DWORD                       csCounterSigners;
  struct _CRYPT_PROVIDER_SGNR *pasCounterSigners;
  PCCERT_CHAIN_CONTEXT        pChainContext;
} CRYPT_PROVIDER_SGNR, *PCRYPT_PROVIDER_SGNR;