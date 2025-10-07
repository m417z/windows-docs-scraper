void ScsiReadCapacity(
   [out, HBA_STATUS_QUALIFIERS] HBA_STATUS      HBAStatus,
   [in] uint8                                   Cdb[10],
   [in, HBAType("HBA_WWN")] uint8               HbaPortWWN[10],
   [in, HBAType("HBA_WWN")] uint8               DiscoveredPortWWN[10],
   [in] uint64                                  FcLun,
   [out] uint32                                 ResponseBufferSize,
   [out] uint32                                 SenseBufferSize,
   [out] uint8                                  ScsiStatus,
   [out, WmiSizeIs("ResponseBufferSize")] uint8 ResponseBuffer[],
   [out, WmiSizeIs("SenseBufferSize")] uint8    SenseBuffer[]
);