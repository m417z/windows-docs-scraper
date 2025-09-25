typedef struct _DXGK_UPDATECURRENTVALUESFROMCPU_FLAGS {
  union {
    struct {
      UINT AlwaysSignaled : 1;
      UINT NotificationOnly : 1;
      UINT Reserved : 30;
    };
    UINT Value;
  };
} DXGK_UPDATECURRENTVALUESFROMCPU_FLAGS;