typedef struct _STORAGE_LB_PROVISIONING_MAP_RESOURCES {
  ULONG     Size;
  ULONG     Version;
  UCHAR     AvailableMappingResourcesValid : 1;
  UCHAR     UsedMappingResourcesValid : 1;
  UCHAR     Reserved0 : 6;
  UCHAR     Reserved1[3];
  UCHAR     AvailableMappingResourcesScope : 2;
  UCHAR     UsedMappingResourcesScope : 2;
  UCHAR     Reserved2 : 4;
  UCHAR     Reserved3[3];
  ULONGLONG AvailableMappingResources;
  ULONGLONG UsedMappingResources;
} STORAGE_LB_PROVISIONING_MAP_RESOURCES, *PSTORAGE_LB_PROVISIONING_MAP_RESOURCES;