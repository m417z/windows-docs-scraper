DOT11EXTIHV_RECEIVE_INDICATION Dot11extihvReceiveIndication;

DWORD Dot11extihvReceiveIndication(
  [in, optional] HANDLE hIhvExtAdapter,
  [in]           DOT11EXT_IHV_INDICATION_TYPE indicationType,
  [in]           ULONG uBufferLength,
  [in, optional] LPVOID pvBuffer
)
{...}