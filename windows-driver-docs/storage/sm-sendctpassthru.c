void SM_SendCTPassThru(
   [in, HBAType("HBA_WWN")] uint8              HbaPortWWN[8],
   [in] uint32                                 InRespBufferMaxSize,
   [in] uint32                                 RequestBufferSize,
   [in, WmiSizeIs("RequestBufferSize")] uint8  RequestBuffer,
   [out, HBA_STATUS_QUALIFIERS] HBA_STATUS     HBAStatus,
   [out] uint32                                TotalResponseBufferSize,
   [out] uint32                                ActualResponseBufferSize,
   [out, WmiSizeIs("OutRespBufferSize")] uint8 ResponseBuffer[]
);