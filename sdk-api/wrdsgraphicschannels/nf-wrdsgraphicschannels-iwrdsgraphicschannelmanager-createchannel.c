HRESULT CreateChannel(
  [in]          const char              *pszChannelName,
  [in]          WRdsGraphicsChannelType channelType,
  [out, retval] IWRdsGraphicsChannel    **ppVirtualChannel
);