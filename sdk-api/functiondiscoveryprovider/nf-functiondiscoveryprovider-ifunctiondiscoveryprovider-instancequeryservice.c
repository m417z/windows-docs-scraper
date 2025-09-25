HRESULT InstanceQueryService(
  [in]  IFunctionInstance *pIFunctionInstance,
  [in]  INT_PTR           iProviderInstanceContext,
  [in]  REFGUID           guidService,
  [in]  REFIID            riid,
  [out] IUnknown          **ppIUnknown
);