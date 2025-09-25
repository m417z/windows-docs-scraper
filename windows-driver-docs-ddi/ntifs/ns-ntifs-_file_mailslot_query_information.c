typedef struct _FILE_MAILSLOT_QUERY_INFORMATION {
  ULONG         MaximumMessageSize;
  ULONG         MailslotQuota;
  ULONG         NextMessageSize;
  ULONG         MessagesAvailable;
  LARGE_INTEGER ReadTimeout;
} FILE_MAILSLOT_QUERY_INFORMATION, *PFILE_MAILSLOT_QUERY_INFORMATION;