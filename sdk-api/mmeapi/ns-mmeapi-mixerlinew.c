typedef struct tagMIXERLINEW {
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
  WCHAR     szShortName[MIXER_SHORT_NAME_CHARS];
  WCHAR     szName[MIXER_LONG_NAME_CHARS];
  struct {
    DWORD     dwType;
    DWORD     dwDeviceID;
    WORD      wMid;
    WORD      wPid;
    MMVERSION vDriverVersion;
    WCHAR     szPname[MAXPNAMELEN];
  } Target;
} MIXERLINEW, *PMIXERLINEW, *LPMIXERLINEW;