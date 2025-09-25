typedef struct _DXGK_POWER_COMPONENT_FLAGS {
  union {
    struct {
      UINT Reserved0 : 1;
      UINT DriverCompletesFStateTransition : 1;
      UINT TransitionTo_F0_OnDx : 1;
      UINT NoDebounce : 1;
      UINT ActiveInD3 : 1;
#if ...
      UINT Reserved : 27;
#else
      UINT Reserved : 29;
#endif
    };
    UINT Value;
  };
} DXGK_POWER_COMPONENT_FLAGS;