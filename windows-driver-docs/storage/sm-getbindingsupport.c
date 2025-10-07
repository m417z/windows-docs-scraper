void SM_GetBindingSupport(
   [in, HBAType("HBA_WWN")] uint8                 HbaPortWWN[8],
   [in, HBAType("HBA_WWN")] uint8                 DomainPortWWN[8],
   [out, HBA_STATUS_QUALIFIERS] HBA_STATUS        HBAStatus,
   [out, HBAType("SMHBA_BIND_CAPABILITY")] uint32 Flags
);