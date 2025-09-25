LPVOID CreateFiberEx(
  [in]           SIZE_T                dwStackCommitSize,
  [in]           SIZE_T                dwStackReserveSize,
  [in]           DWORD                 dwFlags,
  [in]           LPFIBER_START_ROUTINE lpStartAddress,
  [in, optional] LPVOID                lpParameter
);