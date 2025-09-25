# _DXGKMDT_OPM_SET_ACP_AND_CGMSA_SIGNALING_PARAMETERS structure

## Description

The DXGKMDT_OPM_SET_ACP_AND_CGMSA_SIGNALING_PARAMETERS structure contains parameters to set Analog Content Protection (ACP) and Content Generation Management System Analog (CGMS-A) signaling for a protected output.

## Members

### `ulNewTVProtectionStandard`

A [DXGKMDT_OPM_PROTECTION_STANDARD](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmdt/ne-d3dkmdt-_dxgkmdt_opm_protection_standard)-typed value that indicates the type of television signal to set ACP and CGMS-A signaling for on the protected output.

### `ulAspectRatioChangeMask1`

A mask value that indicates the valid bits to change in the following **ulAspectRatioData1** member.

### `ulAspectRatioData1`

32-bit data that indicates the aspect ratio value to set for the active protection standard.

### `ulAspectRatioChangeMask2`

A mask value that indicates the valid bits to change in the following **ulAspectRatioData2** member.

### `ulAspectRatioData2`

32-bit data for additional aspect ratio-related data for specific protection standards. This data can be used to express End and Q0 values for EIA-608-B, or active format description for CEA-805-A Type B packets.

### `ulAspectRatioChangeMask3`

A mask value that indicates the valid bits to change in the following **ulAspectRatioData3** member.

### `ulAspectRatioData3`

32-bit data for additional aspect ratio-related data for specific protection standards. This data can be used to express End and Q0 values for EIA-608-B, or active format description for CEA-805-A Type B packets.

### `ulReserved`

Reserved. Must be set to zero.

### `ulReserved2`

Reserved. Must be set to zero.

### `ulReserved3`

Reserved. Must be set to zero.

## See also

[DXGKMDT_OPM_PROTECTION_STANDARD](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmdt/ne-d3dkmdt-_dxgkmdt_opm_protection_standard)