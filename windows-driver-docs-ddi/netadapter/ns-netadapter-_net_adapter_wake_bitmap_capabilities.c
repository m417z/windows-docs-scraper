typedef struct _NET_ADAPTER_WAKE_BITMAP_CAPABILITIES {
  ULONG   Size;
  BOOLEAN BitmapPattern;
  SIZE_T  MaximumPatternCount;
  SIZE_T  MaximumPatternSize;
} NET_ADAPTER_WAKE_BITMAP_CAPABILITIES;