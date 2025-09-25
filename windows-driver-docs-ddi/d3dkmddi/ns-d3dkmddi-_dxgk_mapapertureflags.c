typedef struct _DXGK_MAPAPERTUREFLAGS {
  union {
    struct {
      UINT CacheCoherent : 1;
      UINT Reserved : 31;
    };
    [in] UINT Value;
  };
} DXGK_MAPAPERTUREFLAGS;