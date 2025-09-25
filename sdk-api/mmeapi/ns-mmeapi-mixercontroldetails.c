typedef struct tMIXERCONTROLDETAILS {
  DWORD  cbStruct;
  DWORD  dwControlID;
  DWORD  cChannels;
  union {
    HWND  hwndOwner;
    DWORD cMultipleItems;
  } DUMMYUNIONNAME;
  DWORD  cbDetails;
  LPVOID paDetails;
} MIXERCONTROLDETAILS, *PMIXERCONTROLDETAILS, *LPMIXERCONTROLDETAILS;