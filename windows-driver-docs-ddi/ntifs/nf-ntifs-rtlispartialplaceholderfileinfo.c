NTSYSAPI NTSTATUS RtlIsPartialPlaceholderFileInfo(
  [in]  const VOID             *InfoBuffer,
  [in]  FILE_INFORMATION_CLASS InfoClass,
  [out] PBOOLEAN               IsPartialPlaceholder
);