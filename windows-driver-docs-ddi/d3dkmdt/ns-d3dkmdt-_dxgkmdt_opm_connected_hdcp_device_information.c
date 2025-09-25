typedef struct _DXGKMDT_OPM_CONNECTED_HDCP_DEVICE_INFORMATION {
  DXGKMDT_OPM_RANDOM_NUMBER             rnRandomNumber;
  ULONG                                 ulStatusFlags;
  ULONG                                 ulHDCPFlags;
  DXGKMDT_OPM_HDCP_KEY_SELECTION_VECTOR ksvB;
  BYTE                                  Reserved[11];
  BYTE                                  Reserved2[16];
  BYTE                                  Reserved3[16];
} DXGKMDT_OPM_CONNECTED_HDCP_DEVICE_INFORMATION;