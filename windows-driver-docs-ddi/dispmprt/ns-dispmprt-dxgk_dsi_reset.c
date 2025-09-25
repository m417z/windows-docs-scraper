typedef struct _DXGK_DSI_RESET {
  UINT  Flags;
  union {
    struct {
      UINT MipiErrors : 16;
      UINT ResetFailed : 1;
      UINT NeedModeSet : 1;
    };
    UINT Results;
  };
} DXGK_DSI_RESET, *PDXGK_DSI_RESET;