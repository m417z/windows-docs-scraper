typedef struct _DXGK_QUERYSEGMENTIN {
  [in] PHYSICAL_ADDRESS  AgpApertureBase;
  [in] LARGE_INTEGER     AgpApertureSize;
  [in] DXGK_SEGMENTFLAGS AgpFlags;
} DXGK_QUERYSEGMENTIN;