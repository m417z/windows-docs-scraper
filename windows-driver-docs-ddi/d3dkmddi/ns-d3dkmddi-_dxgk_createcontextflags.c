typedef struct _DXGK_CREATECONTEXTFLAGS {
  union {
    struct {
      UINT SystemContext : 1;
      UINT GdiContext : 1;
      UINT VirtualAddressing : 1;
      UINT SystemProtectedContext : 1;
      UINT HwQueueSupported : 1;
      UINT TestContext : 1;
#if ...
      UINT Reserved : 26;
#elif
      UINT Reserved : 27;
#elif
      UINT Reserved : 28;
#elif
      UINT Reserved : 29;
#else
      UINT Reserved : 30;
#endif
    };
    UINT Value;
  };
} DXGK_CREATECONTEXTFLAGS;