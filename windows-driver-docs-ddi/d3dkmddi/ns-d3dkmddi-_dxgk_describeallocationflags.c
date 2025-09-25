typedef struct _DXGK_DESCRIBEALLOCATIONFLAGS {
  union {
    struct {
      UINT CheckDisplayMode : 1;
      UINT Reserved : 31;
    };
    [in] UINT Value;
  };
} DXGK_DESCRIBEALLOCATIONFLAGS;