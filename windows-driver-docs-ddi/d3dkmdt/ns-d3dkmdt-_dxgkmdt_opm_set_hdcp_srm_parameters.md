# _DXGKMDT_OPM_SET_HDCP_SRM_PARAMETERS structure

## Description

The DXGKMDT_OPM_SET_HDCP_SRM_PARAMETERS structure contains parameters to set the version of a High-bandwidth Digital Content Protection (HDCP) System Renewability Message (SRM) for a protected output.

## Members

### `ulSRMVersion`

The version number of an HDCP SRM. The least significant bits (bits 0 through 15) contain the SRM's version number in little-endian format. The SRM's version number is stored in the SRM's SRM version field in little-endian format. For more information about the SRM's SRM version field, see the [HDCP Specification Revision 1.1](https://go.microsoft.com/fwlink/p/?linkid=38728).

## See also

[DXGKMDT_OPM_CONFIGURE_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmdt/ns-d3dkmdt-_dxgkmdt_opm_configure_parameters)

[DxgkDdiOPMConfigureProtectedOutput](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_opm_configure_protected_output)