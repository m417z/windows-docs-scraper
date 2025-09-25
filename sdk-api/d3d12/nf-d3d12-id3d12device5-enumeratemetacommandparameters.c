HRESULT EnumerateMetaCommandParameters(
  [in]            REFGUID                            CommandId,
  [in]            D3D12_META_COMMAND_PARAMETER_STAGE Stage,
  [out, optional] UINT                               *pTotalStructureSizeInBytes,
  [in, out]       UINT                               *pParameterCount,
  [out, optional] D3D12_META_COMMAND_PARAMETER_DESC  *pParameterDescs
);