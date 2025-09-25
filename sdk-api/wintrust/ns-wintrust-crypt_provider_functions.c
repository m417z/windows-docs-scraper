typedef struct _CRYPT_PROVIDER_FUNCTIONS {
  DWORD                             cbStruct;
  PFN_CPD_MEM_ALLOC                 pfnAlloc;
  PFN_CPD_MEM_FREE                  pfnFree;
  PFN_CPD_ADD_STORE                 pfnAddStore2Chain;
  PFN_CPD_ADD_SGNR                  pfnAddSgnr2Chain;
  PFN_CPD_ADD_CERT                  pfnAddCert2Chain;
  PFN_CPD_ADD_PRIVDATA              pfnAddPrivData2Chain;
  PFN_PROVIDER_INIT_CALL            pfnInitialize;
  PFN_PROVIDER_OBJTRUST_CALL        pfnObjectTrust;
  PFN_PROVIDER_SIGTRUST_CALL        pfnSignatureTrust;
  PFN_PROVIDER_CERTTRUST_CALL       pfnCertificateTrust;
  PFN_PROVIDER_FINALPOLICY_CALL     pfnFinalPolicy;
  PFN_PROVIDER_CERTCHKPOLICY_CALL   pfnCertCheckPolicy;
  PFN_PROVIDER_TESTFINALPOLICY_CALL pfnTestFinalPolicy;
  struct _CRYPT_PROVUI_FUNCS        *psUIpfns;
  PFN_PROVIDER_CLEANUP_CALL         pfnCleanupPolicy;
} CRYPT_PROVIDER_FUNCTIONS, *PCRYPT_PROVIDER_FUNCTIONS;