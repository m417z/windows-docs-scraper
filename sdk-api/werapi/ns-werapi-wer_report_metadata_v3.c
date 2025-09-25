typedef struct _WER_REPORT_METADATA_V3 {
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
  WCHAR                FriendlyEventName[WER_MAX_FRIENDLY_EVENT_NAME_LENGTH];
  WCHAR                ApplicationName[WER_MAX_APPLICATION_NAME_LENGTH];
  WCHAR                ApplicationPath[MAX_PATH];
  WCHAR                Description[WER_MAX_DESCRIPTION_LENGTH];
  WCHAR                BucketIdString[WER_MAX_BUCKET_ID_STRING_LENGTH];
  ULONGLONG            LegacyBucketId;
} WER_REPORT_METADATA_V3, *PWER_REPORT_METADATA_V3;