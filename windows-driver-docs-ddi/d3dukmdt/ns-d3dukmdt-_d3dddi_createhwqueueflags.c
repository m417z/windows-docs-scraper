typedef struct _D3DDDI_CREATEHWQUEUEFLAGS {
  union {
    struct {
      UINT DisableGpuTimeout : 1;
      UINT NoBroadcastSignal : 1;
      UINT NoBroadcastWait : 1;
      UINT NoKmdAccess : 1;
      UINT UserModeSubmission : 1;
      UINT NativeProgressFence : 1;
      UINT TestQueue : 1;
      UINT Reserved : 25;
    };
    UINT Value;
  };
} D3DDDI_CREATEHWQUEUEFLAGS;