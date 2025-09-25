typedef struct {
  ULONGLONG StartFileReferenceNumber;
  USN       LowUsn;
  USN       HighUsn;
} MFT_ENUM_DATA_V0, *PMFT_ENUM_DATA_V0;