typedef struct _D3DDDI_OVERLAYCOLORCONTROLS {
  [in] INT                              BrightnessSetting;
  [in] INT                              ContrastSetting;
  [in] INT                              HueSetting;
  [in] INT                              SaturationSetting;
  [in] INT                              SharpnessSetting;
  [in] INT                              GammaSetting;
  [in] INT                              ColorEnableSetting;
  [in] D3DDDI_OVERLAYCOLORCONTROLSFLAGS Flags;
} D3DDDI_OVERLAYCOLORCONTROLS;