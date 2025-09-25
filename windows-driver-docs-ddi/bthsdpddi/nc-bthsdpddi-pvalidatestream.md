# PVALIDATESTREAM callback function

## Description

The Bluetooth
**SdpValidateStream** function is used to parse a raw SDP record and determine if it contains
errors.

## Parameters

### `Stream`

A pointer to the raw SDP stream to be validated.

### `Size`

An unsigned long integer that indicates the size of the SDP stream to be validated.

### `ErrorByte`

A pointer to a variable that receives the address of the first byte in the SDP record that
contains an error. The address is absolute.

## Return value

Possible return values include:

STATUS_SUCCESS

STATUS_INVALID_PARAMETER

## Remarks

The
**SdpValidateStream** function does nothing on success. On failure, it pinpoints the location of the
first error in the specified SDP record.

Bluetooth profile drivers should use this function to validate all SDP streams from external sources.
Other SDP functions might not perform complete data validation.

Bluetooth profile drivers can obtain a pointer to this function through the
[BTHDDI_SDP_PARSE_INTERFACE](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthsdpddi/ns-bthsdpddi-_bthddi_sdp_parse_interface) structure.

## See also

[BTHDDI_SDP_PARSE_INTERFACE](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthsdpddi/ns-bthsdpddi-_bthddi_sdp_parse_interface)