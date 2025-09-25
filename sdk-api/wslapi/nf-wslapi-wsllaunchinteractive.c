HRESULT WslLaunchInteractive(
  [in]           PCWSTR distributionName,
  [in, optional] PCWSTR command,
  [in]           BOOL   useCurrentWorkingDirectory,
  [out]          DWORD  *exitCode
);