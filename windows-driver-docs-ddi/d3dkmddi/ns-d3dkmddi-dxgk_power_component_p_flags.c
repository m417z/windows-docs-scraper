typedef struct _DXGK_POWER_COMPONENT_P_FLAGS {
  union {
    struct {
      UINT Reserved : 32;
    };
    UINT Value;
  };
} DXGK_POWER_COMPONENT_P_FLAGS;