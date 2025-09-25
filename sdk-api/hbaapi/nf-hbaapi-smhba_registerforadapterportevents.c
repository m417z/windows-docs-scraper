HBA_STATUS HBA_API SMHBA_RegisterForAdapterPortEvents(
  void(* )(void *pData,HBA_WWN PortWWN,HBA_UINT32 eventType,HBA_UINT32 fabricPortID) callback,
  void                                                                               *pUserData,
  HBA_HANDLE                                                                         Handle,
  HBA_WWN                                                                            PortWWN,
  HBA_UINT32                                                                         SpecificEventType,
  HBA_CALLBACKHANDLE                                                                 *pCallbackHandle
);