typedef struct D3DDDIARG_COPYFLAGS {
  union {
    struct {
      UINT NoOverwrite : 1;
      UINT Discard : 1;
      UINT Reserved1 : 22;
      UINT BoxValid : 1;
      UINT Reserved2 : 7;
    };
    UINT Value;
  };
} D3DDDIARG_COPYFLAGS;