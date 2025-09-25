typedef struct _tagKSJACK_SINK_INFORMATION {
  KSJACK_SINK_CONNECTIONTYPE ConnType;
  WORD                       ManufacturerId;
  WORD                       ProductId;
  WORD                       AudioLatency;
  BOOL                       HDCPCapable;
  BOOL                       AICapable;
  UCHAR                      SinkDescriptionLength;
  WCHAR                      SinkDescription[MAX_SINK_DESCRIPTION_NAME_LENGTH];
  LUID                       PortId;
} KSJACK_SINK_INFORMATION, *PKSJACK_SINK_INFORMATION;