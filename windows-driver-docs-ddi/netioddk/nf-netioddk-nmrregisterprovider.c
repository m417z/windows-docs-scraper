NTSTATUS NmrRegisterProvider(
  [in]  PNPI_PROVIDER_CHARACTERISTICS ProviderCharacteristics,
  [in]  __drv_aliasesMem PVOID        ProviderContext,
  [out] PHANDLE                       NmrProviderHandle
);