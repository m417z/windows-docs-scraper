typedef struct _D3DDDICB_DESTROYALLOCATION2FLAGS {
  union {
    struct {
      UINT AssumeNotInUse : 1;
      UINT SynchronousDestroy : 1;
      UINT Reserved : 29;
      UINT SystemUseOnly : 1;
    };
    UINT Value;
  };
} D3DDDICB_DESTROYALLOCATION2FLAGS;