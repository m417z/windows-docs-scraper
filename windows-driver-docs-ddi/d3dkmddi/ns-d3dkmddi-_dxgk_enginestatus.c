typedef struct _DXGK_ENGINESTATUS {
  union {
    struct {
      UINT Responsive : 1;
      UINT Reserved : 31;
    };
    UINT Value;
  };
} DXGK_ENGINESTATUS;