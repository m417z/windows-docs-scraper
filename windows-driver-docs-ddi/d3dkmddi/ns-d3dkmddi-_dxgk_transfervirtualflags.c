typedef struct _DXGK_TRANSFERVIRTUALFLAGS {
  union {
    struct {
      UINT Src64KBPages : 1;
      UINT Dst64KBPages : 1;
      UINT Reserved : 30;
    };
    UINT Flags;
  };
} DXGK_TRANSFERVIRTUALFLAGS;