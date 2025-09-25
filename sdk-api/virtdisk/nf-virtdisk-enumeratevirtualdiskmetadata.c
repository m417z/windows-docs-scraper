DWORD EnumerateVirtualDiskMetadata(
  [in]      HANDLE VirtualDiskHandle,
  [in, out] PULONG NumberOfItems,
  [out]     GUID   *Items
);