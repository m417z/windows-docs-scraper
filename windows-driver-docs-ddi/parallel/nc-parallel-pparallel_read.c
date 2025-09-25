PPARALLEL_READ PparallelRead;

NTSTATUS PparallelRead(
  [in]  PVOID Context,
  [out] PVOID Buffer,
  [in]  ULONG NumBytesToRead,
  [out] PULONG NumBytesRead,
  [in]  UCHAR Channel
)
{...}