struct IDDCX_DISPLAYCONFIGPATH {
  UINT                   Size;
  IDDCX_MONITOR          MonitorObject;
  POINT                  Position;
  DISPLAYCONFIG_2DREGION Resolution;
  DISPLAYCONFIG_ROTATION Rotation;
  DISPLAYCONFIG_RATIONAL RefreshRate;
  UINT                   VSyncFreqDivider;
  UINT                   MonitorScaleFactor;
  UINT                   PhysicalWidthOverride;
  UINT                   PhysicalHeightOverride;
};