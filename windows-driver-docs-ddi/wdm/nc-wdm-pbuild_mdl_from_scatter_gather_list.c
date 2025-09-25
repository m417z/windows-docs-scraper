PBUILD_MDL_FROM_SCATTER_GATHER_LIST PbuildMdlFromScatterGatherList;

NTSTATUS PbuildMdlFromScatterGatherList(
  [in]  PDMA_ADAPTER DmaAdapter,
  [in]  PSCATTER_GATHER_LIST ScatterGather,
  [in]  PMDL OriginalMdl,
  [out] PMDL *TargetMdl
)
{...}