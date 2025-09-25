HBA_STATUS HBA_API HBA_RegisterForTargetEvents(
  void(* )(void *pData,HBA_WWN hbaPortWWN,HBA_WWN discoveredPortWWN,HBA_UINT32 eventType) callback,
  void                                                                                    *pUserData,
  HBA_HANDLE                                                                              Handle,
  HBA_WWN                                                                                 HbaPortWWN,
  HBA_WWN                                                                                 DiscoveredPortWWN,
  HBA_CALLBACKHANDLE                                                                      *pCallbackHandle,
  HBA_UINT32                                                                              AllTargets
);