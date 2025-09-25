typedef struct _XLATEOBJ {
  ULONG  iUniq;
  FLONG  flXlate;
  USHORT iSrcType;
  USHORT iDstType;
  ULONG  cEntries;
  ULONG  *pulXlate;
} XLATEOBJ;