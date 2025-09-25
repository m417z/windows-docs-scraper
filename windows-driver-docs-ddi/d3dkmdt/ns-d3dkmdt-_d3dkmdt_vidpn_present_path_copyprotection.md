# _D3DKMDT_VIDPN_PRESENT_PATH_COPYPROTECTION structure

## Description

The D3DKMDT_VIDPN_PRESENT_PATH_COPYPROTECTION structure contains information about the copy protection that is supported (as well as the copy protection that is currently active) on a particular VidPN present path.

## Members

### `CopyProtectionType`

A value from the [D3DKMDT_VIDPN_PRESENT_PATH_COPYPROTECTION_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmdt/ne-d3dkmdt-_d3dkmdt_vidpn_present_path_copyprotection_type) enumeration that indicates the type of copy protection that is active on the path.

### `APSTriggerBits`

A value that describes copy protection for an OEM device. A value of 0 indicates no copy protection, and values of 1, 2, and 3 indicate low, medium, and high levels of copy protection, respectively. Values greater than 3 are not allowed.

### `OEMCopyProtection`

Reserved for future use.

### `CopyProtectionSupport`

A [D3DKMDT_VIDPN_PRESENT_PATH_COPYPROTECTION_SUPPORT](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmdt/ns-d3dkmdt-_d3dkmdt_vidpn_present_path_copyprotection_support) structure that indicates the types of copy protection that are supported by the path.

## Remarks

The **CopyProtection** member of the [D3DKMDT_VIDPN_PRESENT_PATH](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmdt/ns-d3dkmdt-_d3dkmdt_vidpn_present_path) structure is a D3DKMDT_VIDPN_PRESENT_PATH_COPYPROTECTION structure.