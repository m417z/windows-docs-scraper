typedef struct {
  [in]  IN USHORT                                        Size;
  [in]  IN USHORT                                        Version;
  [out] OUT PVOID                                        Context;
  [out] OUT PINTERFACE_REFERENCE                         InterfaceReference;
  [out] OUT PINTERFACE_DEREFERENCE                       InterfaceDereference;
  [out] OUT DXGK_BRIGHTNESS_SET_3                        SetBrightness;
  [out] OUT DXGK_BRIGHTNESS_GET_3                        GetBrightness;
  [out] OUT DXGK_BRIGHTNESS_GET_CAPS_3                   GetBrightnessCaps;
  [out] OUT DXGK_BRIGHTNESS_GET_NIT_RANGES               GetNitRanges;
  [out] OUT DXGK_BRIGHTNESS_SET_BACKLIGHT_OPTIMIZATION_3 SetBacklightOptimization;
} DXGK_BRIGHTNESS_INTERFACE_3, *PDXGK_BRIGHTNESS_INTERFACE_3;