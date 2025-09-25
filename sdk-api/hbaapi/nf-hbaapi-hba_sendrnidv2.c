HBA_STATUS HBA_API HBA_SendRNIDV2(
  HBA_HANDLE Handle,
  HBA_WWN    HbaPortWWN,
  HBA_WWN    DestWWN,
  HBA_UINT32 DestFCID,
  HBA_UINT32 NodeIdDataFormat,
  void       *pRspBuffer,
  HBA_UINT32 *pRspBufferSize
);