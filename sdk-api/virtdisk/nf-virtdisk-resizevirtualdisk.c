DWORD ResizeVirtualDisk(
  [in]           HANDLE                          VirtualDiskHandle,
  [in]           RESIZE_VIRTUAL_DISK_FLAG        Flags,
  [in]           PRESIZE_VIRTUAL_DISK_PARAMETERS Parameters,
  [in, optional] LPOVERLAPPED                    Overlapped
);