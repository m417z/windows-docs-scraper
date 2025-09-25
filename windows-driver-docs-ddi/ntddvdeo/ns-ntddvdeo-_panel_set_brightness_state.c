typedef struct _PANEL_SET_BRIGHTNESS_STATE {
  union {
    struct {
      ULONG Smooth : 1;
      ULONG Reserved : 31;
    };
    ULONG Value;
  };
} PANEL_SET_BRIGHTNESS_STATE, *PPANEL_SET_BRIGHTNESS_STATE;