HBA_STATUS HBA_API HBA_SendSRL(
  HBA_HANDLE Handle,
  HBA_WWN    HbaPortWWN,
  HBA_WWN    Wwn,
  HBA_UINT32 Domain,
  void       *pRspBuffer,
  HBA_UINT32 *pRspBufferSize
);