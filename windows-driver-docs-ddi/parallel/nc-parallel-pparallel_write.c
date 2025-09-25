PPARALLEL_WRITE PparallelWrite;

NTSTATUS PparallelWrite(
  [in]  PVOID Context,
  [in]  PVOID Buffer,
  [in]  ULONG NumBytesToWrite,
  [out] PULONG NumBytesWritten,
  [in]  UCHAR Channel
)
{...}