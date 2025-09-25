typedef struct _tagADDRESS64 {
  DWORD64      Offset;
  WORD         Segment;
  ADDRESS_MODE Mode;
} ADDRESS64, *LPADDRESS64;