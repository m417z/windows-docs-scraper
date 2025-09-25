typedef struct RILUICCSERVICEPARAMS {
  RILUICCSERVICE        service;
  BOOL                  fHasLockVerification;
  RILUICCLOCKCREDENTIAL lockCredential;
  BOOL                  fEnable;
} RILUICCSERVICEPARAMS, *LPRILUICCSERVICEPARAMS;