typedef struct _MIRACAST_DRIVER_INTERFACE {
  UINT                         Size;
  PFN_CREATE_MIRACAST_CONTEXT  CreateMiracastContext;
  PFN_DESTROY_MIRACAST_CONTEXT DestroyMiracastContext;
  PFN_START_MIRACAST_SESSION   StartMiracastSession;
  PFN_STOP_MIRACAST_SESSION    StopMiracastSession;
  PFN_HANDLE_KMD_MESSAGE       HandleKernelModeMessage;
} MIRACAST_DRIVER_INTERFACE, *PMIRACAST_DRIVER_INTERFACE;