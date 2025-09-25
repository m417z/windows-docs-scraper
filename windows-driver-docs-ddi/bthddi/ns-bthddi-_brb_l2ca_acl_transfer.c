struct _BRB_L2CA_ACL_TRANSFER {
  BRB_HEADER           Hdr;
  BTH_ADDR             BtAddress;
  L2CAP_CHANNEL_HANDLE ChannelHandle;
  ULONG                TransferFlags;
  ULONG                BufferSize;
  PVOID                Buffer;
  PMDL                 BufferMDL;
  LONGLONG             Timeout;
  ULONG                RemainingBufferSize;
};