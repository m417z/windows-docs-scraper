# _DXGKMDT_OPM_HDCP_FLAG enumeration

## Description

The DXGKMDT_OPM_HDCP_FLAG enumeration identifies whether a protected output's physical connector is connected to a High-bandwidth Digital Content Protection (HDCP) repeater.

## Constants

### `DXGKMDT_OPM_HDCP_FLAG_NONE`

Indicates that no HDCP flags are set. Therefore, the protected output's physical connector is not connected to an HDCP repeater.

### `DXGKMDT_OPM_HDCP_FLAG_REPEATER`

Indicates that the protected output's physical connector is connected to an HDCP repeater.

## Remarks

The DXGKMDT_OPM_HDCP_FLAG enumeration is used only if a protected output has Certified Output Protection Protocol (COPP) semantics.

An HDCP repeater is a device that allows multiple monitors to display the video signal from a protected output's physical connector. For example, if a user connected an HDCP repeater from a graphics adapter's Digital Video Interface (DVI) connector to a TV monitor and computer monitor, both monitors would display the same picture. For more information about HDCP repeaters, see the [HDCP Specification Revision 1.1](https://go.microsoft.com/fwlink/p/?linkid=38728).

## See also

[DXGKMDT_OPM_CONNECTED_HDCP_DEVICE_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmdt/ns-d3dkmdt-_dxgkmdt_opm_connected_hdcp_device_information)

[DxgkDdiOPMGetCOPPCompatibleInformation](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_opm_get_copp_compatible_information)