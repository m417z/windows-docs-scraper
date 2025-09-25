HBA_STATUS HBA_API HBA_SendRPL(
  HBA_HANDLE Handle,
  HBA_WWN    HbaPortWWN,
  HBA_WWN    Agent_wwn,
  HBA_UINT32 Agent_domain,
  HBA_UINT32 PortIndex,
  void       *pRspBuffer,
  HBA_UINT32 *pRspBufferSize
);