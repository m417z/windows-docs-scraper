HBA_STATUS HBA_API SMHBA_SendSMPPassThru(
  HBA_HANDLE Handle,
  HBA_WWN    HbaPortWWN,
  HBA_WWN    DestPortWWN,
  HBA_WWN    DomainPortWWN,
  void       *ReqBuffer,
  HBA_UINT32 ReqBufferSize,
  void       *RspBuffer,
  HBA_UINT32 *RspBufferSize
);