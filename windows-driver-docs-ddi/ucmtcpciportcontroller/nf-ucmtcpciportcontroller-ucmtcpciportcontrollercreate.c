NTSTATUS UcmTcpciPortControllerCreate(
  WDFDEVICE                        WdfDevice,
  PUCMTCPCI_PORT_CONTROLLER_CONFIG Config,
  PWDF_OBJECT_ATTRIBUTES           Attributes,
  UCMTCPCIPORTCONTROLLER           *PortControllerObject
);