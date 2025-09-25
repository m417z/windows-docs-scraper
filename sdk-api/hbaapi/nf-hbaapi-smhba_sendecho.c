HBA_STATUS HBA_API SMHBA_SendECHO(
  HBA_HANDLE Handle,
  HBA_WWN    HbaPortWWN,
  HBA_WWN    DestWWN,
  HBA_UINT32 DestFCID,
  void       *ReqBuffer,
  HBA_UINT32 ReqBufferSize,
  void       *RspBuffer,
  HBA_UINT32 *RspBufferSize
);