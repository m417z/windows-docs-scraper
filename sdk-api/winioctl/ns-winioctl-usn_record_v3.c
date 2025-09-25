typedef struct {
  DWORD         RecordLength;
  WORD          MajorVersion;
  WORD          MinorVersion;
  FILE_ID_128   FileReferenceNumber;
  FILE_ID_128   ParentFileReferenceNumber;
  USN           Usn;
  LARGE_INTEGER TimeStamp;
  DWORD         Reason;
  DWORD         SourceInfo;
  DWORD         SecurityId;
  DWORD         FileAttributes;
  WORD          FileNameLength;
  WORD          FileNameOffset;
  WCHAR         FileName[1];
} USN_RECORD_V3, *PUSN_RECORD_V3;