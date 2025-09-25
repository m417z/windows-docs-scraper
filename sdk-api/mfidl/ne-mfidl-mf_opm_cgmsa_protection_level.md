# MF_OPM_CGMSA_PROTECTION_LEVEL enumeration

## Description

Defines protection levels for **MFPROTECTION_CGMSA**.

## Constants

### `MF_OPM_CGMSA_OFF:0`

CGMS-A is disabled.

### `MF_OPM_CGMSA_COPY_FREELY:0x1`

The protection level is Copy Freely.

### `MF_OPM_CGMSA_COPY_NO_MORE:0x2`

The protection level is Copy No More.

### `MF_OPM_CGMSA_COPY_ONE_GENERATION:0x3`

The protection level is Copy One Generation.

### `MF_OPM_CGMSA_COPY_NEVER:0x4`

The protection level is Copy Never.

### `MF_OPM_CGMSA_REDISTRIBUTION_CONTROL_REQUIRED:0x8`

Redistribution control (also called the broadcast flag) is required. This flag can be combined with the other flags.

## Remarks

These flags are equivalent to the OPM_CGMSA_Protection_Level enumeration constants used in the Output Protection Protocol (OPM).

## See also

[Media Foundation Enumerations](https://learn.microsoft.com/windows/desktop/medfound/media-foundation-enumerations)