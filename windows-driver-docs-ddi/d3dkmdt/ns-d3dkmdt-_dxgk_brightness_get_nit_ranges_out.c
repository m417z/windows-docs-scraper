typedef struct _DXGK_BRIGHTNESS_GET_NIT_RANGES_OUT {
  UINT32                    NormalRangeCount;
  UINT32                    RangeCount;
  UINT32                    PreferredMaximumBrightness;
  DXGK_BRIGHTNESS_NIT_RANGE SupportedRanges[DXGK_BRIGHTNESS_MAXIMUM_NIT_RANGE_COUNT];
} DXGK_BRIGHTNESS_GET_NIT_RANGES_OUT, *PDXGK_BRIGHTNESS_GET_NIT_RANGES_OUT;