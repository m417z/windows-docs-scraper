HBA_STATUS HBA_API SMHBA_RegisterForAdapterAddEvents(
  void(* )(void *pData,HBA_WWN PortWWN,HBA_UINT32 eventType) callback,
  void                                                       *pUserData,
  HBA_CALLBACKHANDLE                                         *pCallbackHandle
);