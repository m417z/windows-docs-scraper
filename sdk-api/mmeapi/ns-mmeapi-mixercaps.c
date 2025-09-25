typedef struct tMIXERCAPS {
  WORD    wMid;
  WORD    wPid;
  VERSION vDriverVersion;
  char    szPname[MAXPNAMELEN];
  DWORD   fdwSupport;
  DWORD   cDestinations;
} MIXERCAPS, *PMIXERCAPS, *LPMIXERCAPS;