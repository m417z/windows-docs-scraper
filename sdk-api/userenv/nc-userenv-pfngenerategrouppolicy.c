PFNGENERATEGROUPPOLICY Pfngenerategrouppolicy;

DWORD Pfngenerategrouppolicy(
  [in] DWORD dwFlags,
  [in] BOOL *pbAbort,
  [in] WCHAR *pwszSite,
  [in] PRSOP_TARGET pComputerTarget,
  [in] PRSOP_TARGET pUserTarget
)
{...}