HRESULT WDSCLIAPI WdsCliTransferFile(
  [in]           PCWSTR             pwszServer,
  [in]           PCWSTR             pwszNamespace,
  [in]           PCWSTR             pwszRemoteFilePath,
  [in]           PCWSTR             pwszLocalFilePath,
  [in]           DWORD              dwFlags,
  [in]           DWORD              dwReserved,
  [in, optional] PFN_WdsCliCallback pfnWdsCliCallback,
  [in, optional] PVOID              pvUserData,
  [out]          PHANDLE            phTransfer
);