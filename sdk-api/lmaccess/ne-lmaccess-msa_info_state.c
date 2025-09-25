typedef enum _MSA_INFO_STATE {
  MsaInfoNotExist = 1,
  MsaInfoNotService,
  MsaInfoCannotInstall,
  MsaInfoCanInstall,
  MsaInfoInstalled
} MSA_INFO_STATE, *PMSA_INFO_STATE;