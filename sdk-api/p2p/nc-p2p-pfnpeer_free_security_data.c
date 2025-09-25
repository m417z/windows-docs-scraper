PFNPEER_FREE_SECURITY_DATA PfnpeerFreeSecurityData;

HRESULT PfnpeerFreeSecurityData(
  [in] HGRAPH hGraph,
  [in] PVOID pvContext,
  [in] PPEER_DATA pSecurityData
)
{...}