CrediUnmarshalandDecodeStringFn Crediunmarshalanddecodestringfn;

NTSTATUS Crediunmarshalanddecodestringfn(
  [in]  LPWSTR MarshaledString,
  [out] LPBYTE *Blob,
  [out] ULONG *BlobSize,
  [out] BOOLEAN *IsFailureFatal
)
{...}