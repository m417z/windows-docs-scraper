typedef struct RILSENDRESTRICTEDUICCCMDPARAMS {
  DWORD                 cbSize;
  RILUICCCOMMAND        dwCommand;
  RILUICCCMDPARAMETERS  rscpParameters;
  BOOL                  fHasLockVerification;
  RILUICCLOCKCREDENTIAL lockVerification;
  DWORD                 dwDataSize;
  BYTE                  pbData[1];
} RILSENDRESTRICTEDUICCCMDPARAMS, *LPRILSENDRESTRICTEDUICCCMDPARAMS;