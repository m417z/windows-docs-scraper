typedef struct {
  USN_RECORD_COMMON_HEADER Header;
  FILE_ID_128              FileReferenceNumber;
  FILE_ID_128              ParentFileReferenceNumber;
  USN                      Usn;
  DWORD                    Reason;
  DWORD                    SourceInfo;
  DWORD                    RemainingExtents;
  WORD                     NumberOfExtents;
  WORD                     ExtentSize;
  USN_RECORD_EXTENT        Extents[1];
} USN_RECORD_V4, *PUSN_RECORD_V4;