DWORD GetVirtualDiskInformation(
  [in]                HANDLE                 VirtualDiskHandle,
  [in, out]           PULONG                 VirtualDiskInfoSize,
  [in, out]           PGET_VIRTUAL_DISK_INFO VirtualDiskInfo,
  [in, out, optional] PULONG                 SizeUsed
);