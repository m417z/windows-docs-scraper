typedef struct {
  KSPIN_INTERFACE Interface;
  KSPIN_MEDIUM    Medium;
  ULONG           PinId;
  HANDLE          PinToHandle;
  KSPRIORITY      Priority;
} KSPIN_CONNECT, *PKSPIN_CONNECT;