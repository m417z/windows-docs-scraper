struct _BRB_SCO_GET_CHANNEL_INFO {
  BRB_HEADER                Hdr;
  BTH_ADDR                  BtAddress;
  SCO_CHANNEL_HANDLE        ChannelHandle;
  ULONG                     InfoFlags;
  ULONG                     TransmitBandwidth;
  ULONG                     ReceiveBandwidth;
  USHORT                    MaxLatency;
  USHORT                    PacketType;
  USHORT                    ContentFormat;
  USHORT                    Reserved;
  SCO_RETRANSMISSION_EFFORT RetransmissionEffort;
  ULONG                     ChannelFlags;
  CONNECTION_HANDLE         HciConnectionHandle;
  SCO_LINK_TYPE             LinkType;
  BASEBAND_CHANNEL_INFO     BasebandInfo;
};