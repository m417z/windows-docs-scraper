typedef struct _WER_REPORT_METADATA_V2 {
  WER_REPORT_SIGNATURE Signature;
  GUID                 BucketId;
  GUID                 ReportId;
  FILETIME             CreationTime;
  ULONGLONG            SizeInBytes;
  WCHAR                CabId[MAX_PATH];
  DWORD                ReportStatus;
  GUID                 ReportIntegratorId;
  DWORD                NumberOfFiles;
  DWORD                SizeOfFileNames;
  WCHAR                *FileNames;
} WER_REPORT_METADATA_V2, *PWER_REPORT_METADATA_V2;