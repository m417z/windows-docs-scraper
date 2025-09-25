HBA_STATUS HBA_API HBA_RegisterForLinkEvents(
  void(* )(void *data,HBA_WWN adapterWWN,HBA_UINT32 eventType, void *pRLIRBuffer,HBA_UINT32 RLIRBufferSize) callback,
  void                                                                                                      *userData,
  void                                                                                                      *pRLIRBuffer,
  HBA_UINT32                                                                                                RLIRBufferSize,
  HBA_HANDLE                                                                                                Handle,
  HBA_CALLBACKHANDLE                                                                                        *pCallbackHandle
);