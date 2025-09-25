HBA_STATUS HBA_API HBA_SendScsiInquiry(
  HBA_HANDLE Handle,
  HBA_WWN    PortWWN,
  HBA_UINT64 FcLUN,
  HBA_UINT8  EVPD,
  HBA_UINT32 PageCode,
  void       *pRspBuffer,
  HBA_UINT32 RspBufferSize,
  void       *pSenseBuffer,
  HBA_UINT32 SenseBufferSize
);