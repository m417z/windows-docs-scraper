typedef struct _D3DKMT_BRIGHTNESS_INFO {
  D3DKMT_BRIGHTNESS_INFO_TYPE Type;
  ULONG                       ChildUid;
  union {
    D3DKMT_BRIGHTNESS_POSSIBLE_LEVELS   PossibleLevels;
    UCHAR                               Brightness;
    DXGK_BRIGHTNESS_CAPS                BrightnessCaps;
    DXGK_BRIGHTNESS_STATE               BrightnessState;
    DXGK_BACKLIGHT_OPTIMIZATION_LEVEL   OptimizationLevel;
    DXGK_BACKLIGHT_INFO                 ReductionInfo;
    BOOLEAN                             VerboseLogging;
    DXGK_BRIGHTNESS_GET_NIT_RANGES_OUT  NitRanges;
    DXGK_BRIGHTNESS_GET_OUT             GetBrightnessMillinits;
    DXGK_BRIGHTNESS_SET_IN              SetBrightnessMillinits;
    D3DKMT_BRIGHTNESS_INTERFACE_VERSION BrightnessInterfaceSupported;
  };
} D3DKMT_BRIGHTNESS_INFO;