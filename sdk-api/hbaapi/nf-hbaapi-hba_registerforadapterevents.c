HBA_STATUS HBA_API HBA_RegisterForAdapterEvents(
  void(* )(void *pData,HBA_WWN PortWWN,HBA_UINT32 eventType) callback,
  void                                                       *pUserData,
  HBA_HANDLE                                                 Handle,
  HBA_CALLBACKHANDLE                                         *pCallbackHandle
);