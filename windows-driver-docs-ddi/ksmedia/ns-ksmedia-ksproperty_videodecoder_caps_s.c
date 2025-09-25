typedef struct {
  KSPROPERTY Property;
  ULONG      StandardsSupported;
  ULONG      Capabilities;
  ULONG      SettlingTime;
  ULONG      HSyncPerVSync;
} KSPROPERTY_VIDEODECODER_CAPS_S, *PKSPROPERTY_VIDEODECODER_CAPS_S;