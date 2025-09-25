LPFN_RIORECEIVE LpfnRioreceive;

BOOL LpfnRioreceive(
  RIO_RQ SocketQueue,
  PRIO_BUF pData,
  ULONG DataBufferCount,
  DWORD Flags,
  PVOID RequestContext
)
{...}