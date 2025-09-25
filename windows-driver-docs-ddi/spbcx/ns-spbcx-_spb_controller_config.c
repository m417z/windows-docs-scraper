typedef struct _SPB_CONTROLLER_CONFIG {
  ULONG                       Size;
  WDF_IO_QUEUE_DISPATCH_TYPE  ControllerDispatchType;
  WDF_TRI_STATE               PowerManaged;
  PFN_SPB_TARGET_CONNECT      EvtSpbTargetConnect;
  PFN_SPB_TARGET_DISCONNECT   EvtSpbTargetDisconnect;
  PFN_SPB_CONTROLLER_LOCK     EvtSpbControllerLock;
  PFN_SPB_CONTROLLER_UNLOCK   EvtSpbControllerUnlock;
  PFN_SPB_CONTROLLER_READ     EvtSpbIoRead;
  PFN_SPB_CONTROLLER_WRITE    EvtSpbIoWrite;
  PFN_SPB_CONTROLLER_SEQUENCE EvtSpbIoSequence;
} SPB_CONTROLLER_CONFIG, *PSPB_CONTROLLER_CONFIG;