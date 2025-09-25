# PGETNEXTELEMENT callback function

## Description

The Bluetooth
**SdpGetNextElement** function is used to iterate through the entries found in an SDP record
stream.

## Parameters

### `Stream`

Pointer to the SDP record stream to iterate through.

### `StreamSize`

An unsigned long integer that indicates the size of the SDP stream.

### `CurrentElement`

A pointer to the currently selected entry in the SDP stream. This parameter can take a **NULL**
value.

### `NextElement`

A pointer to an unsigned character variable that receives the address of the next entry in the SDP
container stream.

### `NextElementSize`

A pointer to an unsigned long integer variable that receives the size of the next entry in the SDP
container stream.

## Remarks

The
**SdpGetNextElement** function operates directly on unparsed streams and does not require the caller to
convert from a stream representation of the SDP record to a tree-based representation.

The
**SdpGetNextElement** function iterates through the primary entries of a container stream but does not
iterate through any sub-entries of the given entry. To iterate through the sub-entries call
**SdpGetNextElement** iteratively using the
*NextElement* parameter obtained from the previous call.

Calling this function with the
*CurrentElement* parameter set to **NULL** returns the first entry in the container stream.

Bluetooth profile drivers can obtain a pointer to this function through the
[BTHDDI_SDP_PARSE_INTERFACE](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthsdpddi/ns-bthsdpddi-_bthddi_sdp_parse_interface) structure.

## See also

[BTHDDI_SDP_PARSE_INTERFACE](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthsdpddi/ns-bthsdpddi-_bthddi_sdp_parse_interface)