typedef struct waveoutcaps_tag {
  WORD    wMid;
  WORD    wPid;
  VERSION vDriverVersion;
  char    szPname[MAXPNAMELEN];
  DWORD   dwFormats;
  WORD    wChannels;
  DWORD   dwSupport;
} WAVEOUTCAPS, *PWAVEOUTCAPS, *NPWAVEOUTCAPS, *LPWAVEOUTCAPS;