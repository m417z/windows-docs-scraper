typedef struct _TC_GEN_FILTER {
  USHORT AddressType;
  ULONG  PatternSize;
  PVOID  Pattern;
  PVOID  Mask;
} TC_GEN_FILTER, *PTC_GEN_FILTER;