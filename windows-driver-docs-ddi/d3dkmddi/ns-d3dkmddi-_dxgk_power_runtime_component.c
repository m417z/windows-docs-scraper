typedef struct _DXGK_POWER_RUNTIME_COMPONENT {
  ULONG                        StateCount;
  DXGK_POWER_RUNTIME_STATE     States[DXGK_MAX_F_STATES];
  DXGK_POWER_COMPONENT_MAPPING ComponentMapping;
  DXGK_POWER_COMPONENT_FLAGS   Flags;
  GUID                         ComponentGuid;
  UCHAR                        ComponentName[DXGK_POWER_COMPONENT_NAME_SIZE];
  ULONG                        ProviderCount;
  ULONG                        Providers[DXGK_MAX_POWER_COMPONENT_PROVIDERS];
} DXGK_POWER_RUNTIME_COMPONENT;