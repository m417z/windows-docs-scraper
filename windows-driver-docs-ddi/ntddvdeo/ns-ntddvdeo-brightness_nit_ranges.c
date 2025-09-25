typedef struct BRIGHTNESS_NIT_RANGES {
  ULONG                NormalRangeCount;
  ULONG                RangeCount;
  ULONG                PreferredMaximumBrightness;
  BRIGHTNESS_NIT_RANGE SupportedRanges[BRIGHTNESS_MAX_NIT_RANGE_COUNT];
} BRIGHTNESS_NIT_RANGES, *PBRIGHTNESS_NIT_RANGES;