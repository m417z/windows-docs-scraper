NTSTATUS FsRtlKernelFsControlFile(
  [in]  PFILE_OBJECT FileObject,
  [in]  ULONG        FsControlCode,
  [in]  PVOID        InputBuffer,
  [in]  ULONG        InputBufferLength,
  [out] PVOID        OutputBuffer,
  [out] ULONG        OutputBufferLength,
  [out] PULONG       RetOutputBufferSize
);