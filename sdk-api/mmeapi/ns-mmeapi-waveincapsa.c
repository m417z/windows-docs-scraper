typedef struct tagWAVEINCAPSA {
  WORD      wMid;
  WORD      wPid;
  MMVERSION vDriverVersion;
  CHAR      szPname[MAXPNAMELEN];
  DWORD     dwFormats;
  WORD      wChannels;
  WORD      wReserved1;
} WAVEINCAPSA, *PWAVEINCAPSA, *NPWAVEINCAPSA, *LPWAVEINCAPSA;