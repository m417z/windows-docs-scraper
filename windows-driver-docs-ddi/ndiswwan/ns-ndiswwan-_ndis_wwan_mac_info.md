# _NDIS_WWAN_MAC_INFO structure

## Description

The NDIS_WWAN_MAC_INFO structure represents NDIS port information for a PDP context.

## Members

### `uReserved`

Reserved. Do not use.

### `uNdisPortNumber`

The number of the NDIS port. This value is an NDIS_PORT_NUMBER value, which has a ULONG data type and is valid from zero through 0xffffff, where zero is reserved for the default port.

### `MacAddr`

The NDIS port of the PDP context.