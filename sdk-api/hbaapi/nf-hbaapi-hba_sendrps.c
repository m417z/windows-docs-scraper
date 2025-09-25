HBA_STATUS HBA_API HBA_SendRPS(
  HBA_HANDLE Handle,
  HBA_WWN    HbaPortWWN,
  HBA_WWN    Agent_wwn,
  HBA_UINT32 Agent_domain,
  HBA_WWN    Object_wwn,
  HBA_UINT32 Object_port_number,
  void       *pRspBuffer,
  HBA_UINT32 *pRspBufferSize
);