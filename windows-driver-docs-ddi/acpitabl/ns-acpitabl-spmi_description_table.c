typedef struct _SPMI_DESCRIPTION_TABLE {
  DESCRIPTION_HEADER Header;
  UINT8              InterfaceType;
  UINT8              Reserved1;
  UINT16             SpecificationRevision;
  struct {
    UINT8 GpeSupported : 1;
    UINT8 ApicInterrupt : 1;
    UINT8 Reserved : 6;
  } InterruptType;
  UINT8              Gpe;
  UINT8              Reserved2;
  UINT8              PciDeviceFlag;
  UINT32             GlobalSystemInterrupt;
  GEN_ADDR           BaseAddress;
  UINT8              PciSegmentGroupNumber;
  UINT8              PciBusNumber;
  UINT8              PciDeviceNumber;
  UINT8              PciFunctionNumber;
  UINT8              Reserved3;
} SPMI_DESCRIPTION_TABLE, *PSPMI_DESCRIPTION_TABLE;