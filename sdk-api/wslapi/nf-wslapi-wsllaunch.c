HRESULT WslLaunch(
  [in]           PCWSTR distributionName,
  [in, optional] PCWSTR command,
  [in]           BOOL   useCurrentWorkingDirectory,
  [in]           HANDLE stdIn,
  [in]           HANDLE stdOut,
  [in]           HANDLE stdErr,
  [out]          HANDLE *process
);