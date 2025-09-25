typedef struct _FILE_FS_SECTOR_SIZE_INFORMATION {
  ULONG LogicalBytesPerSector;
  ULONG PhysicalBytesPerSectorForAtomicity;
  ULONG PhysicalBytesPerSectorForPerformance;
  ULONG FileSystemEffectivePhysicalBytesPerSectorForAtomicity;
  ULONG Flags;
  ULONG ByteOffsetForSectorAlignment;
  ULONG ByteOffsetForPartitionAlignment;
} FILE_FS_SECTOR_SIZE_INFORMATION, *PFILE_FS_SECTOR_SIZE_INFORMATION;