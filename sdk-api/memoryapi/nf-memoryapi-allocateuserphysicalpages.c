BOOL AllocateUserPhysicalPages(
  [in]      HANDLE     hProcess,
  [in, out] PULONG_PTR NumberOfPages,
  [out]     PULONG_PTR PageArray
);