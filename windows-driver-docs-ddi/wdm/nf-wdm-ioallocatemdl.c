PMDL IoAllocateMdl(
  [in, optional]      __drv_aliasesMem PVOID VirtualAddress,
  [in]                ULONG                  Length,
  [in]                BOOLEAN                SecondaryBuffer,
  [in]                BOOLEAN                ChargeQuota,
  [in, out, optional] PIRP                   Irp
);