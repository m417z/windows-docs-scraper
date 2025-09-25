HBA_STATUS HBA_API HBA_SendReadCapacity(
  HBA_HANDLE Handle,
  HBA_WWN    PortWWN,
  HBA_UINT64 FcLUN,
  void       *pRspBuffer,
  HBA_UINT32 RspBufferSize,
  void       *pSenseBuffer,
  HBA_UINT32 SenseBufferSize
);