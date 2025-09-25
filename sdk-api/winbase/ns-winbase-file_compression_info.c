typedef struct _FILE_COMPRESSION_INFO {
  LARGE_INTEGER CompressedFileSize;
  WORD          CompressionFormat;
  UCHAR         CompressionUnitShift;
  UCHAR         ChunkShift;
  UCHAR         ClusterShift;
  UCHAR         Reserved[3];
} FILE_COMPRESSION_INFO, *PFILE_COMPRESSION_INFO;