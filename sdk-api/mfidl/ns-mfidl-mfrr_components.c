typedef struct _MFRR_COMPONENTS {
  DWORD                     dwRRInfoVersion;
  DWORD                     dwRRComponents;
  PMFRR_COMPONENT_HASH_INFO pRRComponents;
} MFRR_COMPONENTS, *PMFRR_COMPONENTS;