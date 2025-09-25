HBA_STATUS HBA_API HBA_SendLIRR(
  HBA_HANDLE Handle,
  HBA_WWN    SourceWWN,
  HBA_WWN    DestWWN,
  HBA_UINT8  Function,
  HBA_UINT8  Type,
  void       *pRspBuffer,
  HBA_UINT32 *pRspBufferSize
);