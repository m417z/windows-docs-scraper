typedef struct tagAUXCAPSW {
  WORD      wMid;
  WORD      wPid;
  MMVERSION vDriverVersion;
  WCHAR     szPname[MAXPNAMELEN];
  WORD      wTechnology;
  WORD      wReserved1;
  DWORD     dwSupport;
} AUXCAPSW, *PAUXCAPSW, *NPAUXCAPSW, *LPAUXCAPSW;