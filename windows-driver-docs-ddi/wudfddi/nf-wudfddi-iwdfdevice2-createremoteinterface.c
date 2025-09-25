HRESULT CreateRemoteInterface(
  [in]           IWDFRemoteInterfaceInitialize *pRemoteInterfaceInit,
  [in, optional] IUnknown                      *pCallbackInterface,
  [out]          IWDFRemoteInterface           **ppRemoteInterface
);