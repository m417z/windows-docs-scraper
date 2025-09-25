HRESULT CreateVirtualChannel(
  [in]  BSTR                    bstrChannelName,
  [in]  CHANNEL_PRIORITY        Priority,
  [in]  unsigned long           ChannelFlags,
  [out] IRDPSRAPIVirtualChannel **ppChannel
);