typedef struct _DXGK_CONTEXTINFO_CAPS {
  union {
    struct {
      UINT NoPatchingRequired : 1;
      UINT DriverManagesResidency : 1;
      UINT UseIoMmu : 1;
      UINT Reserved : 29;
    };
    UINT Value;
  };
} DXGK_CONTEXTINFO_CAPS;