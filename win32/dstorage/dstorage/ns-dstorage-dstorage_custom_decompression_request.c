struct DSTORAGE_CUSTOM_DECOMPRESSION_REQUEST {
  UINT64                              Id;
  DSTORAGE_COMPRESSION_FORMAT         CompressionFormat;
  UINT8                               Reserved[3];
  DSTORAGE_CUSTOM_DECOMPRESSION_FLAGS Flags;
  UINT64                              SrcSize;
  void const                          *SrcBuffer;
  UINT64                              DstSize;
  void                                *DstBuffer;
};