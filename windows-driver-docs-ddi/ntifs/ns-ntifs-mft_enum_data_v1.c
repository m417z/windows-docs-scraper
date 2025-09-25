typedef struct {
  ULONGLONG StartFileReferenceNumber;
  USN       LowUsn;
  USN       HighUsn;
  USHORT    MinMajorVersion;
  USHORT    MaxMajorVersion;
} MFT_ENUM_DATA_V1, *PMFT_ENUM_DATA_V1;