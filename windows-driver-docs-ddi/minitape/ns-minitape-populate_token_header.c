typedef struct {
  UCHAR PopulateTokenDataLength[2];
  UCHAR Immediate : 1;
  UCHAR Reserved1 : 7;
  UCHAR Reserved2;
  UCHAR InactivityTimeout[4];
  UCHAR Reserved3[6];
  UCHAR BlockDeviceRangeDescriptorListLength[2];
  UCHAR BlockDeviceRangeDescriptor[ANYSIZE_ARRAY];
} POPULATE_TOKEN_HEADER, *PPOPULATE_TOKEN_HEADER;