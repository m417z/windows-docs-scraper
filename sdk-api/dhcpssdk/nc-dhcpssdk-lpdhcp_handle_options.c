LPDHCP_HANDLE_OPTIONS LpdhcpHandleOptions;

DWORD LpdhcpHandleOptions(
  [in]      LPBYTE Packet,
  [in]      DWORD PacketSize,
  [in]      LPVOID Reserved,
  [in]      LPVOID PktContext,
  [in, out] LPDHCP_SERVER_OPTIONS ServerOptions
)
{...}