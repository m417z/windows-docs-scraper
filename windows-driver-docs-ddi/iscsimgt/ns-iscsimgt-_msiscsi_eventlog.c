typedef struct _MSiSCSI_Eventlog {
  ULONG Type;
  ULONG LogToEventlog;
  ULONG Size;
  UCHAR AdditionalData[1];
} MSiSCSI_Eventlog, *PMSiSCSI_Eventlog;