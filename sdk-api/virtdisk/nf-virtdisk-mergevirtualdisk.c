DWORD MergeVirtualDisk(
  [in]           HANDLE                         VirtualDiskHandle,
  [in]           MERGE_VIRTUAL_DISK_FLAG        Flags,
  [in]           PMERGE_VIRTUAL_DISK_PARAMETERS Parameters,
  [in, optional] LPOVERLAPPED                   Overlapped
);