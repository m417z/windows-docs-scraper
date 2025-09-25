typedef struct _tagKSJACK_SINK_INFORMATION {
  KSJACK_SINK_CONNECTIONTYPE ConnType;
  WORD                       ManufacturerId;
  WORD                       ProductId;
  WORD                       AudioLatency;
  BOOL                       HDCPCapable;
  BOOL                       AICapable;
  UCHAR                      SinkDescriptionLength;
  WCHAR                      SinkDescription[32];
  LUID                       PortId;
} KSJACK_SINK_INFORMATION;