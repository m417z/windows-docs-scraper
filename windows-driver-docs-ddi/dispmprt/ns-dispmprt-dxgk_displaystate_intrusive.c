typedef struct _DXGKARG_DISPLAYSTATE_INTRUSIVE {
  [in] D3DDDI_VIDEO_PRESENT_TARGET_ID         VidPnTargetId;
       DXGK_DIAG_MONITOR_STATE                MonitorState;
       DXGK_DIAG_DISPLAY_SCANOUT_STATE        DisplayScanoutState;
       DXGK_DIAG_DISPLAY_SAMPLED_GAMMA        DisplaySampledGamma;
       DXGK_DIAG_SCANOUT_BUFFER_CONTENT       DisplayBufferContent;
       DXGK_DIAG_DISPLAY_HARDWARE_ERROR_STATE DisplayErrorState;
       DXGK_DIAG_DISPLAY_HARDWARE_BANDWIDTH   DisplayBandwidth;
       UINT                                   ReturnSubStatus;
} DXGK_DISPLAYSTATE_INTRUSIVE;