NTSTATUS IoCheckQuotaBufferValidity(
  [in]  PFILE_QUOTA_INFORMATION QuotaBuffer,
  [in]  ULONG                   QuotaLength,
  [out] PULONG                  ErrorOffset
);