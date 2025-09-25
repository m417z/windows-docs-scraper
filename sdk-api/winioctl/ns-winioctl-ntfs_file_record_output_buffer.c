typedef struct {
  LARGE_INTEGER FileReferenceNumber;
  DWORD         FileRecordLength;
  BYTE          FileRecordBuffer[1];
} NTFS_FILE_RECORD_OUTPUT_BUFFER, *PNTFS_FILE_RECORD_OUTPUT_BUFFER;