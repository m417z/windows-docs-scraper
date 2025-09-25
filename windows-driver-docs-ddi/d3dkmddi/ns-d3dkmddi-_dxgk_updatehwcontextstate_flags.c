typedef struct _DXGK_UPDATEHWCONTEXTSTATE_FLAGS {
  union {
    struct {
      UINT Suspended : 1;
      UINT InterruptOnSwitchCompletion : 1;
      UINT Reserved : 30;
    };
    UINT Value;
  };
} DXGK_UPDATEHWCONTEXTSTATE_FLAGS;