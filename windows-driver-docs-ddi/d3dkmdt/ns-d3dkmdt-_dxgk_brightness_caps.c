typedef struct _DXGK_BRIGHTNESS_CAPS {
  union {
    struct {
      UINT SmoothBrightness : 1;
      UINT AdaptiveBrightness : 1;
      UINT NitsBrightness : 1;
      UINT Reserved : 29;
    };
    [in] UINT Value;
  };
} DXGK_BRIGHTNESS_CAPS;