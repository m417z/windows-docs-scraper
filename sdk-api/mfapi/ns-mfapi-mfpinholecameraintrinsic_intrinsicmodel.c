typedef struct _MFPinholeCameraIntrinsic_IntrinsicModel {
  UINT32                               Width;
  UINT32                               Height;
  MFCameraIntrinsic_PinholeCameraModel CameraModel;
  MFCameraIntrinsic_DistortionModel    DistortionModel;
} MFPinholeCameraIntrinsic_IntrinsicModel;