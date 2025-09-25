PCALCULATE_SCATTER_GATHER_LIST_SIZE PcalculateScatterGatherListSize;

NTSTATUS PcalculateScatterGatherListSize(
  [in]            PDMA_ADAPTER DmaAdapter,
  [in, optional]  PMDL Mdl,
  [in]            PVOID CurrentVa,
  [in]            ULONG Length,
  [out]           PULONG ScatterGatherListSize,
  [out, optional] PULONG pNumberOfMapRegisters
)
{...}