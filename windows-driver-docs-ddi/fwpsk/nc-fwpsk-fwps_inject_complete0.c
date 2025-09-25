FWPS_INJECT_COMPLETE0 FwpsInjectComplete0;

void FwpsInjectComplete0(
  [in]      void *context,
  [in, out] NET_BUFFER_LIST *netBufferList,
  [in]      BOOLEAN dispatchLevel
)
{...}