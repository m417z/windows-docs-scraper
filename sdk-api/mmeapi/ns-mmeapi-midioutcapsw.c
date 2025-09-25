typedef struct tagMIDIOUTCAPSW {
  WORD      wMid;
  WORD      wPid;
  MMVERSION vDriverVersion;
  WCHAR     szPname[MAXPNAMELEN];
  WORD      wTechnology;
  WORD      wVoices;
  WORD      wNotes;
  WORD      wChannelMask;
  DWORD     dwSupport;
} MIDIOUTCAPSW, *PMIDIOUTCAPSW, *NPMIDIOUTCAPSW, *LPMIDIOUTCAPSW;