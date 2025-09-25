# _DXGKMDT_DPCP_PROTECTION_LEVEL enumeration

## Description

The DXGKMDT_OPM_DPCP_PROTECTION_LEVEL enumeration indicates the protection levels for a protected output that supports DisplayPort Content Protection (DPCP).

## Constants

### `DXGKMDT_OPM_DPCP_OFF`

Indicates that DPCP does not protect the output's signal.

### `DXGKMDT_OPM_DPCP_ON`

Indicates that DPCP protects the output's signal.

### `DXGKMDT_OPM_DPCP_FORCE_ULONG`

Forces this enumeration to compile to 32 bits in size. Without this value, some compilers would allow this enumeration to compile to a size other than 32 bits. You should not use this value.

## Remarks

DPCP protects digital video signals from DisplayPort output connectors. For more information about DisplayPort, see the [DisplayPort article](https://go.microsoft.com/fwlink/p/?linkid=71382).

## See also

[DXGKMDT_OPM_SET_PROTECTION_LEVEL_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmdt/ns-d3dkmdt-_dxgkmdt_opm_set_protection_level_parameters)

[DXGKMDT_OPM_STANDARD_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmdt/ns-d3dkmdt-_dxgkmdt_opm_standard_information)

[DxgkDdiOPMConfigureProtectedOutput](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_opm_configure_protected_output)

[DxgkDdiOPMGetCOPPCompatibleInformation](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_opm_get_copp_compatible_information)

[DxgkDdiOPMGetInformation](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_opm_get_information)