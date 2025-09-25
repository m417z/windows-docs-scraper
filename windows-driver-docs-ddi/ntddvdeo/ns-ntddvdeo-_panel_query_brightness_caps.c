typedef struct _PANEL_QUERY_BRIGHTNESS_CAPS {
  BRIGHTNESS_INTERFACE_VERSION Version;
  union {
    struct {
      ULONG Smooth : 1;
      ULONG Adaptive : 1;
      ULONG NitsCalibrated : 1;
      ULONG Reserved : 29;
    };
    ULONG Value;
  };
} PANEL_QUERY_BRIGHTNESS_CAPS, *PPANEL_QUERY_BRIGHTNESS_CAPS;