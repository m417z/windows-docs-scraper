struct IDxcValidator2 : IDxcValidator {
  HRESULT ValidateWithDebug(
    IDxcBlob            *pShader,
    UINT32              Flags,
    DxcBuffer           *pOptDebugBitcode,
    IDxcOperationResult **ppResult
  );
};