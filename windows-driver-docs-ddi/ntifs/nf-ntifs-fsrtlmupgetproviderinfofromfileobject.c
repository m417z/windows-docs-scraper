NTSTATUS FsRtlMupGetProviderInfoFromFileObject(
  [in]      PFILE_OBJECT pFileObject,
  [in]      ULONG        Level,
  [out]     PVOID        pBuffer,
  [in, out] PULONG       pBufferSize
);