# _DXGKMDT_OPM_HDCP_KEY_SELECTION_VECTOR structure

## Description

The DXGKMDT_OPM_HDCP_KEY_SELECTION_VECTOR structure contains a key-selection vector (KSV) for a High-bandwidth Digital Content Protection (HDCP) protected output.

## Members

### `abKeySelectionVector`

A 5-byte array that comprises the HDCP KSV. Byte 0 is the least significant byte and byte 4 is the most significant byte.

## Remarks

For more information about the HDCP KSV, see the [HDCP Specification Revision 1.1](https://go.microsoft.com/fwlink/p/?linkid=38728).

## See also

[DXGKMDT_OPM_CONNECTED_HDCP_DEVICE_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmdt/ns-d3dkmdt-_dxgkmdt_opm_connected_hdcp_device_information)