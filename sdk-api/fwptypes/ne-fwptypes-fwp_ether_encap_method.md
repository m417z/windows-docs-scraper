# FWP_ETHER_ENCAP_METHOD enumeration

## Description

The **FWP_ETHER_ENCAP_METHOD** enumerated type specifies the method of encapsulating Ethernet II and SNAP traffic. Reserved.

## Constants

### `FWP_ETHER_ENCAP_METHOD_ETHER_V2:0`

Specifies Ethernet V2 encapsulation.

### `FWP_ETHER_ENCAP_METHOD_SNAP:1`

Specifies Subnet Access Protocol (SNAP) encapsulation with an unknown Organizationally Unique Identifier (OUI) and Service Access Point (SAP) prefix.

### `FWP_ETHER_ENCAP_METHOD_SNAP_W_OUI_ZERO:3`

Specifies SNAP encapsulation with a recognized OUI and a SAP prefix of 03.AA.AA.00.00.00 + Ethertype.

## Remarks

This enumeration is reserved.