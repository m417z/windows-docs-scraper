typedef struct {
  UCHAR WriteUsingTokenDataLength[2];
  UCHAR Immediate : 1;
  UCHAR Reserved1 : 7;
  UCHAR Reserved2[5];
  UCHAR BlockOffsetIntoToken[8];
  UCHAR Token[BLOCK_DEVICE_TOKEN_SIZE];
  UCHAR Reserved3[6];
  UCHAR BlockDeviceRangeDescriptorListLength[2];
  UCHAR BlockDeviceRangeDescriptor[ANYSIZE_ARRAY];
} WRITE_USING_TOKEN_HEADER, *PWRITE_USING_TOKEN_HEADER;