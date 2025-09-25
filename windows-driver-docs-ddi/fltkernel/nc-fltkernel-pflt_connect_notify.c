PFLT_CONNECT_NOTIFY PfltConnectNotify;

NTSTATUS PfltConnectNotify(
  PFLT_PORT ClientPort,
  PVOID ServerPortCookie,
  PVOID ConnectionContext,
  ULONG SizeOfContext,
  PVOID *ConnectionPortCookie
)
{...}