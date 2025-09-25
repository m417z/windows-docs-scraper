ULONG EVNTAPI EventRegister(
  [in]           LPCGUID         ProviderId,
  [in, optional] PENABLECALLBACK EnableCallback,
  [in, optional] PVOID           CallbackContext,
  [out]          PREGHANDLE      RegHandle
);