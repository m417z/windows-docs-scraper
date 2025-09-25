typedef struct _PANEL_GET_BRIGHTNESS {
  BRIGHTNESS_INTERFACE_VERSION Version;
  union {
    UCHAR Level;
    struct {
      ULONG CurrentInMillinits;
      ULONG TargetInMillinits;
    };
  };
} PANEL_GET_BRIGHTNESS, *PPANEL_GET_BRIGHTNESS;