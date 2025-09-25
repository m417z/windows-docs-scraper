typedef struct _MHSP_CHANNEL {
  UINT64 ChannelBaseAddress;
  UINT64 RequestDoorbellAddress;
  UINT64 ReplyDoorbellAddress;
  UINT32 ChannelSize;
  UINT32 IrqResource;
  UINT32 ChannelParameters[2];
} MHSP_CHANNEL, *PMHSP_CHANNEL;