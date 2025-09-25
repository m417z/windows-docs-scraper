typedef struct {
  DWORDLONG StartFileReferenceNumber;
  USN       LowUsn;
  USN       HighUsn;
  WORD      MinMajorVersion;
  WORD      MaxMajorVersion;
} MFT_ENUM_DATA_V1, *PMFT_ENUM_DATA_V1;