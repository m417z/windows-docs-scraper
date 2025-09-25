typedef enum _NDIS_PM_WAKE_REASON_TYPE {
  NdisWakeReasonUnspecified = 0x0000,
  NdisWakeReasonPacket = 0x0001,
  NdisWakeReasonMediaDisconnect = 0x0002,
  NdisWakeReasonMediaConnect = 0x0003,
  NdisWakeReasonWlanNLODiscovery = 0x1000,
  NdisWakeReasonWlanAPAssociationLost = 0x1001,
  NdisWakeReasonWlanGTKHandshakeError = 0x1002,
  NdisWakeReasonWlan4WayHandshakeRequest = 0x1003,
  NdisWakeReasonWlanIncomingActionFrame,
  NdisWakeReasonWlanClientDriverDiagnostic,
  NdisWakeReasonWwanRegisterState = 0x2000,
  NdisWakeReasonWwanSMSReceive = 0x2001,
  NdisWakeReasonWwanUSSDReceive = 0x2002,
  NdisWakeReasonWwanPacketState = 0x2004,
  NdisWakeReasonWwanUiccChange = 0x2005
} NDIS_PM_WAKE_REASON_TYPE, *PNDIS_PM_WAKE_REASON_TYPE;