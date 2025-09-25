typedef struct _TR_SECURE_SERVICE_CALLBACKS_V1 {
  ULONG                                         Flags;
  PFN_TR_CREATE_SECURE_SERVICE_CONTEXT          EvtTrCreateSecureServiceContext;
  PFN_TR_DESTROY_SECURE_SERVICE_CONTEXT         EvtTrDestroySecureServiceContext;
  PFN_TR_CONNECT_SECURE_SERVICE                 EvtTrConnectSecureService;
  PFN_TR_DISCONNECT_SECURE_SERVICE              EvtTrDisconnectSecureService;
  PFN_TR_CREATE_SECURE_SERVICE_SESSION_CONTEXT  EvtTrCreateSecureSessionContext;
  PFN_TR_DESTROY_SECURE_SERVICE_SESSION_CONTEXT EvtTrDestroySecureSessionContext;
  PFN_TR_PROCESS_SECURE_SERVICE_REQUEST         EvtTrProcessSecureServiceRequest;
  PFN_TR_CANCEL_SECURE_SERVICE_REQUEST          EvtTrCancelSecureServiceRequest;
  PFN_TR_PROCESS_OTHER_SECURE_SERVICE_IO        EvtTrProcessOtherSecureServiceIo;
} TR_SECURE_SERVICE_CALLBACKS_V1, *PTR_SECURE_SERVICE_CALLBACKS_V1;