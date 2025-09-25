HRESULT CreateVideoExtensionCommand(
  const D3D12_VIDEO_EXTENSION_COMMAND_DESC *pDesc,
  const void                               *pCreationParameters,
  SIZE_T                                   CreationParametersDataSizeInBytes,
  ID3D12ProtectedResourceSession           *pProtectedResourceSession,
  REFIID                                   riid,
  void                                     **ppVideoExtensionCommand
);