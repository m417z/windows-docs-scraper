DWORD OpenVirtualDisk(
  [in]           PVIRTUAL_STORAGE_TYPE         VirtualStorageType,
  [in]           PCWSTR                        Path,
  [in]           VIRTUAL_DISK_ACCESS_MASK      VirtualDiskAccessMask,
  [in]           OPEN_VIRTUAL_DISK_FLAG        Flags,
  [in, optional] POPEN_VIRTUAL_DISK_PARAMETERS Parameters,
  [out]          PHANDLE                       Handle
);