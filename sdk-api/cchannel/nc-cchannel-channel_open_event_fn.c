CHANNEL_OPEN_EVENT_FN ChannelOpenEventFn;

VOID VCAPITYPE ChannelOpenEventFn(
  [in] DWORD openHandle,
  [in] UINT event,
  [in] LPVOID pData,
  [in] UINT32 dataLength,
  [in] UINT32 totalLength,
  [in] UINT32 dataFlags
)
{...}