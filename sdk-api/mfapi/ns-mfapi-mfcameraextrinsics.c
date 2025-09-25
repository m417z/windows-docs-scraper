typedef struct _MFCameraExtrinsics {
  UINT32                                TransformCount;
  MFCameraExtrinsic_CalibratedTransform CalibratedTransforms[1];
} MFCameraExtrinsics;