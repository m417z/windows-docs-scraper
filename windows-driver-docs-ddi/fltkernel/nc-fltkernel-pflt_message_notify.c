PFLT_MESSAGE_NOTIFY PfltMessageNotify;

NTSTATUS PfltMessageNotify(
  PVOID PortCookie,
  PVOID InputBuffer,
  ULONG InputBufferLength,
  PVOID OutputBuffer,
  ULONG OutputBufferLength,
  PULONG ReturnOutputBufferLength
)
{...}