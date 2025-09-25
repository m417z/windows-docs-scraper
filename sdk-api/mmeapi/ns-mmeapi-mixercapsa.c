typedef struct tagMIXERCAPSA {
  WORD      wMid;
  WORD      wPid;
  MMVERSION vDriverVersion;
  CHAR      szPname[MAXPNAMELEN];
  DWORD     fdwSupport;
  DWORD     cDestinations;
} MIXERCAPSA, *PMIXERCAPSA, *LPMIXERCAPSA;