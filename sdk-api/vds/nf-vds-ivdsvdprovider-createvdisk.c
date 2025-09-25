HRESULT CreateVDisk(
  [in]  PVIRTUAL_STORAGE_TYPE        VirtualDeviceType,
  [in]  LPWSTR                       pPath,
  [in]  LPWSTR                       pStringSecurityDescriptor,
  [in]  CREATE_VIRTUAL_DISK_FLAG     Flags,
  [in]  ULONG                        ProviderSpecificFlags,
  [in]  ULONG                        Reserved,
  [in]  PVDS_CREATE_VDISK_PARAMETERS pCreateDiskParameters,
  [out] IVdsAsync                    **ppAsync
);