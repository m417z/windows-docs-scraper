typedef struct _DXGK_CONNECTION_CHANGE {
  ULONGLONG                      ConnectionChangeId;
  D3DDDI_VIDEO_PRESENT_TARGET_ID TargetId : 24;
  DXGK_CONNECTION_STATUS         ConnectionStatus : 4;
  UINT                           Reserved : 4;
  union {
    struct {
      D3DKMDT_VIDEO_OUTPUT_TECHNOLOGY       LinkTargetType;
      DXGK_CONNECTION_MONITOR_CONNECT_FLAGS MonitorConnectFlags;
    } MonitorConnect;
    struct {
      D3DKMDT_VIDEO_OUTPUT_TECHNOLOGY BaseTargetType;
      D3DDDI_VIDEO_PRESENT_TARGET_ID  NewTargetId;
    } TargetConnect;
    struct {
      D3DKMDT_VIDEO_OUTPUT_TECHNOLOGY BaseTargetType;
      D3DDDI_VIDEO_PRESENT_TARGET_ID  NewTargetId;
    } TargetJoin;
  };
} DXGK_CONNECTION_CHANGE, *PDXGK_CONNECTION_CHANGE;