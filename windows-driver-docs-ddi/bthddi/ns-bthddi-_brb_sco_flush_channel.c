struct _BRB_SCO_FLUSH_CHANNEL {
  BRB_HEADER         Hdr;
  BTH_ADDR           BtAddress;
  SCO_CHANNEL_HANDLE ChannelHandle;
  ULONG              FlushFlags;
};