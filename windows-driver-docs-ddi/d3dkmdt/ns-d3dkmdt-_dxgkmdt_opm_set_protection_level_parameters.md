# _DXGKMDT_OPM_SET_PROTECTION_LEVEL_PARAMETERS structure

## Description

The DXGKMDT_OPM_SET_PROTECTION_LEVEL_PARAMETERS structure contains parameters to set the protection level of a protected output in a call to the [DxgkDdiOPMConfigureProtectedOutput](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_opm_configure_protected_output) function.

## Members

### `ulProtectionType`

A [DXGKMDT_OPM_PROTECTION_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmdt/ne-d3dkmdt-_dxgkmdt_opm_protection_type)-typed value that indicates the protection type to set a protection level for.

### `ulProtectionLevel`

A value that specifies the protection level to set for one of the following protection types that is specified in the **ulProtectionType** member:

#### DXGKMDT_OPM_PROTECTION_TYPE_ACP

A [DXGKMDT_OPM_ACP_PROTECTION_LEVEL](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmdt/ne-d3dkmdt-_dxgkmdt_opm_acp_protection_level)-typed value that identifies the Analog Copy Protection (ACP) level that the protected output uses.

#### DXGKMDT_OPM_PROTECTION_TYPE_CGMSA

A [DXGKMDT_OPM_CGMSA](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmdt/ne-d3dkmdt-_dxgkmdt_opm_cgmsa)-typed value that identifies the Content Generation Management System Analog (CGMS-A) protection level that the protected output uses.

#### DXGKMDT_OPM_PROTECTION_TYPE_HDCP or DXGKMDT_OPM_PROTECTION_TYPE_COPP_COMPATIBLE_HDCP

A [DXGKMDT_OPM_HDCP_PROTECTION_LEVEL](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmdt/ne-d3dkmdt-_dxgkmdt_opm_hdcp_protection_level)-typed value that identifies the High-bandwidth Digital Content Protection (HDCP) level that the protected output uses. Protected outputs with COPP semantics can use only DXGKMDT_OPM_PROTECTION_TYPE_COPP_COMPATIBLE_HDCP; protected outputs with OPM semantics can use only DXGKMDT_OPM_PROTECTION_TYPE_HDCP.

#### DXGKMDT_OPM_PROTECTION_TYPE_DPCP

A [DXGKMDT_OPM_DPCP_PROTECTION_LEVEL](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmdt/ne-d3dkmdt-_dxgkmdt_dpcp_protection_level)-typed value that identifies the DisplayPort Copy Protection (DPCP) protection level that the protected output uses.

### `Reserved`

Reserved. Must be set to zero.

### `Reserved2`

Reserved. Must be set to zero.

## See also

[DXGKMDT_OPM_ACP_PROTECTION_LEVEL](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmdt/ne-d3dkmdt-_dxgkmdt_opm_acp_protection_level)

[DXGKMDT_OPM_CGMSA](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmdt/ne-d3dkmdt-_dxgkmdt_opm_cgmsa)

[DXGKMDT_OPM_DPCP_PROTECTION_LEVEL](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmdt/ne-d3dkmdt-_dxgkmdt_dpcp_protection_level)

[DXGKMDT_OPM_HDCP_PROTECTION_LEVEL](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmdt/ne-d3dkmdt-_dxgkmdt_opm_hdcp_protection_level)

[DXGKMDT_OPM_PROTECTION_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmdt/ne-d3dkmdt-_dxgkmdt_opm_protection_type)

[DxgkDdiOPMConfigureProtectedOutput](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_opm_configure_protected_output)