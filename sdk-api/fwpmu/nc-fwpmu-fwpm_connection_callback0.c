FWPM_CONNECTION_CALLBACK0 FwpmConnectionCallback0;

void FwpmConnectionCallback0(
  [in, out] void *context,
  [in]      FWPM_CONNECTION_EVENT_TYPE eventType,
  [in]      const FWPM_CONNECTION0 *connection
)
{...}