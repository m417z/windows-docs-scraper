# PRETRIEVEUUID128 callback function

## Description

The Bluetooth
**SdpRetrieveUuid128** function is used to copy an unaligned 128-bit universally unique identifier (UUID)
from an SDP stream.

## Parameters

### `Stream`

A pointer to an unaligned 128-bit UUID.

### `uuid128`

A pointer to an aligned variable to receive the 128-bit UUID.

## Remarks

The
**SdpRetrieveUuid128** function does not search for the UUID to copy. The
*Stream* parameter must specify the exact address of the UUID to be extracted.

Some processor architectures require that values be aligned in memory and will generate an error if an
attempt is made to access a misaligned value. SDP records are constructed without regard to processor
alignment rules. When SDP records are stored in memory, they might contain elements that are misaligned
according to local processor's alignment rules.

The
**SdpRetrieveUuid128** function safely copies UUIDs onto computers that have alignment requirements and
efficiently copies UUIDs onto computers that do not have requirements. In addition, this function works
on UUIDs that are aligned correctly.

This function has no effect on byte order.

Bluetooth profile drivers can obtain a pointer to this function through the
[BTHDDI_SDP_PARSE_INTERFACE](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthsdpddi/ns-bthsdpddi-_bthddi_sdp_parse_interface) structure.

## See also

[BTHDDI_SDP_PARSE_INTERFACE](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthsdpddi/ns-bthsdpddi-_bthddi_sdp_parse_interface)