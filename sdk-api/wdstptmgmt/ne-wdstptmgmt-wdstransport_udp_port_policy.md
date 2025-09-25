# WDSTRANSPORT_UDP_PORT_POLICY enumeration

## Description

Specifies which policy WDS transport services should use when allocating UDP ports.

## Constants

### `WdsTptUdpPortPolicyDynamic:0`

Use Windows Sockets (Winsock) to get a dynamic UDP port.

### `WdsTptUdpPortPolicyFixed:1`

Assign a fixed UDP port from a specified range of UDP ports.

## See also

[IWdsTransportServicePolicy2::UdpPortPolicy Property](https://learn.microsoft.com/windows/desktop/api/wdstptmgmt/nf-wdstptmgmt-iwdstransportservicepolicy2-get_udpportpolicy)