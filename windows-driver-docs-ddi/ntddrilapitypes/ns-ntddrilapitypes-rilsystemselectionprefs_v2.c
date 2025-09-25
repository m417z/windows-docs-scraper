typedef struct RILSYSTEMSELECTIONPREFS_V2 {
  DWORD                              cbSize;
  DWORD                              dwParams;
  DWORD                              dwExecutor;
  DWORD                              dwSystemTypes;
  RILSYSTEMSELECTIONPREFSMODE        dwMode;
  RILOPERATORNAMES                   plmnInfo;
  RILSYSTEMSELECTIONPREFSROAMINGMODE dwRoamingMode;
  DWORD                              dwAcquisitionOrderSize;
  DWORD                              AcquisitionOrder[16];
} RILSYSTEMSELECTIONPREFS_V2, *LPRILSYSTEMSELECTIONPREFS_V2, RILSYSTEMSELECTIONPREFS, *LPRILSYSTEMSELECTIONPREFS;