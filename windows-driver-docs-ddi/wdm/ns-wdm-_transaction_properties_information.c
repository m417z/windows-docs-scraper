typedef struct _TRANSACTION_PROPERTIES_INFORMATION {
  ULONG         IsolationLevel;
  ULONG         IsolationFlags;
  LARGE_INTEGER Timeout;
  ULONG         Outcome;
  ULONG         DescriptionLength;
  WCHAR         Description[1];
} TRANSACTION_PROPERTIES_INFORMATION, *PTRANSACTION_PROPERTIES_INFORMATION;