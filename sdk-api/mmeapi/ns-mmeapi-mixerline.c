typedef struct tMIXERLINE {
  DWORD  cbStruct;
  DWORD  dwDestination;
  DWORD  dwSource;
  DWORD  dwLineID;
  DWORD  fdwLine;
  DWORD  dwUser;
  DWORD  dwComponentType;
  DWORD  cChannels;
  DWORD  cConnections;
  DWORD  cControls;
  char   szShortName[MIXER_SHORT_NAME_CHARS];
  char   szName[MIXER_LONG_NAME_CHARS];
  struct {
    DWORD   dwType;
    DWORD   dwDeviceID;
    WORD    wMid;
    WORD    wPid;
    VERSION vDriverVersion;
    char    szPname[MAXPNAMELEN];
  } Target;
} MIXERLINE, *PMIXERLINE, *LPMIXERLINE;