# _NDIS_PORT structure

## Description

The NDIS_PORT structure specifies the characteristics of an NDIS port and a pointer to the next
element in a linked list of ports.

## Members

### `Next`

A pointer to the next port in the linked list of ports.

### `NdisReserved`

Reserved for NDIS.

### `MiniportReserved`

Reserved for miniport drivers.

### `ProtocolReserved`

Reserved for protocol drivers.

### `PortCharacteristics`

An
[NDIS_PORT_CHARACTERISTICS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_port_characteristics) structure that specifies the characteristics of the port.

## Remarks

The NDIS_PORT structure is used to create a linked list of ports. Such a linked list is used in port
activation (**NetEventPortActivation**) Plug and Play (PnP) events.

## See also

[NDIS_PORT_CHARACTERISTICS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_port_characteristics)