typedef struct {
  [in]  IN USHORT                                      Size;
  [in]  IN USHORT                                      Version;
  [in]  OUT PVOID                                      Context;
  [out] OUT PINTERFACE_REFERENCE                       InterfaceReference;
  [out] OUT PINTERFACE_DEREFERENCE                     InterfaceDereference;
  [out] OUT DXGK_BRIGHTNESS_GET_POSSIBLE               GetPossibleBrightness;
  [out] OUT DXGK_BRIGHTNESS_SET                        SetBrightness;
  [out] OUT DXGK_BRIGHTNESS_GET                        GetBrightness;
  [out] OUT DXGK_BRIGHTNESS_GET_CAPS                   GetBrightnessCaps;
  [out] OUT DXGK_BRIGHTNESS_SET_STATE                  SetBrightnessState;
  [out] OUT DXGK_BRIGHTNESS_SET_BACKLIGHT_OPTIMIZATION SetBacklightOptimization;
  [out] OUT DXGK_BRIGHTNESS_GET_BACKLIGHT_REDUCTION    GetBacklightReduction;
} DXGK_BRIGHTNESS_INTERFACE_2, *PDXGK_BRIGHTNESS_INTERFACE_2;