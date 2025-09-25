struct _BRB_SCO_TRANSFER {
  BRB_HEADER         Hdr;
  BTH_ADDR           BtAddress;
  SCO_CHANNEL_HANDLE ChannelHandle;
  ULONG              TransferFlags;
  ULONG              BufferSize;
  PVOID              Buffer;
  PMDL               BufferMDL;
  ULONGLONG          DataTag;
};