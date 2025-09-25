PFN_D3D12_CREATE_VERSIONED_ROOT_SIGNATURE_DESERIALIZER PfnD3d12CreateVersionedRootSignatureDeserializer;

HRESULT PfnD3d12CreateVersionedRootSignatureDeserializer(
  LPCVOID pSrcData,
  SIZE_T SrcDataSizeInBytes,
  REFIID pRootSignatureDeserializerInterface,
  void **ppRootSignatureDeserializer
)
{...}