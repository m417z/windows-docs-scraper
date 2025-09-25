LPFN_RIOCREATEREQUESTQUEUE LpfnRiocreaterequestqueue;

RIO_RQ LpfnRiocreaterequestqueue(
  SOCKET Socket,
  ULONG MaxOutstandingReceive,
  ULONG MaxReceiveDataBuffers,
  ULONG MaxOutstandingSend,
  ULONG MaxSendDataBuffers,
  RIO_CQ ReceiveCQ,
  RIO_CQ SendCQ,
  PVOID SocketContext
)
{...}