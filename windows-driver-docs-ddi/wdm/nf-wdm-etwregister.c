NTSTATUS EtwRegister(
  [in]           LPCGUID            ProviderId,
  [in, optional] PETWENABLECALLBACK EnableCallback,
  [in, optional] PVOID              CallbackContext,
  [out]          PREGHANDLE         RegHandle
);