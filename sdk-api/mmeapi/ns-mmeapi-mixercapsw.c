typedef struct tagMIXERCAPSW {
  WORD      wMid;
  WORD      wPid;
  MMVERSION vDriverVersion;
  WCHAR     szPname[MAXPNAMELEN];
  DWORD     fdwSupport;
  DWORD     cDestinations;
} MIXERCAPSW, *PMIXERCAPSW, *LPMIXERCAPSW;