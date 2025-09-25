typedef struct midiincaps_tag {
  WORD    wMid;
  WORD    wPid;
  VERSION vDriverVersion;
  char    szPname[MAXPNAMELEN];
  DWORD   dwSupport;
} MIDIINCAPS, *PMIDIINCAPS, *NPMIDIINCAPS, *LPMIDIINCAPS;