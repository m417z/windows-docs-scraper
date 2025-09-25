HRESULT CreateMetaCommand(
  [in]           REFGUID    CommandId,
  [in]           UINT       NodeMask,
  [in, optional] const void *pCreationParametersData,
  [in]           SIZE_T     CreationParametersDataSizeInBytes,
                 REFIID     riid,
  [out]          void       **ppMetaCommand
);