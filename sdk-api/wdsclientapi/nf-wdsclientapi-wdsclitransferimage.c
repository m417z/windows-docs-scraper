HRESULT WDSCLIAPI WdsCliTransferImage(
  [in]           HANDLE             hImage,
  [in]           PWSTR              pwszLocalPath,
  [in]           DWORD              dwFlags,
  [in]           DWORD              dwReserved,
  [in, optional] PFN_WdsCliCallback pfnWdsCliCallback,
  [in, optional] PVOID              pvUserData,
  [out]          PHANDLE            phTransfer
);