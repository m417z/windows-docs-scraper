# DXGKMDT_OPM_ACP_PROTECTION_LEVEL enumeration

## Description

The DXGKMDT_OPM_ACP_PROTECTION_LEVEL enumeration indicates the protection levels for a protected output that supports Analog Copy Protection (ACP).

## Constants

### `DXGKMDT_OPM_ACP_OFF`

Indicates that the signal from a video output is not protected by any form of ACP.

### `DXGKMDT_OPM_ACP_LEVEL_ONE`

Indicates that the signal from a video output is protected by the ACP level one protection scheme.

### `DXGKMDT_OPM_ACP_LEVEL_TWO`

Indicates that the signal from a video output is protected by the ACP level two protection scheme.

### `DXGKMDT_OPM_ACP_LEVEL_THREE`

Indicates that the signal from a video output is protected by the ACP level three protection scheme.

### `DXGKMDT_OPM_ACP_FORCE_ULONG`

Forces this enumeration to compile to 32 bits in size. Without this value, some compilers would allow this enumeration to compile to a size other than 32 bits. You should not use this value.

## Remarks

ACP protects analog TV signals. For example, a DVD player can use ACP to prevent a VCR from recording a copy of a DVD movie. Currently, OPM can use ACP to protect signals from composite outputs, S-Video outputs, or component outputs.

Display miniport drivers use the values in DXGKMDT_OPM_ACP_PROTECTION_LEVEL to report the virtual protection level of the protected output or the actual protection level of a physical connector through calls to the driver's [**DxgkDdiOPMGetInformation**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_opm_get_information) and [**DxgkDdiOPMGetCOPPCompatibleInformation**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_opm_get_copp_compatible_information) functions. The values in DXGKMDT_OPM_ACP_PROTECTION_LEVEL are also used to configure the protected output's new virtual protection level in a call to the driver's [**DxgkDdiOPMConfigureProtectedOutput**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_opm_configure_protected_output) function.

## See also

[**DXGKMDT_OPM_SET_PROTECTION_LEVEL_PARAMETERS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmdt/ns-d3dkmdt-_dxgkmdt_opm_set_protection_level_parameters)

[**DXGKMDT_OPM_STANDARD_INFORMATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmdt/ns-d3dkmdt-_dxgkmdt_opm_standard_information)

[**DxgkDdiOPMConfigureProtectedOutput**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_opm_configure_protected_output)

[**DxgkDdiOPMGetCOPPCompatibleInformation**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_opm_get_copp_compatible_information)

[**DxgkDdiOPMGetInformation**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_opm_get_information)