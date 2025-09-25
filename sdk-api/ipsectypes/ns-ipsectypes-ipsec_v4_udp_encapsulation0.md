# IPSEC_V4_UDP_ENCAPSULATION0 structure

## Description

The **IPSEC_V4_UDP_ENCAPSULATION0** structure stores the User Datagram Protocol (UDP) encapsulation ports for Encapsulating Security Payload (ESP) encapsulation.

## Members

### `localUdpEncapPort`

Source UDP encapsulation port.

### `remoteUdpEncapPort`

Destination UDP encapsulation port.

## Remarks

This is used only when a NAT was detected as part of the IPsec NAT traversal specification.

**IPSEC_V4_UDP_ENCAPSULATION0** is a specific implementation of IPSEC_V4_UDP_ENCAPSULATION. See [WFP Version-Independent Names and Targeting Specific Versions of Windows](https://learn.microsoft.com/windows/desktop/FWP/wfp-version-independent-names-and-targeting-specific-versions-of-windows) for more information.

## See also

[Windows Filtering Platform API Structures](https://learn.microsoft.com/windows/desktop/FWP/fwp-structs)