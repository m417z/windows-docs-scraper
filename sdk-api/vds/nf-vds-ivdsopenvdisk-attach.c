HRESULT Attach(
  [in]  LPWSTR                   pStringSecurityDescriptor,
  [in]  ATTACH_VIRTUAL_DISK_FLAG Flags,
  [in]  ULONG                    ProviderSpecificFlags,
  [in]  ULONG                    TimeoutInMs,
  [out] IVdsAsync                **ppAsync
);