PCREATE_COMMON_BUFFER_FROM_MDL PcreateCommonBufferFromMdl;

NTSTATUS PcreateCommonBufferFromMdl(
  [in]  PDMA_ADAPTER DmaAdapter,
  [in]  PMDL Mdl,
  [in]  PDMA_COMMON_BUFFER_EXTENDED_CONFIGURATION ExtendedConfigs,
  [in]  ULONG ExtendedConfigsCount,
  [out] PPHYSICAL_ADDRESS LogicalAddress
)
{...}