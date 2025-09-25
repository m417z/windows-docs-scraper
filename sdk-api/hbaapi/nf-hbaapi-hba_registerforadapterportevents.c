HBA_STATUS HBA_API HBA_RegisterForAdapterPortEvents(
  void(* )(void *pData,HBA_WWN PortWWN,HBA_UINT32 eventType,HBA_UINT32 fabricPortID) callback,
  void                                                                               *UserData,
  HBA_HANDLE                                                                         Handle,
  HBA_WWN                                                                            PortWWN,
  HBA_CALLBACKHANDLE                                                                 *pCallbackHandle
);