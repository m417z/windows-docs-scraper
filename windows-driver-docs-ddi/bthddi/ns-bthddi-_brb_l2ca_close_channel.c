struct _BRB_L2CA_CLOSE_CHANNEL {
  BRB_HEADER           Hdr;
  BTH_ADDR             BtAddress;
  L2CAP_CHANNEL_HANDLE ChannelHandle;
};