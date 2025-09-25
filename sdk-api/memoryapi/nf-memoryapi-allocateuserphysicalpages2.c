BOOL AllocateUserPhysicalPages2(
  [in]     HANDLE                  ObjectHandle,
  [in,out] PULONG_PTR              NumberOfPages,
  [out]    PULONG_PTR              PageArray,
  [in,out] PMEM_EXTENDED_PARAMETER ExtendedParameters,
  [in]     ULONG                   ExtendedParameterCount
);