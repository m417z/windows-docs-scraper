typedef struct _INTERFACE_HARDWARE_TIMESTAMP_CAPABILITIES {
  BOOLEAN PtpV2OverUdpIPv4EventMessageReceive;
  BOOLEAN PtpV2OverUdpIPv4AllMessageReceive;
  BOOLEAN PtpV2OverUdpIPv4EventMessageTransmit;
  BOOLEAN PtpV2OverUdpIPv4AllMessageTransmit;
  BOOLEAN PtpV2OverUdpIPv6EventMessageReceive;
  BOOLEAN PtpV2OverUdpIPv6AllMessageReceive;
  BOOLEAN PtpV2OverUdpIPv6EventMessageTransmit;
  BOOLEAN PtpV2OverUdpIPv6AllMessageTransmit;
  BOOLEAN AllReceive;
  BOOLEAN AllTransmit;
  BOOLEAN TaggedTransmit;
} INTERFACE_HARDWARE_TIMESTAMP_CAPABILITIES, *PINTERFACE_HARDWARE_TIMESTAMP_CAPABILITIES;