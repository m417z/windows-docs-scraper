typedef struct tagMIXERCONTROLW {
  DWORD cbStruct;
  DWORD dwControlID;
  DWORD dwControlType;
  DWORD fdwControl;
  DWORD cMultipleItems;
  WCHAR szShortName[MIXER_SHORT_NAME_CHARS];
  WCHAR szName[MIXER_LONG_NAME_CHARS];
  union {
    struct {
      LONG lMinimum;
      LONG lMaximum;
    } DUMMYSTRUCTNAME;
    struct {
      DWORD dwMinimum;
      DWORD dwMaximum;
    } DUMMYSTRUCTNAME2;
    DWORD dwReserved[6];
  } Bounds;
  union {
    DWORD cSteps;
    DWORD cbCustomData;
    DWORD dwReserved[6];
  } Metrics;
} MIXERCONTROLW, *PMIXERCONTROLW, *LPMIXERCONTROLW;