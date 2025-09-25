DOT11EXTIHV_RECEIVE_PACKET Dot11extihvReceivePacket;

DWORD Dot11extihvReceivePacket(
  [in, optional] HANDLE hIhvExtAdapter,
  [in]           DWORD dwInBufferSize,
  [in]           LPVOID pvInBuffer
)
{...}