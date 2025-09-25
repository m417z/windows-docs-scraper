QUERY_MIRACAST_DRIVER_INTERFACE QueryMiracastDriverInterface;

NTSTATUS QueryMiracastDriverInterface(
  [in]  UINT MiracastDriverInterfaceVersion,
  [in]  UINT MiracastDriverInterfaceSize,
  [out] VOID *pMiracastDriverInterface
)
{...}