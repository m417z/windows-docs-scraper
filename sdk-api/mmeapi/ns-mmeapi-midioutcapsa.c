typedef struct tagMIDIOUTCAPSA {
  WORD      wMid;
  WORD      wPid;
  MMVERSION vDriverVersion;
  CHAR      szPname[MAXPNAMELEN];
  WORD      wTechnology;
  WORD      wVoices;
  WORD      wNotes;
  WORD      wChannelMask;
  DWORD     dwSupport;
} MIDIOUTCAPSA, *PMIDIOUTCAPSA, *NPMIDIOUTCAPSA, *LPMIDIOUTCAPSA;