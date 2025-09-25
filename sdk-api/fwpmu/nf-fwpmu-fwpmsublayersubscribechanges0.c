DWORD FwpmSubLayerSubscribeChanges0(
  [in]           HANDLE                            engineHandle,
  [in]           const FWPM_SUBLAYER_SUBSCRIPTION0 *subscription,
  [in]           FWPM_SUBLAYER_CHANGE_CALLBACK0    callback,
  [in, optional] void                              *context,
  [out]          HANDLE                            *changeHandle
);