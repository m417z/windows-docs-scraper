typedef struct {
  ULONG PelsWidth;
  ULONG PelsHeight;
  ULONG BitsPerPel;
  WCHAR DeviceID[1];
} KSDISPLAYCHANGE, *PKSDISPLAYCHANGE;