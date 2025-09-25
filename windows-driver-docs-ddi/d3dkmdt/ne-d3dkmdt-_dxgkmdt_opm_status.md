# _DXGKMDT_OPM_STATUS enumeration

## Description

The DXGKMDT_OPM_STATUS enumeration identifies the status of a protected output.

## Constants

### `DXGKMDT_OPM_STATUS_NORMAL`

Indicates that the protected output is working correctly.

### `DXGKMDT_OPM_STATUS_LINK_LOST`

Indicates that although the protected output detected no tampering, an output protection technology unexpectedly stopped working.

This status bit must be set if DXGKMDT_OPM_STATUS_REVOKED_HDCP_DEVICE_ATTACHED is also set.

### `DXGKMDT_OPM_STATUS_RENEGOTIATION_REQUIRED`

Indicates that the end user caused the configuration of the physical connector to change. Therefore, a renegotiation is required.

### `DXGKMDT_OPM_STATUS_TAMPERING_DETECTED`

Indicates that tampering with the graphics adapter or the adapter's display miniport driver has occurred.

### `DXGKMDT_OPM_STATUS_REVOKED_HDCP_DEVICE_ATTACHED`

Indicates that a revoked High-bandwidth Digital Content Protection (HDCP) device is directly or indirectly attached to a protected output. If HDCP is not enabled, the protected output is not required to detect revoked devices. If HDCP is enabled, the protected output must detect revoked devices. The driver sets this status value only from a call to its [DxgkDdiOPMGetInformation](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_opm_get_information) function to determine if HDCP is enabled.

## Remarks

The display miniport driver returns status about a protected output whenever the driver's [DxgkDdiOPMGetInformation](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_opm_get_information) and [DxgkDdiOPMGetCOPPCompatibleInformation](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_opm_get_copp_compatible_information) functions are called to retrieve information about the protected output. For more information about returning a protected output's status, see [Reporting Status about a Protected Output](https://learn.microsoft.com/windows-hardware/drivers/display/reporting-status-of-a-protected-output).

## See also

[DXGKMDT_OPM_ACP_AND_CGMSA_SIGNALING](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmdt/ns-d3dkmdt-_dxgkmdt_opm_acp_and_cgmsa_signaling)

[DXGKMDT_OPM_ACTUAL_OUTPUT_FORMAT](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmdt/ns-d3dkmdt-_dxgkmdt_opm_actual_output_format)

[DXGKMDT_OPM_CONNECTED_HDCP_DEVICE_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmdt/ns-d3dkmdt-_dxgkmdt_opm_connected_hdcp_device_information)

[DXGKMDT_OPM_STANDARD_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmdt/ns-d3dkmdt-_dxgkmdt_opm_standard_information)

[DxgkDdiOPMGetCOPPCompatibleInformation](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_opm_get_copp_compatible_information)

[DxgkDdiOPMGetInformation](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_opm_get_information)