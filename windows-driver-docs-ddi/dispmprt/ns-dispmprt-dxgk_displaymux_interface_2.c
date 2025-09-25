typedef struct _DXGK_DISPLAYMUX_INTERFACE_2 {
  USHORT                                              Size;
  USHORT                                              Version;
  PVOID                                               Context;
  PINTERFACE_REFERENCE                                InterfaceReference;
  PINTERFACE_DEREFERENCE                              InterfaceDereference;
  DXGKDDI_DISPLAYMUX_GET_DRIVER_SUPPORT_LEVEL         DxgkDdiDisplayMuxGetDriverSupportLevel;
  DXGKDDI_DISPLAYMUX_GET_RUNTIME_STATUS               DxgkDdiDisplayMuxGetRuntimeStatus;
  DXGKDDI_DISPLAYMUX_PRE_SWITCH_AWAY                  DxgkDdiDisplayMuxPreSwitchAway;
  DXGKDDI_DISPLAYMUX_PRE_SWITCH_AWAY_GET_PRIVATE_DATA DxgkDdiDisplayMuxPreSwitchAwayGetPrivateData;
  DXGKDDI_DISPLAYMUX_PRE_SWITCH_TO                    DxgkDdiDisplayMuxPreSwitchTo;
  DXGKDDI_DISPLAYMUX_SWITCH_CANCELED                  DxgkDdiDisplayMuxSwitchCanceled;
  DXGKDDI_DISPLAYMUX_POST_SWITCH_AWAY                 DxgkDdiDisplayMuxPostSwitchAway;
  DXGKDDI_DISPLAYMUX_POST_SWITCH_TO_PHASE1            DxgkDdiDisplayMuxPostSwitchToPhase1;
  DXGKDDI_DISPLAYMUX_POST_SWITCH_TO_PHASE2            DxgkDdiDisplayMuxPostSwitchToPhase2;
  DXGKDDI_DISPLAYMUX_UPDATE_STATE                     DxgkDdiDisplayMuxUpdateState;
  DXGKDDI_DISPLAYMUX_REPORT_PRESENCE                  DxgkDdiDisplayMuxReportPresence;
  DXGKDDI_DISPLAYMUX_SET_INTERNAL_PANEL_INFO          DxgkDdiDisplayMuxSetInternalPanelInfo;
} DXGK_DISPLAYMUX_INTERFACE_2, *PDXGK_DISPLAYMUX_INTERFACE_2;