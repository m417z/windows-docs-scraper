# _D3DKMDT_VIDPN_PRESENT_PATH_COPYPROTECTION_TYPE enumeration

## Description

The D3DKMDT_VIDPN_PRESENT_PATH_COPYPROTECTION_TYPE enumeration is used to indicate the type of copy protection that is supported by a VidPN present path.

## Constants

### `D3DKMDT_VPPMT_UNINITIALIZED`

Indicates that a variable of type D3DKMDT_VIDPN_PRESENT_PATH_COPYPROTECTION_TYPE has not yet been assigned a meaningful value.

### `D3DKMDT_VPPMT_NOPROTECTION`

Indicates that the path has no copy protection.

### `D3DKMDT_VPPMT_MACROVISION_APSTRIGGER`

Indicates that the path provides support for Rovi's (formerly Macrovision) analog protection system (APS).

### `D3DKMDT_VPPMT_MACROVISION_FULLSUPPORT`

Indicates that the path provides full Rovi (formerly Macrovision) copy protection support.

## Remarks

The **CopyProtectionType** member of the [D3DKMDT_VIDPN_PRESENT_PATH_COPYPROTECTION](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmdt/ns-d3dkmdt-_d3dkmdt_vidpn_present_path_copyprotection) structure is a value from the D3DKMDT_VIDPN_PRESENT_PATH_COPYPROTECTION_TYPE enumeration.