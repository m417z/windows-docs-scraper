# PBYTESWAPUINT64 callback function

## Description

The Bluetooth
**SdpByteSwapUint64** function is used to reverse the byte order of an unsigned 64-bit integer.

## Parameters

### `uint64`

The unsigned 64-bit integer for which to reverse the byte order.

## Return value

**SdpByteSwapUint64** returns a converted unsigned 64-bit integer.

## Remarks

The
**SdpByteSwapUint64** function always reverses the byte order of the value passed in the
*uint64* parameter. Writers of Bluetooth device drivers can use this function to convert unsigned
64-bit integer values from the byte order on the local computer to the byte order of the network that the
computer is connected to.

Bluetooth profile drivers can obtain a pointer to this function through the
[BTHDDI_SDP_PARSE_INTERFACE](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthsdpddi/ns-bthsdpddi-_bthddi_sdp_parse_interface).

## See also

[BTHDDI_SDP_PARSE_INTERFACE](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthsdpddi/ns-bthsdpddi-_bthddi_sdp_parse_interface)