DWORD AttachVirtualDisk(
  [in]           HANDLE                          VirtualDiskHandle,
  [in, optional] PSECURITY_DESCRIPTOR            SecurityDescriptor,
  [in]           ATTACH_VIRTUAL_DISK_FLAG        Flags,
  [in]           ULONG                           ProviderSpecificFlags,
  [in, optional] PATTACH_VIRTUAL_DISK_PARAMETERS Parameters,
  [in, optional] LPOVERLAPPED                    Overlapped
);