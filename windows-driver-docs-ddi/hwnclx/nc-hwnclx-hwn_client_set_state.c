HWN_CLIENT_SET_STATE HwnClientSetState;

NTSTATUS HwnClientSetState(
  [in]  PVOID Context,
  [in]  PVOID Buffer,
  [in]  ULONG BufferLength,
  [out] PULONG BytesWritten
)
{...}