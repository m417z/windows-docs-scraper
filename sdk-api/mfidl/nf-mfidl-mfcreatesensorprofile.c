HRESULT MFCreateSensorProfile(
  [in]           REFGUID          ProfileType,
  [in, out]      UINT32           ProfileIndex,
  [in, optional] LPCWSTR          Constraints,
  [out]          IMFSensorProfile **ppProfile
);