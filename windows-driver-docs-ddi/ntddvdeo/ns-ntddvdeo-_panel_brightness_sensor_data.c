typedef struct _PANEL_BRIGHTNESS_SENSOR_DATA {
  union {
    struct {
      ULONG AlsReadingValid : 1;
      ULONG ChromaticityCoordinateValid : 1;
      ULONG ColorTemperatureValid : 1;
      ULONG Reserved : 29;
    };
    ULONG Value;
  };
  float                   AlsReading;
  CHROMATICITY_COORDINATE ChromaticityCoordinate;
  float                   ColorTemperature;
} PANEL_BRIGHTNESS_SENSOR_DATA;