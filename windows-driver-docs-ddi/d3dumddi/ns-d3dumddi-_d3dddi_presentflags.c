typedef struct _D3DDDI_PRESENTFLAGS {
  union {
    struct {
      UINT Blt : 1;
      UINT ColorFill : 1;
      UINT Flip : 1;
      UINT AllowTearing : 1;
      UINT AllowFlexibleRefresh : 1;
      UINT Reserved : 27;
    };
    UINT Value;
  };
} D3DDDI_PRESENTFLAGS;