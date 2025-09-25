VIRTUALCHANNELINIT Virtualchannelinit;

UINT VCAPITYPE Virtualchannelinit(
  [in]      LPVOID *ppInitHandle,
  [in, out] PCHANNEL_DEF pChannel,
  [in]      INT channelCount,
  [in]      ULONG versionRequested,
  [in]      PCHANNEL_INIT_EVENT_FN pChannelInitEventProc
)
{...}