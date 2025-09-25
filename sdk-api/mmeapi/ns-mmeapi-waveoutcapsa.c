typedef struct tagWAVEOUTCAPSA {
  WORD      wMid;
  WORD      wPid;
  MMVERSION vDriverVersion;
  CHAR      szPname[MAXPNAMELEN];
  DWORD     dwFormats;
  WORD      wChannels;
  WORD      wReserved1;
  DWORD     dwSupport;
} WAVEOUTCAPSA, *PWAVEOUTCAPSA, *NPWAVEOUTCAPSA, *LPWAVEOUTCAPSA;