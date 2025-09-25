typedef struct _DXGK_DIAGNOSTIC_CATEGORIES {
  union {
    struct {
      UINT Notifications : 1;
      UINT Progressions : 1;
#if ...
      UINT Reserved : 30;
#else
      UINT Reserved : 31;
#endif
    };
    UINT Value;
  };
} DXGK_DIAGNOSTIC_CATEGORIES;