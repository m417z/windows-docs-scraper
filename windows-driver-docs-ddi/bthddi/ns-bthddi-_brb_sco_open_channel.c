struct _BRB_SCO_OPEN_CHANNEL {
  BRB_HEADER                 Hdr;
  BTH_ADDR                   BtAddress;
  ULONG                      TransmitBandwidth;
  ULONG                      ReceiveBandwidth;
  USHORT                     MaxLatency;
  USHORT                     PacketType;
  USHORT                     ContentFormat;
  USHORT                     Reserved;
  SCO_RETRANSMISSION_EFFORT  RetransmissionEffort;
  ULONG                      ChannelFlags;
  ULONG                      CallbackFlags;
  PFNSCO_INDICATION_CALLBACK Callback;
  PVOID                      CallbackContext;
  PVOID                      ReferenceObject;
  SCO_CHANNEL_HANDLE         ChannelHandle;
  UCHAR                      Response;
};