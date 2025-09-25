typedef struct midioutcaps_tag {
  WORD    wMid;
  WORD    wPid;
  VERSION vDriverVersion;
  char    szPname[MAXPNAMELEN];
  WORD    wTechnology;
  WORD    wVoices;
  WORD    wNotes;
  WORD    wChannelMask;
  DWORD   dwSupport;
} MIDIOUTCAPS, *PMIDIOUTCAPS, *NPMIDIOUTCAPS, *LPMIDIOUTCAPS;