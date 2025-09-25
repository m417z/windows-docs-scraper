HBA_STATUS HBA_API HBA_ScsiReportLUNsV2(
  HBA_HANDLE Hbahandle,
  HBA_WWN    HbaPortWWN,
  HBA_WWN    DiscoveredPortWWN,
  void       *pRespBuffer,
  HBA_UINT32 *pRespBufferSize,
  HBA_UINT8  *pScsiStatus,
  void       *pSenseBuffer,
  HBA_UINT32 *pSenseBufferSize
);