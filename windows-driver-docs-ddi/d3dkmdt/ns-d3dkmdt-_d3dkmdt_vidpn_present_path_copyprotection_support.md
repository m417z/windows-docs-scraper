# _D3DKMDT_VIDPN_PRESENT_PATH_COPYPROTECTION_SUPPORT structure

## Description

The D3DKMDT_VIDPN_PRESENT_PATH_COPYPROTECTION_SUPPORT structure is used to indicate the types of copy protection that are supported by a particular VidPN present path.

## Members

### `NoProtection`

The path is not capable of providing any copy protection.

### `MacroVisionApsTrigger`

The path is capable of providing Rovi (formerly Macrovision) analog protection support (APS).

### `MacroVisionFull`

The path is capable of providing full Rovi (formerly Macrovision) copy protection.

### `Reserved`

Reserved for future use.

## Remarks

The **CopyProtectionSupport** member of the [D3DKMDT_VIDPN_PRESENT_PATH_COPYPROTECTION](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmdt/ns-d3dkmdt-_d3dkmdt_vidpn_present_path_copyprotection) structure is a D3DKMDT_VIDPN_PRESENT_PATH_COPYPROTECTION_SUPPORT structure.