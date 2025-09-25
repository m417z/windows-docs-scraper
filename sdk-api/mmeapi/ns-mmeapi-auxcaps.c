typedef struct auxcaps_tag {
  WORD    wMid;
  WORD    wPid;
  VERSION vDriverVersion;
  char    szPname[MAXPNAMELEN];
  WORD    wTechnology;
  DWORD   dwSupport;
} AUXCAPS, *PAUXCAPS, *NPAUXCAPS, *LPAUXCAPS;