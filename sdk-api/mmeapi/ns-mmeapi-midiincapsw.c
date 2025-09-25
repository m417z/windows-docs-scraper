typedef struct tagMIDIINCAPSW {
  WORD      wMid;
  WORD      wPid;
  MMVERSION vDriverVersion;
  WCHAR     szPname[MAXPNAMELEN];
  DWORD     dwSupport;
} MIDIINCAPSW, *PMIDIINCAPSW, *NPMIDIINCAPSW, *LPMIDIINCAPSW;