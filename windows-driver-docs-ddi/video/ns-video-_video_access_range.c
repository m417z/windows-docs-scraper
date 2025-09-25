typedef struct _VIDEO_ACCESS_RANGE {
  PHYSICAL_ADDRESS RangeStart;
  ULONG            RangeLength;
  UCHAR            RangeInIoSpace;
  UCHAR            RangeVisible;
  UCHAR            RangeShareable;
  UCHAR            RangePassive;
} VIDEO_ACCESS_RANGE, *PVIDEO_ACCESS_RANGE;