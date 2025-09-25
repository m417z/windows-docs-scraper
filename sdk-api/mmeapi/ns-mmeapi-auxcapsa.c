typedef struct tagAUXCAPSA {
  WORD      wMid;
  WORD      wPid;
  MMVERSION vDriverVersion;
  CHAR      szPname[MAXPNAMELEN];
  WORD      wTechnology;
  WORD      wReserved1;
  DWORD     dwSupport;
} AUXCAPSA, *PAUXCAPSA, *NPAUXCAPSA, *LPAUXCAPSA;