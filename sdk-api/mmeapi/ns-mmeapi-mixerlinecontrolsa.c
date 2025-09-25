typedef struct tagMIXERLINECONTROLSA {
  DWORD           cbStruct;
  DWORD           dwLineID;
  union {
    DWORD dwControlID;
    DWORD dwControlType;
  } DUMMYUNIONNAME;
  DWORD           cControls;
  DWORD           cbmxctrl;
  LPMIXERCONTROLA pamxctrl;
} MIXERLINECONTROLSA, *PMIXERLINECONTROLSA, *LPMIXERLINECONTROLSA;