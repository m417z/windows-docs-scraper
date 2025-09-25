typedef struct _FILE_MEMORY_PARTITION_INFORMATION {
  ULONG_PTR OwnerPartitionHandle;
  union {
    struct {
      UCHAR NoCrossPartitionAccess;
      UCHAR Spare[3];
    } DUMMYSTRUCTNAME;
    ULONG AllFlags;
  } Flags;
} FILE_MEMORY_PARTITION_INFORMATION, *PFILE_MEMORY_PARTITION_INFORMATION;