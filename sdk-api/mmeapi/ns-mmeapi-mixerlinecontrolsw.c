typedef struct tagMIXERLINECONTROLSW {
  DWORD           cbStruct;
  DWORD           dwLineID;
  union {
    DWORD dwControlID;
    DWORD dwControlType;
  } DUMMYUNIONNAME;
  DWORD           cControls;
  DWORD           cbmxctrl;
  LPMIXERCONTROLW pamxctrl;
} MIXERLINECONTROLSW, *PMIXERLINECONTROLSW, *LPMIXERLINECONTROLSW;