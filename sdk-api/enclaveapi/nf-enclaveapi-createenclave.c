LPVOID CreateEnclave(
  [in]            HANDLE  hProcess,
  [in, optional]  LPVOID  lpAddress,
  [in]            SIZE_T  dwSize,
  [in]            SIZE_T  dwInitialCommitment,
  [in]            DWORD   flEnclaveType,
  [in]            LPCVOID lpEnclaveInformation,
  [in]            DWORD   dwInfoLength,
  [out, optional] LPDWORD lpEnclaveError
);