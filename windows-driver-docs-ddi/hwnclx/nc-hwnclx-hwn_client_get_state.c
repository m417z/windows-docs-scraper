HWN_CLIENT_GET_STATE HwnClientGetState;

NTSTATUS HwnClientGetState(
  [in]  PVOID Context,
  [out] PVOID OutputBuffer,
  [in]  ULONG OutputBufferLength,
  [in]  PVOID InputBuffer,
  [in]  ULONG InputBufferLength,
  [out] PULONG BytesRead
)
{...}