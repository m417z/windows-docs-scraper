typedef struct {
  LARGE_INTEGER FileReferenceNumber;
  ULONG         FileRecordLength;
  UCHAR         FileRecordBuffer[1];
} NTFS_FILE_RECORD_OUTPUT_BUFFER, *PNTFS_FILE_RECORD_OUTPUT_BUFFER;