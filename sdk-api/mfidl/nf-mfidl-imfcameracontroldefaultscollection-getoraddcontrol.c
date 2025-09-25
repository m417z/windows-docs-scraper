HRESULT GetOrAddControl(
  MF_CAMERA_CONTROL_CONFIGURATION_TYPE configType,
  REFGUID                              controlSet,
  ULONG                                constrolId,
  ULONG                                controlSize,
  ULONG                                dataSize,
  IMFCameraControlDefaults             **defaults
);