typedef struct _MSiSCSI_SessionStatistics {
  WCHAR     iSCSIName[223 + 1];
  ULONGLONG USID;
  ULONGLONG UniqueAdapterId;
  ULONGLONG BytesSent;
  ULONGLONG BytesReceived;
  ULONGLONG PDUCommandsSent;
  ULONGLONG PDUResponsesReceived;
  ULONGLONG DigestErrors;
  ULONGLONG ConnectionTimeoutErrors;
  ULONGLONG FormatErrors;
} MSiSCSI_SessionStatistics, *PMSiSCSI_SessionStatistics;