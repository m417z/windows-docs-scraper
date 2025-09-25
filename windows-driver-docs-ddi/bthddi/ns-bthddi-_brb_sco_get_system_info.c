struct _BRB_SCO_GET_SYSTEM_INFO {
  BRB_HEADER Hdr;
  ULONG      Features;
  ULONG      MaxChannels;
  ULONG      TransferUnit;
  USHORT     PacketTypes;
  USHORT     DataFormats;
  ULONG      Reserved;
};