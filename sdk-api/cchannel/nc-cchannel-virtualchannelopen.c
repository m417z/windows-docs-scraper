VIRTUALCHANNELOPEN Virtualchannelopen;

UINT VCAPITYPE Virtualchannelopen(
  [in]  LPVOID pInitHandle,
  [out] LPDWORD pOpenHandle,
  [in]  PCHAR pChannelName,
  [in]  PCHANNEL_OPEN_EVENT_FN pChannelOpenEventProc
)
{...}