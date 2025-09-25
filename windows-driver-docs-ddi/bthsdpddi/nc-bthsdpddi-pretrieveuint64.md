# PRETRIEVEUINT64 callback function

## Description

The Bluetooth
**SdpRetrieveUint64** function is used to copy an unaligned 64-bit integer from an SDP stream.

## Parameters

### `Stream`

Pointer to the source address for the unaligned 64-bit integer.

### `pUint16`

Pointer to the address of an aligned variable to receive the 64-bit integer.

## Remarks

The
**SdpRetrieveUint64** function does not search for the unaligned integer to copy. The
*Stream* parameter must specify the exact address of the unsigned integer to be extracted.

Some processor architectures require that values be aligned in memory and will generate an error if an
attempt is made to access a misaligned value. SDP records are constructed without regard to processor
alignment rules. When SDP records are stored in memory, they might contain elements that are misaligned
according to local processor's alignment rules.

The
**SdpRetrieveUint64** function safely copies unaligned integers on computers that have alignment
requirements and efficiently copies unaligned integers on computers that do not have requirements. In
addition, this function works on integers that are correctly aligned.

This function has no effect on byte order.

Bluetooth profile drivers can obtain a pointer to this function through the
[BTHDDI_SDP_PARSE_INTERFACE](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthsdpddi/ns-bthsdpddi-_bthddi_sdp_parse_interface) structure.

## See also

[BTHDDI_SDP_PARSE_INTERFACE](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthsdpddi/ns-bthsdpddi-_bthddi_sdp_parse_interface)