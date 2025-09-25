typedef union _DXGK_MODE_BEHAVIOR_FLAGS {
  struct {
    UINT PrioritizeHDR : 1;
    UINT ColorimetricControl : 1;
    UINT Reserved : 30;
  };
  UINT   Value;
} DXGK_MODE_BEHAVIOR_FLAGS;