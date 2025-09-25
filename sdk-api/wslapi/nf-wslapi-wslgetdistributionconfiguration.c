HRESULT WslGetDistributionConfiguration(
  [in]  PCWSTR                 distributionName,
  [out] ULONG                  *distributionVersion,
  [out] ULONG                  *defaultUID,
  [out] WSL_DISTRIBUTION_FLAGS *wslDistributionFlags,
  [out] PSTR                   **defaultEnvironmentVariables,
  [out] ULONG                  *defaultEnvironmentVariableCount
);