DWORD GetVirtualDiskPhysicalPath(
  [in]            HANDLE VirtualDiskHandle,
  [in, out]       PULONG DiskPathSizeInBytes,
  [out, optional] PWSTR  DiskPath
);