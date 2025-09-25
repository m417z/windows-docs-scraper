typedef struct _NET_WAKE_SOURCE_BITMAP_PARAMETERS {
  ULONG       Size;
  ULONG       Id;
  UCHAR const *Pattern;
  SIZE_T      PatternSize;
  UCHAR const *Mask;
  SIZE_T      MaskSize;
} NET_WAKE_SOURCE_BITMAP_PARAMETERS;