BOOL LoadEnclaveData(
  [in]            HANDLE  hProcess,
  [in]            LPVOID  lpAddress,
  [in]            LPCVOID lpBuffer,
  [in]            SIZE_T  nSize,
  [in]            DWORD   flProtect,
  [in]            LPCVOID lpPageInformation,
  [in]            DWORD   dwInfoLength,
  [out]           PSIZE_T lpNumberOfBytesWritten,
  [out, optional] LPDWORD lpEnclaveError
);