typedef struct {
  ULONG         RecordLength;
  USHORT        MajorVersion;
  USHORT        MinorVersion;
  ULONGLONG     FileReferenceNumber;
  ULONGLONG     ParentFileReferenceNumber;
  USN           Usn;
  LARGE_INTEGER TimeStamp;
  ULONG         Reason;
  ULONG         SourceInfo;
  ULONG         SecurityId;
  ULONG         FileAttributes;
  USHORT        FileNameLength;
  USHORT        FileNameOffset;
  WCHAR         FileName[1];
} USN_RECORD_V2, *PUSN_RECORD_V2;