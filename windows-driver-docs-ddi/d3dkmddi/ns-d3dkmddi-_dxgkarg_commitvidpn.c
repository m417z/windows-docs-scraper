typedef struct _DXGKARG_COMMITVIDPN {
       IN D3DKMDT_HVIDPN                      hFunctionalVidPn;
       IN D3DDDI_VIDEO_PRESENT_SOURCE_ID      AffectedVidPnSourceId;
       IN D3DKMDT_MONITOR_CONNECTIVITY_CHECKS MonitorConnectivityChecks;
       IN HANDLE                              hPrimaryAllocation;
  [in] IN DXGKARG_COMMITVIDPN_FLAGS           Flags;
} DXGKARG_COMMITVIDPN;