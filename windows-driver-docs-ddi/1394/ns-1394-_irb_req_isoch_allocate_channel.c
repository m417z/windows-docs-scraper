typedef struct _IRB_REQ_ISOCH_ALLOCATE_CHANNEL {
  ULONG         nRequestedChannel;
  ULONG         Channel;
  LARGE_INTEGER ChannelsAvailable;
} IRB_REQ_ISOCH_ALLOCATE_CHANNEL;