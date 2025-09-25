BOOL GetProcessAffinityMask(
  [in]  HANDLE     hProcess,
  [out] PDWORD_PTR lpProcessAffinityMask,
  [out] PDWORD_PTR lpSystemAffinityMask
);