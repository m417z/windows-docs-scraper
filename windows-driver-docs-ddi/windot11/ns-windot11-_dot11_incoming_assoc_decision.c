typedef struct _DOT11_INCOMING_ASSOC_DECISION {
  NDIS_OBJECT_HEADER Header;
  DOT11_MAC_ADDRESS  PeerMacAddr;
  BOOLEAN            bAccept;
  USHORT             usReasonCode;
  ULONG              uAssocResponseIEsOffset;
  ULONG              uAssocResponseIEsLength;
} DOT11_INCOMING_ASSOC_DECISION, *PDOT11_INCOMING_ASSOC_DECISION;