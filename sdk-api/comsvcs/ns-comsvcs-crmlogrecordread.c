typedef struct tagCrmLogRecordRead {
  DWORD dwCrmFlags;
  DWORD dwSequenceNumber;
  BLOB  blobUserData;
} CrmLogRecordRead;