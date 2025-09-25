DWORD GetVirtualDiskMetadata(
  [in]      HANDLE     VirtualDiskHandle,
  [in]      const GUID *Item,
  [in, out] PULONG     MetaDataSize,
  [out]     PVOID      MetaData
);