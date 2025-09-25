typedef struct _NTSCSI_UNICODE_STRING {
  USHORT Length;
  USHORT MaximumLength;
#if ...
  USHORT *Buffer;
#else
  PWCH   Buffer;
#endif
} NTSCSI_UNICODE_STRING;