typedef struct _DXGK_NODEMETADATA_FLAGS {
  union {
    struct {
      UINT ContextSchedulingSupported : 1;
      UINT RingBufferFenceRelease : 1;
      UINT SupportTrackedWorkload : 1;
      UINT UserModeSubmission : 1;
      UINT SupportBuildTestCommandBuffer : 1;
#if ...
      UINT Reserved : 11;
#elif
      UINT Reserved : 12;
      UINT MaxInFlightHwQueueBuffers : 16;
#else
      UINT Reserved : 31;
#endif
    };
    UINT32 Value;
  };
} DXGK_NODEMETADATA_FLAGS;