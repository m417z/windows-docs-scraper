typedef struct {
  ULONG         RecordLength;
  USHORT        MajorVersion;
  USHORT        MinorVersion;
  FILE_ID_128   FileReferenceNumber;
  FILE_ID_128   ParentFileReferenceNumber;
  USN           Usn;
  LARGE_INTEGER TimeStamp;
  ULONG         Reason;
  ULONG         SourceInfo;
  ULONG         SecurityId;
  ULONG         FileAttributes;
  USHORT        FileNameLength;
  USHORT        FileNameOffset;
  WCHAR         FileName[1];
} USN_RECORD_V3, *PUSN_RECORD_V3;