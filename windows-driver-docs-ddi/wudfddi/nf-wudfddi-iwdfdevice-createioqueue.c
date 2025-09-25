HRESULT CreateIoQueue(
  [in, optional] IUnknown                   *pCallbackInterface,
  [in]           BOOL                       bDefaultQueue,
  [in]           WDF_IO_QUEUE_DISPATCH_TYPE DispatchType,
  [in]           BOOL                       bPowerManaged,
  [in]           BOOL                       bAllowZeroLengthRequests,
  [out]          IWDFIoQueue                **ppIoQueue
);