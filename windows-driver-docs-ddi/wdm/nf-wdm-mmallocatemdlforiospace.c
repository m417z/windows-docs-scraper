NTSTATUS MmAllocateMdlForIoSpace(
  [in]  PMM_PHYSICAL_ADDRESS_LIST PhysicalAddressList,
  [in]  SIZE_T                    NumberOfEntries,
  [out] PMDL                      *NewMdl
);