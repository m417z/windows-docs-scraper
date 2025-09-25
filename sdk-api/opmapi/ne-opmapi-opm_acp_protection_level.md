# OPM_ACP_PROTECTION_LEVEL enumeration

## Description

Specifies the protection level for Analog Copy Protection (ACP).

## Constants

### `OPM_ACP_OFF:0`

ACP is disabled.

### `OPM_ACP_LEVEL_ONE:1`

ACP protection level 1.

### `OPM_ACP_LEVEL_TWO:2`

ACP protection level 2.

### `OPM_ACP_LEVEL_THREE:3`

ACP protection level 3.

### `OPM_ACP_FORCE_ULONG:0x7fffffff`

Reserved.

## Remarks

This enumeration is numerically equivalent to the **COPP_ACP_Protection_Level** enumeration used in Certified Output Protection Protocol. The OPM_ACP_OFF flag corresponds to COPP_ACP_Level0.

## See also

[OPM Enumerations](https://learn.microsoft.com/windows/desktop/medfound/opm-enumerations)