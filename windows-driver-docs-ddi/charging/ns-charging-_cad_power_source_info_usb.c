typedef struct _CAD_POWER_SOURCE_INFO_USB {
  POWERSOURCEID   SourceId;
  USHORT          Version;
  ULONG           Flags;
  ULONG           MaxCurrent;
  ULONG           Voltage;
  LONG            PortType;
  ULONGLONG       PortId;
  USBFN_PORT_TYPE PowerSourceInformation;
  GUID            OemCharger;
} CAD_POWER_SOURCE_INFO_USB, *PCAD_POWER_SOURCE_INFO_USB;