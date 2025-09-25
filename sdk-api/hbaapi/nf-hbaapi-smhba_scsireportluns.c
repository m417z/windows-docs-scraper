HBA_STATUS HBA_API SMHBA_ScsiReportLuns(
  HBA_HANDLE Hbahandle,
  HBA_WWN    HbaPortWWN,
  HBA_WWN    DiscoveredPortWWN,
  HBA_WWN    DomainPortWWN,
  void       *pRespBuffer,
  HBA_UINT32 *pRespBufferSize,
  HBA_UINT8  *pScsiStatus,
  void       *pSenseBuffer,
  HBA_UINT32 *pSenseBufferSize
);