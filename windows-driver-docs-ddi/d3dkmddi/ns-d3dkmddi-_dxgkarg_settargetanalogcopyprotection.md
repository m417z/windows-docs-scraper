# _DXGKARG_SETTARGETANALOGCOPYPROTECTION structure

## Description

Holds information to set analog copy protection on a display adapter's video present target.

## Members

### `TargetId` [in]

The identifier of a display adapter's video present target.

### `CopyProtectionType` [in]

A value from the D3DKMDT_VIDPN_PRESENT_PATH_COPYPROTECTION_TYPE enum indicating the type of analog copy protection being requested.

### `APSTriggerBits` [in]

A value that describes copy protection for an OEM device. A value of 0 indicates no copy protection, and values of 1, 2, and 3 indicate low, medium, and high levels of copy protection, respectively. Values greater than 3 are not allowed.

### `CopyProtectionSupport` [in]

A D3DKMDT_VIDPN_PRESENT_PATH_COPYPROTECTION_SUPPORT structure containing flags indicating the analog copy protection support being requested.