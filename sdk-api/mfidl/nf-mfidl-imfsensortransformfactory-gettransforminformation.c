HRESULT GetTransformInformation(
  [in]  DWORD         TransformIndex,
  [out] GUID          *pguidTransformId,
  [out] IMFAttributes **ppAttributes,
  [out] IMFCollection **ppStreamInformation
);