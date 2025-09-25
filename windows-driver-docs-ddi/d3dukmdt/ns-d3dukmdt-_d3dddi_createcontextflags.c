typedef struct _D3DDDI_CREATECONTEXTFLAGS {
  union {
    struct {
      UINT NullRendering : 1;
      UINT InitialData : 1;
      UINT DisableGpuTimeout : 1;
      UINT SynchronizationOnly : 1;
      UINT HwQueueSupported : 1;
      UINT NoKmdAccess : 1;
      UINT TestContext : 1;
#if ...
      UINT Reserved : 25;
#elif
      UINT Reserved : 28;
#else
      UINT Reserved : 30;
#endif
    };
    UINT Value;
  };
} D3DDDI_CREATECONTEXTFLAGS;