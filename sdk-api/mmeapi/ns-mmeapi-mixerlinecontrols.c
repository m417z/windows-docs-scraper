typedef struct tMIXERLINECONTROLS {
  DWORD          cbStruct;
  DWORD          dwLineID;
  union {
    DWORD dwControlID;
    DWORD dwControlType;
  };
  DWORD          cControls;
  DWORD          cbmxctrl;
  LPMIXERCONTROL pamxctrl;
} MIXERLINECONTROLS, *PMIXERLINECONTROLS, *LPMIXERLINECONTROLS;