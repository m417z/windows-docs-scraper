typedef struct _CRYPT_PROVIDER_SIGSTATE {
  DWORD                               cbStruct;
  HCRYPTMSG                           *rhSecondarySigs;
  HCRYPTMSG                           hPrimarySig;
  BOOL                                fFirstAttemptMade;
  BOOL                                fNoMoreSigs;
  DWORD                               cSecondarySigs;
  DWORD                               dwCurrentIndex;
  BOOL                                fSupportMultiSig;
  DWORD                               dwCryptoPolicySupport;
  DWORD                               iAttemptCount;
  BOOL                                fCheckedSealing;
  struct _SEALING_SIGNATURE_ATTRIBUTE *pSealingSignature;
} CRYPT_PROVIDER_SIGSTATE, *PCRYPT_PROVIDER_SIGSTATE;