NTSTATUS FwpmBfeStateSubscribeChanges0(
  [in, out]      void                                *deviceObject,
  [in]           FWPM_SERVICE_STATE_CHANGE_CALLBACK0 callback,
  [in, optional] void                                *context,
  [out]          HANDLE                              *changeHandle
);