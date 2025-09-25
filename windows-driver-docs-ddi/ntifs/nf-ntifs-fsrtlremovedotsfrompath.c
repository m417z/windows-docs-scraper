NTSTATUS FsRtlRemoveDotsFromPath(
  [in, out] PWSTR  OriginalString,
  [in]      USHORT PathLength,
  [out]     USHORT *NewLength
);