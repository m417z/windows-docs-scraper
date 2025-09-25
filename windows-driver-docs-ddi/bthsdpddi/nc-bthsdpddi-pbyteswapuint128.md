# PBYTESWAPUINT128 callback function

## Description

The Bluetooth
**SdpByteSwapUint128** function is used to reverse the byte order of an unsigned 128-bit integer.

## Parameters

### `pInUint128`

A pointer to an unsigned 128-bit integer for which to reverse the byte order.

### `pOutUint128`

A pointer to a variable that receives the converted 128-bit integer.

## Remarks

The
**SdpByteSwapUint128** function always reverses the byte order of the value passed in the
*pInUint128* parameter. Writers of Bluetooth device drivers can use this function to convert unsigned
128-bit integer values from the byte order on the local computer to the byte order of the network that
the computer is connected to.

Bluetooth profile drivers can obtain a pointer to this function through the
[BTHDDI_SDP_PARSE_INTERFACE](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthsdpddi/ns-bthsdpddi-_bthddi_sdp_parse_interface).

## See also

[BTHDDI_SDP_PARSE_INTERFACE](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthsdpddi/ns-bthsdpddi-_bthddi_sdp_parse_interface)