HBA_STATUS HBA_API SMHBA_RegisterForAdapterPortStatEvents(
  void(* )(void *pData,HBA_WWN PortWWN,HBA_UINT32 ProtocolType,HBA_UINT32 EventType) callback,
  void                                                                               *pUserData,
  HBA_HANDLE                                                                         Handle,
  HBA_WWN                                                                            PortWWN,
  HBA_UINT32                                                                         ProtocolType,
  SMHBA_PROTOCOLSTATISTICS                                                           Stats,
  HBA_UINT32                                                                         StatType,
  HBA_CALLBACKHANDLE                                                                 *pCallbackHandle
);