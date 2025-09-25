# DXGKMDT_OPM_PROTECTION_TYPE enumeration

## Description

The **DXGKMDT_OPM_PROTECTION_TYPE** enumeration indicates the type of protections that a video output supports.

## Constants

### `DXGKMDT_OPM_PROTECTION_TYPE_OTHER`

Indicates a protection type other than those given in the following constants of this enumeration.

### `DXGKMDT_OPM_PROTECTION_TYPE_NONE`

Indicates that the video output does not support any protection type.

### `DXGKMDT_OPM_PROTECTION_TYPE_COPP_COMPATIBLE_HDCP`

Indicates that the protected output supports High-bandwidth Digital Content Protection (HDCP) that is compatible with Certified Output Protection Protocol (COPP). For more information about HDCP, see the [HDCP Specification Revision 1.1](https://www.digital-cp.com/). This protection type can be used only with protected output objects that have COPP semantics. OPM can use this value in a call to the display miniport driver's [**DxgkDdiOPMGetCOPPCompatibleInformation**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_opm_get_copp_compatible_information) function to determine whether a protected output supports COPP-compatible HDCP. OPM can also use this value in a call to the driver's [**DxgkDdiOPMConfigureProtectedOutput**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_opm_configure_protected_output) function to change the COPP-compatible HDCP protection level.

### `DXGKMDT_OPM_PROTECTION_TYPE_ACP`

Indicates that the protected output supports Analog Copy Protection (ACP). ACP protects analog TV signals. Currently, OPM can use ACP to protect signals from composite outputs, S-Video outputs, or component outputs. OPM can use this value in a call to the display miniport driver's [**DxgkDdiOPMGetCOPPCompatibleInformation**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_opm_get_copp_compatible_information) function to determine whether a protected output supports ACP. OPM can also use this value in a call to the driver's [**DxgkDdiOPMConfigureProtectedOutput**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_opm_configure_protected_output) function to change the ACP protection level.

### `DXGKMDT_OPM_PROTECTION_TYPE_CGMSA`

Indicates that the protected output supports [Content Generation Management System Analog (CGMS-A)](https://learn.microsoft.com/windows-hardware/drivers/display/cgms-a-standards). CGMS-A protects analog TV signals. Currently, OPM can use CGMS-A to protect signals from composite outputs, S-Video outputs, or component outputs. OPM can use this value in a call to the display miniport driver's [**DxgkDdiOPMGetCOPPCompatibleInformation**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_opm_get_copp_compatible_information) function to determine whether a protected output supports CGMS-A. OPM can also use this value in a call to the driver's [**DxgkDdiOPMConfigureProtectedOutput**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_opm_configure_protected_output) function to change the CGMS-A protection level.

### `DXGKMDT_OPM_PROTECTION_TYPE_HDCP`

Indicates that the protected output supports HDCP. This protection type can be used only with protected output objects that have OPM semantics. OPM can use this value in a call to the display miniport driver's [**DxgkDdiOPMGetInformation**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_opm_get_information) function to determine whether a protected output supports HDCP. OPM can also use this value in a call to the driver's [**DxgkDdiOPMConfigureProtectedOutput**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_opm_configure_protected_output) function to change the HDCP protection level.

### `DXGKMDT_OPM_PROTECTION_TYPE_DPCP`

Indicates that the protected output supports DisplayPort Copy Protection (DPCP). For more information about DisplayPort, see the [DisplayPort article](https://wikipedia.org/wiki/DisplayPort). This protection type can be used only with protected output objects that have OPM semantics. OPM can use this value in a call to the display miniport driver's [**DxgkDdiOPMGetInformation**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_opm_get_information) function to determine whether a protected output supports DPCP. OPM can also use this value in a call to the driver's [**DxgkDdiOPMConfigureProtectedOutput**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_opm_configure_protected_output) function to change the DPCP protection level.

### `DXGKMDT_OPM_PROTECTION_TYPE_TYPE_ENFORCEMENT_HDCP`

Indicates that the protected output supports HDCP with Type enforcement.

### `DXGKMDT_OPM_PROTECTION_TYPE_MASK`

A mask value that indicates the valid bit fields in a bitwise OR combination of the values from this enumeration.

## Remarks

DXGKMDT_OPM_PROTECTION_TYPE_HDCP and DXGKMDT_OPM_PROTECTION_TYPE_COPP_COMPATIBLE_HDCP are used to turn HDCP on or off and to determine if HDCP is on or off.

If a protected output supports DXGKMDT_OPM_PROTECTION_TYPE_COPP_COMPATIBLE_HDCP, it supports HDCP repeaters, and an application handles HDCP revocation. If a protected output supports DXGKMDT_OPM_PROTECTION_TYPE_HDCP, it supports HDCP repeaters and handles HDCP revocation.

## See also

[**DXGKMDT_OPM_SET_PROTECTION_LEVEL_PARAMETERS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmdt/ns-d3dkmdt-_dxgkmdt_opm_set_protection_level_parameters)

[**DXGKMDT_OPM_STANDARD_INFORMATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmdt/ns-d3dkmdt-_dxgkmdt_opm_standard_information)

[**DxgkDdiOPMConfigureProtectedOutput**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_opm_configure_protected_output)

[**DxgkDdiOPMGetCOPPCompatibleInformation**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_opm_get_copp_compatible_information)

[**DxgkDdiOPMGetInformation**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_opm_get_information)