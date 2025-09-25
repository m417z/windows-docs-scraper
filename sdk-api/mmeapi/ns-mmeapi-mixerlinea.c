typedef struct tagMIXERLINEA {
  DWORD     cbStruct;
  DWORD     dwDestination;
  DWORD     dwSource;
  DWORD     dwLineID;
  DWORD     fdwLine;
  DWORD_PTR dwUser;
  DWORD     dwComponentType;
  DWORD     cChannels;
  DWORD     cConnections;
  DWORD     cControls;
  CHAR      szShortName[MIXER_SHORT_NAME_CHARS];
  CHAR      szName[MIXER_LONG_NAME_CHARS];
  struct {
    DWORD     dwType;
    DWORD     dwDeviceID;
    WORD      wMid;
    WORD      wPid;
    MMVERSION vDriverVersion;
    CHAR      szPname[MAXPNAMELEN];
  } Target;
} MIXERLINEA, *PMIXERLINEA, *LPMIXERLINEA;