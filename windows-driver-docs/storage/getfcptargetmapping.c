void GetFcpTargetMapping(
   [in, HBAType("HBA_WWN")] uint8                    HbaPortWWN[8],
   [in] uint32                                       InEntryCount,
   [out, HBA_STATUS_QUALIFIERS] HBA_STATUS           HBAStatus,
   [out] uint32                                      TotalEntryCount,
   [out] uint32                                      OutEntryCount,
   [out, WmiSizeIs("OutEntryCount")] HBAFCPScsiEntry Entry[]
);