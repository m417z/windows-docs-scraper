void SM_ScsiInquiry(
   [in, HBAType("HBA_WWN")] uint8               HbaPortWWN[8],
   [in, HBAType("HBA_WWN")] uint8               DiscoveredPortWWN[8],
   [in, HBAType("HBA_WWN")] uint8               DomainPortWWN[8],
   [in, HBAType("HBA_SCSILUN")] uint64          SmhbaLUN,
   [in] uint8                                   Cdb[6],
   [in] uint32                                  InRespBufferMaxSize,
   [in] uint32                                  InSenseBufferMaxSize,
   [out, HBA_STATUS_QUALIFIERS] HBA_STATUS      HBAStatus,
   [out] uint8                                  ScsiStatus,
   [out] uint32                                 OutRespBufferSize,
   [out] uint32                                 OutSenseBufferSize,
   [out, WmiSizeIs("OutRespBufferSize")] uint8  RespBuffer[],
   [out, WmiSizeIs("OutSenseBufferSize")] uint8 SenseBuffer[]
);