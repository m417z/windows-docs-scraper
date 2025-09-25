typedef struct _MFCameraExtrinsic_CalibratedTransform {
  GUID          CalibrationId;
  MF_FLOAT3     Position;
  MF_QUATERNION Orientation;
} MFCameraExtrinsic_CalibratedTransform;