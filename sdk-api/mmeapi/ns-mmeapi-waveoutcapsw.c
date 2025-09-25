typedef struct tagWAVEOUTCAPSW {
  WORD      wMid;
  WORD      wPid;
  MMVERSION vDriverVersion;
  WCHAR     szPname[MAXPNAMELEN];
  DWORD     dwFormats;
  WORD      wChannels;
  WORD      wReserved1;
  DWORD     dwSupport;
} WAVEOUTCAPSW, *PWAVEOUTCAPSW, *NPWAVEOUTCAPSW, *LPWAVEOUTCAPSW;