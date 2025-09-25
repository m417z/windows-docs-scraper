typedef struct {
  KSPROPERTY Property;
  union {
    DEVCAPS Capabilities;
    ULONG   DevPort;
    ULONG   PowerState;
    WCHAR   pawchString[MAX_PATH];
    DWORD   NodeUniqueID[2];
  } u;
} KSPROPERTY_EXTDEVICE_S, *PKSPROPERTY_EXTDEVICE_S;