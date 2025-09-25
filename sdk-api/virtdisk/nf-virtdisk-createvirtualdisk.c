DWORD CreateVirtualDisk(
  [in]           PVIRTUAL_STORAGE_TYPE           VirtualStorageType,
  [in]           PCWSTR                          Path,
  [in]           VIRTUAL_DISK_ACCESS_MASK        VirtualDiskAccessMask,
  [in, optional] PSECURITY_DESCRIPTOR            SecurityDescriptor,
  [in]           CREATE_VIRTUAL_DISK_FLAG        Flags,
  [in]           ULONG                           ProviderSpecificFlags,
  [in]           PCREATE_VIRTUAL_DISK_PARAMETERS Parameters,
  [in, optional] LPOVERLAPPED                    Overlapped,
  [out]          PHANDLE                         Handle
);