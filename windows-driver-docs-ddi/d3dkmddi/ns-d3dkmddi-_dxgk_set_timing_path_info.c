typedef struct _DXGK_SET_TIMING_PATH_INFO {
  D3DDDI_VIDEO_PRESENT_TARGET_ID     VidPnTargetId;
  union {
    D3DDDI_COLOR_SPACE_TYPE             OutputColorSpace;
    D3DDDI_OUTPUT_WIRE_COLOR_SPACE_TYPE OutputWireColorSpace;
  };
  D3DKMDT_WIRE_FORMAT_AND_PREFERENCE SelectedWireFormat;
  union {
    struct {
      DXGK_PATH_UPDATE     VidPnPathUpdates : 2;
      UINT                 Active : 1;
      UINT                 IgnoreConnectivity : 1;
      UINT                 PreserveInherited : 1;
      UINT                 SyncLockGroup : 3;
      DXGK_SYNC_LOCK_STYLE SyncLockStyle : 4;
#if ...
      UINT                 Reserved : 20;
#else
      UINT                 Reserved : 27;
#endif
    } Input;
    UINT InputFlags;
  };
  union {
    struct {
      UINT RecheckMPO : 1;
      UINT Reserved : 31;
    } Output;
    UINT OutputFlags;
  };
  DXGK_CONNECTION_CHANGE             TargetState;
  union {
    struct {
      DXGK_GLITCH_CAUSE    GlitchCause;
      DXGK_GLITCH_EFFECT   GlitchEffect;
      DXGK_GLITCH_DURATION GlitchDuration;
      UINT8                Reserved;
    };
    UINT DiagnosticInfo;
  };
} DXGK_SET_TIMING_PATH_INFO;