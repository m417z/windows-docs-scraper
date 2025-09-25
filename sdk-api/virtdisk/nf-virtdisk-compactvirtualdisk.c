DWORD CompactVirtualDisk(
  [in]           HANDLE                           VirtualDiskHandle,
  [in]           COMPACT_VIRTUAL_DISK_FLAG        Flags,
  [in, optional] PCOMPACT_VIRTUAL_DISK_PARAMETERS Parameters,
  [in, optional] LPOVERLAPPED                     Overlapped
);