void SM_RemovePersistentBinding(
   [in, HBAType("HBA_WWN")] uint8                      HbaPortWWN[8],
   [in, HBAType("HBA_WWN")] uint8                      DomainPortWWN[8],
   [in] uint32                                         EntryCount,
   [in, WmiSizeIs("EntryCount")] MS_SMHBA_BINDINGENTRY Entry[],
   [out, HBA_STATUS_QUALIFIERS] HBA_STATUS             HBAStatus
);