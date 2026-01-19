typedef struct {
  USHORT                 NumEntries;
  USHORT                 FirstEntry;
  union {
    VIDEO_CLUTDATA RgbArray;
    ULONG          RgbLong;
  };
  __unnamed_union_01a0_2 LookupTable[1];
} VIDEO_CLUT, *PVIDEO_CLUT;