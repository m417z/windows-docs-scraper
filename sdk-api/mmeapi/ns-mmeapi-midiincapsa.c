typedef struct tagMIDIINCAPSA {
  WORD      wMid;
  WORD      wPid;
  MMVERSION vDriverVersion;
  CHAR      szPname[MAXPNAMELEN];
  DWORD     dwSupport;
} MIDIINCAPSA, *PMIDIINCAPSA, *NPMIDIINCAPSA, *LPMIDIINCAPSA;