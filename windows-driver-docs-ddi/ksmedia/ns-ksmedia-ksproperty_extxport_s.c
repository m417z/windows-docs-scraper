typedef struct {
  KSPROPERTY Property;
  union {
    ULONG           Capabilities;
    ULONG           SignalMode;
    ULONG           LoadMedium;
    MEDIUM_INFO     MediumInfo;
    TRANSPORT_STATE XPrtState;
    struct {
      BYTE frame;
      BYTE second;
      BYTE minute;
      BYTE hour;
    } Timecode;
    DWORD           dwTimecode;
    DWORD           dwAbsTrackNumber;
    struct {
      ULONG PayloadSize;
      BYTE  Payload[512];
    } RawAVC;
  } u;
} KSPROPERTY_EXTXPORT_S, *PKSPROPERTY_EXTXPORT_S;