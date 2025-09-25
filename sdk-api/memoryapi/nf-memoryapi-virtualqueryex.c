SIZE_T VirtualQueryEx(
  [in]           HANDLE                    hProcess,
  [in, optional] LPCVOID                   lpAddress,
  [out]          PMEMORY_BASIC_INFORMATION lpBuffer,
  [in]           SIZE_T                    dwLength
);