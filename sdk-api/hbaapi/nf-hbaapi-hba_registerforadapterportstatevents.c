HBA_STATUS HBA_API HBA_RegisterForAdapterPortStatEvents(
  void(* )(void *pData,HBA_WWN PortWWN,HBA_UINT32 eventType) callback,
  void                                                       *pUserData,
  HBA_HANDLE                                                 Handle,
  HBA_WWN                                                    PortWWN,
  HBA_PORTSTATISTICS                                         stats,
  HBA_UINT32                                                 statType,
  HBA_CALLBACKHANDLE                                         *pCallbackHandle
);