DWORD ExpandVirtualDisk(
  [in]           HANDLE                          VirtualDiskHandle,
  [in]           EXPAND_VIRTUAL_DISK_FLAG        Flags,
  [in]           PEXPAND_VIRTUAL_DISK_PARAMETERS Parameters,
  [in, optional] LPOVERLAPPED                    Overlapped
);