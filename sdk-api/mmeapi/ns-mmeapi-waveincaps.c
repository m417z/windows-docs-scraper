typedef struct waveincaps_tag {
  WORD    wMid;
  WORD    wPid;
  VERSION vDriverVersion;
  char    szPname[MAXPNAMELEN];
  DWORD   dwFormats;
  WORD    wChannels;
} WAVEINCAPS, *PWAVEINCAPS, *NPWAVEINCAPS, *LPWAVEINCAPS;