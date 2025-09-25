typedef struct _CREDSSP_CRED {
  CREDSPP_SUBMIT_TYPE Type;
  PVOID               pSchannelCred;
  PVOID               pSpnegoCred;
} CREDSSP_CRED, *PCREDSSP_CRED;