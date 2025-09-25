typedef struct _DXGK_DIAGNOSTIC_TYPES {
  union {
    DXGK_DIAGTYPE_NOTIFICATIONS Notifications;
    DXGK_DIAGTYPE_PROGRESSIONS  Progressions;
    UINT                        Value;
  };
} DXGK_DIAGNOSTIC_TYPES;