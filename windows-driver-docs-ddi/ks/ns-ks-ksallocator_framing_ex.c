typedef struct {
  ULONG           CountItems;
  ULONG           PinFlags;
  KS_COMPRESSION  OutputCompression;
  ULONG           PinWeight;
  KS_FRAMING_ITEM FramingItem[1];
} KSALLOCATOR_FRAMING_EX, *PKSALLOCATOR_FRAMING_EX;