LPDHCP_ENTRY_POINT_FUNC LpdhcpEntryPointFunc;

DWORD LpdhcpEntryPointFunc(
  [in]  LPWSTR ChainDlls,
  [in]  DWORD CalloutVersion,
  [out] LPDHCP_CALLOUT_TABLE CalloutTbl
)
{...}