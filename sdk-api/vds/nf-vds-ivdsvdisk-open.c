HRESULT Open(
  [in]  VIRTUAL_DISK_ACCESS_MASK AccessMask,
  [in]  OPEN_VIRTUAL_DISK_FLAG   Flags,
  [in]  ULONG                    ReadWriteDepth,
  [out] IVdsOpenVDisk            **ppOpenVDisk
);