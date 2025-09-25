typedef struct tagKSCAMERA_METADATA_BACKGROUNDSEGMENTATIONMASK {
  KSCAMERA_METADATA_ITEMHEADER Header;
  RECT                         MaskCoverageBoundingBox;
  SIZE                         MaskResolution;
  RECT                         ForegroundBoundingBox;
  BYTE                         MaskData[1];
} KSCAMERA_METADATA_BACKGROUNDSEGMENTATIONMASK, *PKSCAMERA_METADATA_BACKGROUNDSEGMENTATIONMASK;