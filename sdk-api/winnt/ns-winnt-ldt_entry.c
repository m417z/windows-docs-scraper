typedef struct _LDT_ENTRY {
  WORD  LimitLow;
  WORD  BaseLow;
  union {
    struct {
      BYTE BaseMid;
      BYTE Flags1;
      BYTE Flags2;
      BYTE BaseHi;
    } Bytes;
    struct {
      DWORD BaseMid : 8;
      DWORD Type : 5;
      DWORD Dpl : 2;
      DWORD Pres : 1;
      DWORD LimitHi : 4;
      DWORD Sys : 1;
      DWORD Reserved_0 : 1;
      DWORD Default_Big : 1;
      DWORD Granularity : 1;
      DWORD BaseHi : 8;
    } Bits;
  } HighWord;
} LDT_ENTRY, *PLDT_ENTRY;