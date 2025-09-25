HBA_STATUS HBA_API HBA_SendRLS(
  HBA_HANDLE HbaHandle,
  HBA_WWN    HbaPortWWN,
  HBA_WWN    DestWWN,
  void       *pRspBuffer,
  HBA_UINT32 *pRspBufferSize
);