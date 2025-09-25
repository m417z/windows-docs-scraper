DMA_SUSPEND_HANDLER DmaSuspendHandler;

NTSTATUS DmaSuspendHandler(
  [in]  PVOID ProviderChannelContext,
  [out] PPHYSICAL_ADDRESS *pLastDescriptor
)
{...}