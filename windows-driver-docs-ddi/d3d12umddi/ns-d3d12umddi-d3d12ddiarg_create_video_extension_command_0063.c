typedef struct D3D12DDIARG_CREATE_VIDEO_EXTENSION_COMMAND_0063 {
  [in] UINT                                    NodeMask;
  [in] GUID                                    CommandId;
  [in] const void                              *pCreationParameters;
       SIZE_T                                  CreationParametersDataSizeInBytes;
       D3D12DDI_HPROTECTEDRESOURCESESSION_0030 hDrvProtectedResourceSession;
} D3D12DDIARG_CREATE_VIDEO_EXTENSION_COMMAND_0063;