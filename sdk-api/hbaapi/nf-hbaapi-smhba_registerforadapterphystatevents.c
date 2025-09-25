HBA_STATUS HBA_API SMHBA_RegisterForAdapterPhyStatEvents(
  void(* )(void *pData,HBA_WWN PortWWN,HBA_UINT32 PhyIndex,HBA_UINT32 EventType) callback,
  void                                                                           *pUserData,
  HBA_HANDLE                                                                     Handle,
  HBA_WWN                                                                        PortWWN,
  HBA_UINT32                                                                     PhyIndex,
  SMHBA_PHYSTATISTICS                                                            Stats,
  HBA_UINT32                                                                     StatType,
  HBA_CALLBACKHANDLE                                                             *pCallbackHandle
);