LPFN_RIORECEIVEEX LpfnRioreceiveex;

int LpfnRioreceiveex(
                                                                                                                     RIO_RQ SocketQueue,
                                                                                                                     PRIO_BUF pData,
                                                                                                                     ULONG DataBufferCount,
                                                                                                                     PRIO_BUF pLocalAddress,
                                                                                                                     PRIO_BUF pRemoteAddress,
                                                                                                                     PRIO_BUF pControlContext,
                                                                                                                     PRIO_BUF pFlags,
                                                                                                                     DWORD Flags,
                                                                                                                     PVOID RequestContext
)
{...}