typedef struct _D3DDDICB_SIGNALFLAGS {
  union {
    struct {
      UINT SignalAtSubmission : 1;
      UINT EnqueueCpuEvent : 1;
      UINT AllowFenceRewind : 1;
#if ...
      UINT Reserved : 28;
      UINT DXGK_SIGNAL_FLAG_INTERNAL0 : 1;
#elif
      UINT Reserved : 30;
#else
      UINT Reserved : 31;
#endif
    };
    UINT Value;
  };
} D3DDDICB_SIGNALFLAGS;