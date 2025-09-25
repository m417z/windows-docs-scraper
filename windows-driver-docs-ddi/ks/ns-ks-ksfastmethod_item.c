typedef struct {
  ULONG MethodId;
  union {
    PFNKSFASTHANDLER MethodHandler;
    BOOLEAN          MethodSupported;
  };
} KSFASTMETHOD_ITEM, *PKSFASTMETHOD_ITEM;