typedef struct _CURRENT_DEVICE_INTERNAL_STATUS_LOG {
  UCHAR  LogAddress;
  UCHAR  Reserved0[3];
  ULONG  OrganizationID;
  USHORT Area1LastLogPage;
  USHORT Area2LastLogPage;
  USHORT Area3LastLogPage;
  UCHAR  Reserved2[368];
  UCHAR  SavedDataAvailable;
  UCHAR  SavedDataGenerationNumber;
  UCHAR  ReasonIdentifier[128];
} CURRENT_DEVICE_INTERNAL_STATUS_LOG, *PCURRENT_DEVICE_INTERNAL_STATUS_LOG;