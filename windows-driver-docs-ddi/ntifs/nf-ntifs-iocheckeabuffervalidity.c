NTSTATUS IoCheckEaBufferValidity(
  [in]  PFILE_FULL_EA_INFORMATION EaBuffer,
  [in]  ULONG                     EaLength,
  [out] PULONG                    ErrorOffset
);