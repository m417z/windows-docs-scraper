NTSTATUS NmrRegisterClient(
  [in]  PNPI_CLIENT_CHARACTERISTICS ClientCharacteristics,
  [in]  __drv_aliasesMem PVOID      ClientContext,
  [out] PHANDLE                     NmrClientHandle
);