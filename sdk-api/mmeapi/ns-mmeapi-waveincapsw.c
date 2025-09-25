typedef struct tagWAVEINCAPSW {
  WORD      wMid;
  WORD      wPid;
  MMVERSION vDriverVersion;
  WCHAR     szPname[MAXPNAMELEN];
  DWORD     dwFormats;
  WORD      wChannels;
  WORD      wReserved1;
} WAVEINCAPSW, *PWAVEINCAPSW, *NPWAVEINCAPSW, *LPWAVEINCAPSW;