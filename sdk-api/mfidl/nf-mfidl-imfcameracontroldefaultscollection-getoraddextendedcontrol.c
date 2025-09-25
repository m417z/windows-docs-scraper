HRESULT GetOrAddExtendedControl(
  [in]  MF_CAMERA_CONTROL_CONFIGURATION_TYPE configType,
  [in]  ULONG                                constrolId,
  [in]  DWORD                                streamId,
  [in]  ULONG                                dataSize,
  [out] IMFCameraControlDefaults             **defaults
);