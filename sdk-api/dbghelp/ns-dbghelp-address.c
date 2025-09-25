typedef struct _tagADDRESS {
  DWORD        Offset;
  WORD         Segment;
  ADDRESS_MODE Mode;
} ADDRESS, *LPADDRESS;