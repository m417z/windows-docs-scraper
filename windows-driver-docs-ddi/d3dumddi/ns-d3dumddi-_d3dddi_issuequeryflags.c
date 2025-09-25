typedef struct _D3DDDI_ISSUEQUERYFLAGS {
  union {
    struct {
      UINT Begin : 1;
      UINT End : 1;
      UINT Reserved : 30;
    };
    UINT Value;
  };
} D3DDDI_ISSUEQUERYFLAGS;