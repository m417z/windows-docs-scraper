typedef struct tagCHANNEL_ENTRY_POINTS {
  DWORD                cbSize;
  DWORD                protocolVersion;
  PVIRTUALCHANNELINIT  pVirtualChannelInit;
  PVIRTUALCHANNELOPEN  pVirtualChannelOpen;
  PVIRTUALCHANNELCLOSE pVirtualChannelClose;
  PVIRTUALCHANNELWRITE pVirtualChannelWrite;
} CHANNEL_ENTRY_POINTS, *PCHANNEL_ENTRY_POINTS;