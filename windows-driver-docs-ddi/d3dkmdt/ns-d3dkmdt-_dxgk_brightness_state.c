typedef struct _DXGK_BRIGHTNESS_STATE {
  union {
    struct {
      UINT SmoothBrightness : 1;
      UINT Reserved : 31;
    };
    [in] UINT Value;
  };
} DXGK_BRIGHTNESS_STATE;