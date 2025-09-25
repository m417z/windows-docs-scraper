typedef struct _ACX_JACK_SINK_INFORMATION {
  ACX_JACK_SINK_INFO_CONNECTION_TYPE ConnType;
  USHORT                             ManufacturerId;
  USHORT                             ProductId;
  USHORT                             AudioLatency;
  BOOLEAN                            HDCPCapable;
  BOOLEAN                            AICapable;
  UCHAR                              SinkDescriptionLength;
  WCHAR                              SinkDescription[ACX_MAX_JACK_SINK_DESCRIPTION_NAME_LENGTH];
  LUID                               PortId;
} ACX_JACK_SINK_INFORMATION, *PACX_JACK_SINK_INFORMATION;