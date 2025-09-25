typedef struct _ERROR_HISTORY_DIRECTORY {
  UCHAR                         T10VendorId[8];
  UCHAR                         ErrorHistoryVersion;
  UCHAR                         ClearSupport : 1;
  UCHAR                         ErrorHistorySource : 2;
  UCHAR                         ErrorHistoryRetrieved : 2;
  UCHAR                         Reserved0 : 3;
  UCHAR                         Reserved1[20];
  UCHAR                         DirectoryLength[2];
  ERROR_HISTORY_DIRECTORY_ENTRY ErrorHistoryDirectoryList[ANYSIZE_ARRAY];
} ERROR_HISTORY_DIRECTORY, *PERROR_HISTORY_DIRECTORY;