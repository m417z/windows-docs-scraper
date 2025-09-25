# EapPacket structure

## Description

 The **EapPacket** structure contains a packet of opaque data sent during an EAP authentication session.

## Members

### `Code`

An [EapCode](https://learn.microsoft.com/windows/desktop/api/eapmethodtypes/ne-eapmethodtypes-eapcode) enumeration value that identifies the packet type.

### `Id`

The packet ID number.

### `Length`

The length of the entire packet

### `Data`

The packet message data. This opaque data block continues after the first byte for **Length** - 1 bytes.

## See also

[Common EAPHost API Structures](https://learn.microsoft.com/windows/win32/eaphost/common-eap-host-api-structures)

[EapCode](https://learn.microsoft.com/windows/desktop/api/eapmethodtypes/ne-eapmethodtypes-eapcode)