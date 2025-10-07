void SM_SetBindingSupport(
   [in, HBAType("HBA_WWN")] uint8                HbaPortWWN[8],
   [in, HBAType("HBA_WWN")] uint8                DomainPortWWN[8],
   [in, HBAType("SMHBA_BIND_CAPABILITY")] uint32 Flags,
   [out, HBA_STATUS_QUALIFIERS] HBA_STATUS       HBAStatus
);