DWORD IPsecSaContextSubscribe0(
  [in]           HANDLE                               engineHandle,
  [in]           const IPSEC_SA_CONTEXT_SUBSCRIPTION0 *subscription,
  [in]           IPSEC_SA_CONTEXT_CALLBACK0           callback,
  [in, optional] void                                 *context,
  [out]          HANDLE                               *eventsHandle
);