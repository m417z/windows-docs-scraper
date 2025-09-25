HBA_STATUS HBA_API SMHBA_ScsiInquiry(
  HBA_HANDLE  HbaHandle,
  HBA_WWN     HbaPortWWN,
  HBA_WWN     DiscoveredPortWWN,
  HBA_WWN     DomainPortWWN,
  HBA_SCSILUN SmhbaLUN,
  HBA_UINT8   CDB_Byte1,
  HBA_UINT8   CDB_Byte2,
  void        *pRespBuffer,
  HBA_UINT32  *pRespBufferSize,
  HBA_UINT8   *pScsiStatus,
  void        *pSenseBuffer,
  HBA_UINT32  *pSenseBufferSize
);