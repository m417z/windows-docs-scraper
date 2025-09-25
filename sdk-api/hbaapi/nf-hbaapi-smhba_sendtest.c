HBA_STATUS HBA_API SMHBA_SendTEST(
  HBA_HANDLE Handle,
  HBA_WWN    HbaPortWWN,
  HBA_WWN    DestWWN,
  HBA_UINT32 DestFCID,
  void       *ReqBuffer,
  HBA_UINT32 ReqBufferSize
);