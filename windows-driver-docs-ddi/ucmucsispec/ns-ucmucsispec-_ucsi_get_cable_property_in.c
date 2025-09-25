typedef struct _UCSI_GET_CABLE_PROPERTY_IN {
  union {
    UINT16 AsUInt16;
    struct {
      UINT16 SpeedExponent : 2;
      UINT16 Mantissa : 14;
    };
  } bmSpeedSupported;
  UINT8  bCurrentCapability;
  UINT16 VBusInCable : 1;
  UINT16 CableType : 1;
  UINT16 Directionality : 1;
  UINT16 PlugEndType : 2;
  UINT16 ModeSupport : 1;
  UINT16 Latency : 4;
} UCSI_GET_CABLE_PROPERTY_IN, *PUCSI_GET_CABLE_PROPERTY_IN;