HBA_STATUS HBA_API HBA_SendCTPassThruV2(
  HBA_HANDLE Handle,
  HBA_WWN    HbaPortWWN,
  void       *pReqBuffer,
  HBA_UINT32 ReqBufferSize,
  void       *pRspBuffer,
  HBA_UINT32 *pRspBufferSize
);