typedef struct _WER_REPORT_METADATA_V1 {
  WER_REPORT_SIGNATURE Signature;
  GUID                 BucketId;
  GUID                 ReportId;
  FILETIME             CreationTime;
  ULONGLONG            SizeInBytes;
} WER_REPORT_METADATA_V1, *PWER_REPORT_METADATA_V1;