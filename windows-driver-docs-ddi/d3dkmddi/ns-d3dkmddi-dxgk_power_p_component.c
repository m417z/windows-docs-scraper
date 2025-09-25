typedef struct _DXGK_POWER_P_COMPONENT {
  ULONG                        StateCount;
  DXGK_POWER_P_STATE           States[DXGK_MAX_P_STATES];
  DXGK_POWER_COMPONENT_P_FLAGS Flags;
} DXGK_POWER_P_COMPONENT;