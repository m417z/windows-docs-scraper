typedef union _DXGK_DIAGNOSTIC_PSR_REFRESH_REASON {
  struct {
    UINT Present : 1;
    UINT CursorUpdate : 1;
    UINT VSyncEnabled : 1;
    UINT ColorTransformationChange : 1;
    UINT BrightnessChange : 1;
    UINT SinkRequest : 1;
    UINT Other : 1;
    UINT Reserved : 25;
  };
  UINT   Value;
} DXGK_DIAGNOSTIC_PSR_REFRESH_REASON;