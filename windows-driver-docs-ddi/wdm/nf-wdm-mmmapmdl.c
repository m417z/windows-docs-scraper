NTSTATUS MmMapMdl(
  [in] PMDL            MemoryDescriptorList,
  [in] ULONG           Protection,
  [in] PMM_MDL_ROUTINE DriverRoutine,
  [in] PVOID           DriverContext
);