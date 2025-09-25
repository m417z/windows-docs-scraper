typedef struct _DXGK_DIAGTYPE_NOTIFICATIONS {
  union {
    struct {
      UINT PanelSelfRefreshSoftware : 1;
      UINT PanelSelfRefreshHardware : 1;
      UINT Reserved : 30;
    };
    UINT Value;
  };
} DXGK_DIAGTYPE_NOTIFICATIONS;