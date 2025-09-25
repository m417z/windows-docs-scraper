typedef struct _DOT11_INCOMING_ASSOC_DECISION_V2 {
  NDIS_OBJECT_HEADER       Header;
  DOT11_MAC_ADDRESS        PeerMacAddr;
  BOOLEAN                  bAccept;
  USHORT                   usReasonCode;
  ULONG                    uAssocResponseIEsOffset;
  ULONG                    uAssocResponseIEsLength;
  DOT11_WFD_STATUS_CODE    WFDStatus;
} DOT11_INCOMING_ASSOC_DECISION_V2, *PDOT11_INCOMING_ASSOC_DECISION_V2;