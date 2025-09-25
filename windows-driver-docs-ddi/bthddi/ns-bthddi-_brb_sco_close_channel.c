struct _BRB_SCO_CLOSE_CHANNEL {
  BRB_HEADER         Hdr;
  BTH_ADDR           BtAddress;
  SCO_CHANNEL_HANDLE ChannelHandle;
};