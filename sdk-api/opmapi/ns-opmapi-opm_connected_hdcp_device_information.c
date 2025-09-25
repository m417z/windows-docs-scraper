typedef struct _OPM_CONNECTED_HDCP_DEVICE_INFORMATION {
  OPM_RANDOM_NUMBER             rnRandomNumber;
  ULONG                         ulStatusFlags;
  ULONG                         ulHDCPFlags;
  OPM_HDCP_KEY_SELECTION_VECTOR ksvB;
  BYTE                          Reserved[11];
  BYTE                          Reserved2[16];
  BYTE                          Reserved3[16];
} OPM_CONNECTED_HDCP_DEVICE_INFORMATION;