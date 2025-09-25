typedef struct _WPP_TRIAGE_INFO {
  ULONG WppAutoLogHeaderSize;
  ULONG WppDriverContextOffset;
  ULONG WppAutoLogHeaderSizeOffset;
  ULONG WppSizeOfAutoLogHeaderSizeField;
  ULONG WppDriverContextSize;
} WPP_TRIAGE_INFO, *PWPP_TRIAGE_INFO;