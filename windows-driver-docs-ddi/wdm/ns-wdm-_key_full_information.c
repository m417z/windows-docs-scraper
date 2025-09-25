typedef struct _KEY_FULL_INFORMATION {
  LARGE_INTEGER LastWriteTime;
  ULONG         TitleIndex;
  ULONG         ClassOffset;
  ULONG         ClassLength;
  ULONG         SubKeys;
  ULONG         MaxNameLen;
  ULONG         MaxClassLen;
  ULONG         Values;
  ULONG         MaxValueNameLen;
  ULONG         MaxValueDataLen;
  WCHAR         Class[1];
} KEY_FULL_INFORMATION, *PKEY_FULL_INFORMATION;