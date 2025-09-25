typedef struct _DXGKARGCB_DISCONNECTDOORBELL {
  HANDLE                             hHwQueue;
  HANDLE                             hDoorbell;
  DXGKARGCB_DISCONNECTDOORBELL_FLAGS Flags;
  D3DDDI_DOORBELLSTATUS              DisconnectReason;
} DXGKARGCB_DISCONNECTDOORBELL;