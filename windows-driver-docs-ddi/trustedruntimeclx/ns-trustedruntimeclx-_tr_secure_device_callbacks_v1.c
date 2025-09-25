typedef struct _TR_SECURE_DEVICE_CALLBACKS_V1 {
  ULONG                                      Flags;
  PFN_TR_CREATE_SECURE_DEVICE_CONTEXT        EvtTrCreateSecureDeviceContext;
  PFN_TR_DESTROY_SECURE_DEVICE_CONTEXT       EvtTrDestroySecureDeviceContext;
  PFN_TR_PREPARE_HARDWARE_SECURE_ENVIRONMENT EvtTrPrepareHardwareSecureEnvironment;
  PFN_TR_RELEASE_HARDWARE_SECURE_ENVIRONMENT EvtTrReleaseHardwareSecureEnvironment;
  PFN_TR_CONNECT_SECURE_ENVIRONMENT          EvtTrConnectSecureEnvironment;
  PFN_TR_DISCONNECT_SECURE_ENVIRONMENT       EvtTrDisconnectSecureEnvironment;
  PFN_TR_ENUMERATE_SECURE_SERVICES           EvtTrEnumerateSecureServices;
  PFN_TR_PROCESS_OTHER_DEVICE_IO             EvtTrProcessOtherDeviceIo;
  PFN_TR_QUERY_SERVICE_CALLBACKS             EvtTrQueryServiceCallbacks;
} TR_SECURE_DEVICE_CALLBACKS_V1, *PTR_SECURE_DEVICE_CALLBACKS_V1;