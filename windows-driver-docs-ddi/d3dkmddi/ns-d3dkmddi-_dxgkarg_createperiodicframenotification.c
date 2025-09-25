typedef struct _DXGKARG_CREATEPERIODICFRAMENOTIFICATION {
  HANDLE                         hAdapter;
  D3DDDI_VIDEO_PRESENT_SOURCE_ID VidPnTargetId;
  UINT64                         Time;
  UINT                           NotificationID;
  HANDLE                         hNotification;
} DXGKARG_CREATEPERIODICFRAMENOTIFICATION;