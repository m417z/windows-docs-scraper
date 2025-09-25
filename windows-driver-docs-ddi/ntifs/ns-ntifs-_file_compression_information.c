typedef struct _FILE_COMPRESSION_INFORMATION {
  LARGE_INTEGER CompressedFileSize;
  USHORT        CompressionFormat;
  UCHAR         CompressionUnitShift;
  UCHAR         ChunkShift;
  UCHAR         ClusterShift;
  UCHAR         Reserved[3];
} FILE_COMPRESSION_INFORMATION, *PFILE_COMPRESSION_INFORMATION;