struct IDDCX_DISPLAYCONFIG_MODE {
  POINT                                 Position;
  DISPLAYCONFIG_2DREGION                Resolution;
  DISPLAYCONFIG_ROTATION                Rotation;
  DISPLAYCONFIG_RATIONAL                RefreshRate;
  UINT                                  VSyncFreqDivider;
  IDDCX_DISPLAYCONFIG_MONITOR_COLORMODE MonitorColorMode;
};