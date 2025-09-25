typedef struct _PANEL_SET_BRIGHTNESS {
  BRIGHTNESS_INTERFACE_VERSION Version;
  union {
    UCHAR Level;
    struct {
      ULONG                        Millinits;
      ULONG                        TransitionTimeInMs;
      PANEL_BRIGHTNESS_SENSOR_DATA SensorData;
    };
  };
} PANEL_SET_BRIGHTNESS, *PPANEL_SET_BRIGHTNESS;