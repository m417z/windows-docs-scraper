# DXGKMDT_OPM_CGMSA enumeration

## Description

The **DXGKMDT_OPM_CGMSA** enumeration indicates the protection levels for a protected output that supports [Content Generation Management System Analog (CGMS-A)](https://learn.microsoft.com/windows-hardware/drivers/display/cgms-a-standards).

## Constants

### `DXGKMDT_OPM_CGMSA_OFF`

Indicates that a video output's signal is not protected with the CGMS-A output protection scheme.

### `DXGKMDT_OPM_CGMSA_COPY_FREELY`

Indicates that the signal from a physical video output can be copied an infinite number of times.

### `DXGKMDT_OPM_CGMSA_COPY_NO_MORE`

Indicates that the signal from a physical video output cannot be copied because the signal was already copied once.

### `DXGKMDT_OPM_CGMSA_COPY_ONE_GENERATION`

Indicates that the signal from a physical video output can be copied once. However, the copy can never be copied.

### `DXGKMDT_OPM_CGMSA_COPY_NEVER`

Indicates that the signal from a physical video output can never be copied.

### `DXGKMDT_OPM_REDISTRIBUTION_CONTROL_REQUIRED`

Indicates that the technological control of consumer redistribution is enabled.

The five preceding protection levels can be bitwise OR combined with the DXGKMDT_OPM_REDISTRIBUTION_CONTROL_REQUIRED to turn on redistribution control.

DXGKMDT_OPM_REDISTRIBUTION_CONTROL_REQUIRED corresponds to the CEA-805-A standard's Redistribution Control Information (RCI) bit. For more information about the RCI bit, see the definition of the RCI bit in section 4.4.3.8 in the CEA-805-A standard.

DXGKMDT_OPM_REDISTRIBUTION_CONTROL_REQUIRED can be used only if a protected output has COPP semantics. A protected output must enable redistribution control if the DirectX graphics kernel subsystem passes DXGKMDT_OPM_REDISTRIBUTION_CONTROL_REQUIRED to the [**DxgkDdiOPMConfigureProtectedOutput**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_opm_configure_protected_output) function. **DxgkDdiOPMConfigureProtectedOutput** must fail if DXGKMDT_OPM_REDISTRIBUTION_CONTROL_REQUIRED is passed to it and the display miniport driver cannot enable redistribution control for any reason.

## Remarks

CGMS-A protects analog TV signals. Currently, OPM can use CGMS-A to protect signals from composite outputs, S-Video outputs, or component outputs.

## See also

[**DXGKMDT_OPM_SET_PROTECTION_LEVEL_PARAMETERS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmdt/ns-d3dkmdt-_dxgkmdt_opm_set_protection_level_parameters)

[**DXGKMDT_OPM_STANDARD_INFORMATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmdt/ns-d3dkmdt-_dxgkmdt_opm_standard_information)

[**DxgkDdiOPMConfigureProtectedOutput**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_opm_configure_protected_output)

[**DxgkDdiOPMGetCOPPCompatibleInformation**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_opm_get_copp_compatible_information)

[**DxgkDdiOPMGetInformation**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_opm_get_information)