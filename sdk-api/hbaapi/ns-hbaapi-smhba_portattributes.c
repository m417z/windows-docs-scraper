typedef struct SMHBA_PortAttributes {
  HBA_PORTTYPE  PortType;
  HBA_PORTSTATE PortState;
  char          OSDeviceName[256];
  SMHBA_PORT    PortSpecificAttribute;
} SMHBA_PORTATTRIBUTES, *PSMHBA_PORTATTRIBUTES;