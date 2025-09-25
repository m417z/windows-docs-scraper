# _DXGKMDT_OPM_HDCP_PROTECTION_LEVEL enumeration

## Description

The DXGKMDT_OPM_HDCP_PROTECTION_LEVEL enumeration indicates the protection levels for a protected output that supports High-bandwidth Digital Content Protection (HDCP).

## Constants

### `DXGKMDT_OPM_HDCP_OFF`

Indicates that HDCP does not protect the output's signal.

### `DXGKMDT_OPM_HDCP_ON`

Indicates that HDCP protects the output's signal.

### `DXGKMDT_OPM_HDCP_FORCE_ULONG`

Forces this enumeration to compile to 32 bits in size. Without this value, some compilers would allow this enumeration to compile to a size other than 32 bits. You should not use this value.

## Remarks

HDCP protects digital video signals from digital video output connectors. Currently, OPM can use HDCP to protect data from Digital Video Interface (DVI) and High-Definition Multimedia Interface (HDMI) connector outputs. For more information about the HDCP system, see the [HDCP Specification Revision 1.1](https://go.microsoft.com/fwlink/p/?linkid=38728).

## See also

[DXGKMDT_OPM_SET_PROTECTION_LEVEL_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmdt/ns-d3dkmdt-_dxgkmdt_opm_set_protection_level_parameters)

[DXGKMDT_OPM_STANDARD_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmdt/ns-d3dkmdt-_dxgkmdt_opm_standard_information)

[DxgkDdiOPMConfigureProtectedOutput](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_opm_configure_protected_output)

[DxgkDdiOPMGetCOPPCompatibleInformation](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_opm_get_copp_compatible_information)

[DxgkDdiOPMGetInformation](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_opm_get_information)