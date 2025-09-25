typedef struct _DXGKARG_SETTRACKEDWORKLOADPOWERLEVEL {
  UINT                             PowerLevel;
  UINT                             EffectivePowerLevel;
  DXGK_TRACKEDWORKLOAD_STATE_FLAGS Flags;
} DXGKARG_SETTRACKEDWORKLOADPOWERLEVEL;