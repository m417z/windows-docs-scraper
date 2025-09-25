typedef struct _STORAGE_DEPENDENCY_INFO_TYPE_2 {
  DEPENDENT_DISK_FLAG  DependencyTypeFlags;
  ULONG                ProviderSpecificFlags;
  VIRTUAL_STORAGE_TYPE VirtualStorageType;
  ULONG                AncestorLevel;
  PWSTR                DependencyDeviceName;
  PWSTR                HostVolumeName;
  PWSTR                DependentVolumeName;
  PWSTR                DependentVolumeRelativePath;
} STORAGE_DEPENDENCY_INFO_TYPE_2, *PSTORAGE_DEPENDENCY_INFO_TYPE_2;