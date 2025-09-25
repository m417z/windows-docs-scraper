typedef struct _PNP_SERIAL_BUS_DESCRIPTOR {
  UCHAR  Tag;
  USHORT Length;
  UCHAR  RevisionId;
  UCHAR  ResourceSourceIndex;
  UCHAR  SerialBusType;
  UCHAR  GeneralFlags;
  USHORT TypeSpecificFlags;
  UCHAR  TypeSpecificRevisionId;
  USHORT TypeDataLength;
} PNP_SERIAL_BUS_DESCRIPTOR, *PPNP_SERIAL_BUS_DESCRIPTOR;