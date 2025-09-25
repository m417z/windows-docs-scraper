typedef struct _D3DDDICB_SUBMITCOMMANDFLAGS {
  union {
    struct {
      UINT NullRendering : 1;
      UINT Reserved : 31;
    };
    UINT Value;
  };
} D3DDDICB_SUBMITCOMMANDFLAGS;