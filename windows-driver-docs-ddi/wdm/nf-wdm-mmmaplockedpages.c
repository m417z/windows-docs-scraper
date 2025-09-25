PVOID MmMapLockedPages(
  [in] PMDL                                                                          MemoryDescriptorList,
  [in] __drv_strictType(KPROCESSOR_MODE / enum _MODE,__drv_typeConst)KPROCESSOR_MODE AccessMode
);