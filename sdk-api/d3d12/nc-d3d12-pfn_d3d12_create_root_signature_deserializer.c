PFN_D3D12_CREATE_ROOT_SIGNATURE_DESERIALIZER PfnD3d12CreateRootSignatureDeserializer;

HRESULT PfnD3d12CreateRootSignatureDeserializer(
  LPCVOID pSrcData,
  SIZE_T SrcDataSizeInBytes,
  REFIID pRootSignatureDeserializerInterface,
  void **ppRootSignatureDeserializer
)
{...}