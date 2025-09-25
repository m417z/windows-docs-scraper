typedef struct {
  ULONG        MethodId;
  union {
    PFNKSHANDLER MethodHandler;
    BOOLEAN      MethodSupported;
  };
  ULONG        MinMethod;
  ULONG        MinData;
  PFNKSHANDLER SupportHandler;
  ULONG        Flags;
} KSMETHOD_ITEM, *PKSMETHOD_ITEM;