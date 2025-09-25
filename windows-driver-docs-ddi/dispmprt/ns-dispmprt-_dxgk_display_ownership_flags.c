typedef struct _DXGK_DISPLAY_OWNERSHIP_FLAGS {
  union {
    struct {
      DXGK_FRAMEBUFFER_STATE FrameBufferState : 4;
    };
    UINT Value;
  };
} DXGK_DISPLAY_OWNERSHIP_FLAGS, *PDXGK_DISPLAY_OWNERSHIP_FLAGS;