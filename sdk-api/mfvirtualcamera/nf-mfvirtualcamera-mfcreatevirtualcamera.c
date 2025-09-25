HRESULT MFCreateVirtualCamera(
  MFVirtualCameraType     type,
  MFVirtualCameraLifetime lifetime,
  MFVirtualCameraAccess   access,
  LPCWSTR                 friendlyName,
  LPCWSTR                 sourceId,
  const GUID              *categories,
  ULONG                   categoryCount,
  IMFVirtualCamera        **virtualCamera
);