HRESULT ExecuteExtensionCommand(
  ID3D12VideoExtensionCommand *pExtensionCommand,
  const void                  *pExecutionParameters,
  SIZE_T                      ExecutionParametersSizeInBytes,
  void                        *pOutputData,
  SIZE_T                      OutputDataSizeInBytes
);