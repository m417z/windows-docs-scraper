struct IDDCX_DISPLAYCONFIGPATH2 {
  UINT                                    Size;
  IDDCX_DISPLAYCONFIGPATH2_FLAGS          Flags;
  IDDCX_MONITOR                           MonitorObject;
  IDDCX_DISPLAYCONFIG_MODE                Mode;
  UINT                                    MonitorScaleFactor;
  DISPLAYCONFIG_2DREGION                  MonitorPhysicalSize;
  IDDCX_DISPLAYCONFIG_MONITOR_COLORIMETRY MonitorColorimetry;
  UINT                                    MonitorSdrWhiteLevel;
};