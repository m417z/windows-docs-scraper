PAC_CHANGES_CALLBACK_FN PacChangesCallbackFn;

void PacChangesCallbackFn(
  [in, optional] void *context,
  [in]           const INET_FIREWALL_AC_CHANGE *pChange
)
{...}