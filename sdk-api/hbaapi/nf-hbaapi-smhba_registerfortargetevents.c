HBA_STATUS HBA_API SMHBA_RegisterForTargetEvents(
  void(* )(void *pData,HBA_WWN HbaPortWWN,HBA_WWN DiscoveredPortWWN,HBA_WWN DomainPortWWN,HBA_UINT32 EventType) callback,
  void                                                                                                          *pUserData,
  HBA_HANDLE                                                                                                    Handle,
  HBA_WWN                                                                                                       HbaPortWWN,
  HBA_WWN                                                                                                       DiscoveredPortWWN,
  HBA_WWN                                                                                                       DomainPortWWN,
  HBA_CALLBACKHANDLE                                                                                            *pCallbackHandle,
  HBA_UINT32                                                                                                    AllTargets
);