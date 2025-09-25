HBA_STATUS HBA_API SMHBA_ScsiReadCapacity(
  HBA_HANDLE  HbaHandle,
  HBA_WWN     HbaPortWWN,
  HBA_WWN     DiscoveredPortWWN,
  HBA_WWN     DomainPortWWN,
  HBA_SCSILUN SmhbaLUN,
  void        *pRespBuffer,
  HBA_UINT32  *pRespBufferSize,
  HBA_UINT8   *pScsiStatus,
  void        *pSenseBuffer,
  HBA_UINT32  *pSenseBufferSize
);