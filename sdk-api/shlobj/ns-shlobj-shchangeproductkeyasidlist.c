typedef struct _SHChangeProductKeyAsIDList {
  USHORT cb;
  WCHAR  wszProductKey[39];
  USHORT cbZero;
} SHChangeProductKeyAsIDList, *LPSHChangeProductKeyAsIDList;