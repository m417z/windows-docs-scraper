typedef struct _INTERFACE_TIMESTAMP_CAPABILITY_FLAGS {
  BOOLEAN PtpV2OverUdpIPv4EventMsgReceiveHw;
  BOOLEAN PtpV2OverUdpIPv4AllMsgReceiveHw;
  BOOLEAN PtpV2OverUdpIPv4EventMsgTransmitHw;
  BOOLEAN PtpV2OverUdpIPv4AllMsgTransmitHw;
  BOOLEAN PtpV2OverUdpIPv6EventMsgReceiveHw;
  BOOLEAN PtpV2OverUdpIPv6AllMsgReceiveHw;
  BOOLEAN PtpV2OverUdpIPv6EventMsgTransmitHw;
  BOOLEAN PtpV2OverUdpIPv6AllMsgTransmitHw;
  BOOLEAN AllReceiveHw;
  BOOLEAN AllTransmitHw;
  BOOLEAN TaggedTransmitHw;
  BOOLEAN AllReceiveSw;
  BOOLEAN AllTransmitSw;
  BOOLEAN TaggedTransmitSw;
} INTERFACE_TIMESTAMP_CAPABILITY_FLAGS, *PINTERFACE_TIMESTAMP_CAPABILITY_FLAGS;