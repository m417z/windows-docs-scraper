HRESULT CfGetSyncRootInfoByHandle(
  [in]            HANDLE                  FileHandle,
  [in]            CF_SYNC_ROOT_INFO_CLASS InfoClass,
  [out]           PVOID                   InfoBuffer,
  [in]            DWORD                   InfoBufferLength,
  [out, optional] DWORD                   *ReturnedLength
);