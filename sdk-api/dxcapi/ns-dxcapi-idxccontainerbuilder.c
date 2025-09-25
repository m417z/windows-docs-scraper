struct IDxcContainerBuilder : IUnknown {
  HRESULT Load(
    IDxcBlob *pDxilContainerHeader
  );
  HRESULT AddPart(
    UINT32   fourCC,
    IDxcBlob *pSource
  );
  HRESULT RemovePart(
    UINT32 fourCC
  );
  HRESULT SerializeContainer(
    IDxcOperationResult **ppResult
  );
};