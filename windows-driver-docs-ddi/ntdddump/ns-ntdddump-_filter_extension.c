typedef struct _FILTER_EXTENSION {
  FILTER_DUMP_TYPE    DumpType;
  PDEVICE_OBJECT      DeviceObject;
  DISK_GEOMETRY       Geometry;
  LARGE_INTEGER       DiskSize;
  DISK_PARTITION_INFO PartitionInfo;
  PVOID               DumpData;
  ULONG               Size;
  ULONG               Flags;
} FILTER_EXTENSION, *PFILTER_EXTENSION;