LPFN_RIOSEND LpfnRiosend;

BOOL LpfnRiosend(
  RIO_RQ SocketQueue,
  PRIO_BUF pData,
  ULONG DataBufferCount,
  DWORD Flags,
  PVOID RequestContext
)
{...}