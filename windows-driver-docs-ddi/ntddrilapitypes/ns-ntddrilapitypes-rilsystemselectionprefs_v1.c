typedef struct RILSYSTEMSELECTIONPREFS_V1 {
  DWORD                              cbSize;
  DWORD                              dwParams;
  DWORD                              dwExecutor;
  DWORD                              dwSystemTypes;
  RILSYSTEMSELECTIONPREFSMODE        dwMode;
  RILOPERATORNAMES                   plmnInfo;
  RILSYSTEMSELECTIONPREFSROAMINGMODE dwRoamingMode;
} RILSYSTEMSELECTIONPREFS_V1, *LPRILSYSTEMSELECTIONPREFS_V1;