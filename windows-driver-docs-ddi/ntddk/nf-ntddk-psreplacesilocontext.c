NTSTATUS PsReplaceSiloContext(
  [in]       PESILO Silo,
  [in]       ULONG  ContextSlot,
  [in]       PVOID  NewSiloContext,
  [optional] PVOID  *OldSiloContext
);