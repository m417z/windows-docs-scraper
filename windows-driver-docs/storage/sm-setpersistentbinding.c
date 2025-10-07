void SM_SetPersistentBinding(
   [in, HBAType("HBA_WWN")] uint8                        HbaPortWWN[8],
   [in, HBAType("HBA_WWN")] uint8                        DomainPortWWN[8],
   [in] uint32                                           InEntryCount,
   [in, WmiSizeIs("InEntryCount")] MS_SMHBA_BINDINGENTRY Entry[],
   [out, HBA_STATUS_QUALIFIERS] HBA_STATUS               HBAStatus,
   [out] uint32                                          OutStatusCount,
   [out, HBA_STATUS_QUALIFIERS] HBA_STATUS               EntryStatus
);