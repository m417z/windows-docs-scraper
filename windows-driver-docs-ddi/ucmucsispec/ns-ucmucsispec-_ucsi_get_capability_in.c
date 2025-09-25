typedef struct _UCSI_GET_CAPABILITY_IN {
  union {
    UINT32 AsUInt32;
    struct {
      UINT32 DisabledStateSupport : 1;
      UINT32 BatteryCharging : 1;
      UINT32 UsbPowerDelivery : 1;
      UINT32 UsbTypeCCurrent : 1;
      UINT32 bmPowerSource : 8;
    };
  } bmAttributes;
  union {
    UINT8 bNumConnectors : 7;
  };
  union {
    struct {
      UINT32 SetUomSupported : 1;
      UINT32 SetPdmSupported : 1;
      UINT32 AlternateModeDetailsAvailable : 1;
      UINT32 AlternateModeOverrideSupported : 1;
      UINT32 PdoDetailsAvailable : 1;
      UINT32 CableDetailsAvailable : 1;
      UINT32 ExternalSupplyNotificationSupported : 1;
      UINT32 PdResetNotificationSupported : 1;
    } bmOptionalFeatures;
    struct {
      UINT32 OptionalFeatures : 24;
      UINT32 bNumAltModes : 8;
    };
  };
  UINT16 bcdBcVersion;
  UINT16 bcdPdVersion;
  UINT16 bcdUsbTypeCVersion;
} UCSI_GET_CAPABILITY_IN, *PUCSI_GET_CAPABILITY_IN;