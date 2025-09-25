# PBYTESWAPUUID128 callback function

## Description

The Bluetooth **SdpByteSwapUuid128** function is used to reverse the byte order of a 128-bit universally unique identifier (UUID).

## Parameters

### `pUuidFrom`

A pointer to the 128-bit GUID for which to reverse the byte order.

### `pUuiidTo`

A pointer to the converted 128-bit GUID.

## Remarks

The **SdpByteSwapUuid128** function always reverses the byte order of the value pointed to by the *pUuidFrom* parameter. Use this function to convert 128-bit GUID values from the byte order on the local computer to the byte order of the network to which the computer is connected.

Bluetooth profile drivers can obtain a pointer to this function through the [BTHDDI_SDP_PARSE_INTERFACE](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthsdpddi/ns-bthsdpddi-_bthddi_sdp_parse_interface).

## See also

- [BTHDDI_SDP_PARSE_INTERFACE](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthsdpddi/ns-bthsdpddi-_bthddi_sdp_parse_interface)