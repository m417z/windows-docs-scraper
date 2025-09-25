HBA_STATUS HBA_API HBA_SendReportLUNs(
  HBA_HANDLE Handle,
  HBA_WWN    PortWWN,
  void       *pRspBuffer,
  HBA_UINT32 RspBufferSize,
  void       *pSenseBuffer,
  HBA_UINT32 SenseBufferSize
);