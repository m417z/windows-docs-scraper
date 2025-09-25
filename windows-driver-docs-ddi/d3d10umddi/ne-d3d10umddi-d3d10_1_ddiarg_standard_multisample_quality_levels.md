# D3D10_1_DDIARG_STANDARD_MULTISAMPLE_QUALITY_LEVELS enumeration

## Description

The D3D10_1_DDIARG_STANDARD_MULTISAMPLE_QUALITY_LEVELS enumeration type contains values that identify quality levels for multisample patterns.

## Constants

### `D3D10_1_DDIARG_STANDARD_MULTISAMPLE_PATTERN`

The quality level value for standard multisample pattern.

### `D3D10_1_DDIARG_CENTER_MULTISAMPLE_PATTERN`

The same number of samples as D3D10_1_DDIARG_STANDARD_MULTISAMPLE_PATTERN, except all the samples overlap the center of the pixel.

## Remarks

The quality level value for standard multisample pattern is D3D10_1_DDIARG_STANDARD_MULTISAMPLE_PATTERN. To expose support for the standard multisample pattern for a given sample count, the driver must expose at least one standard quality level through its [CheckMultisampleQualityLevels](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_checkmultisamplequalitylevels) function. The D3D runtime can then use the D3D10_1_DDIARG_STANDARD_MULTISAMPLE_PATTERN value. If hardware vendors have no proprietary sample patterns that they want to expose and just have the standard pattern, they can just implement the standard pattern for both quality level 0 as well as quality level D3D10_1_DDIARG_STANDARD_MULTISAMPLE_PATTERN. In this situation, the driver's **CheckMultisampleQualityLevels** function would return a pointer to 1 in the *pNumQualityLevels* parameter. Applications can then request quality level 0 or D3D10_1_DDIARG_STANDARD_MULTISAMPLE_PATTERN, and both quality levels provide the same behavior.

For every sample count where D3D10_1_DDIARG_STANDARD_MULTISAMPLE_PATTERN is supported, a sibling pattern (D3D10_1_DDIARG_CENTER_MULTISAMPLE_PATTERN) must be supported. D3D10_1_DDIARG_CENTER_MULTISAMPLE_PATTERN has the same number of samples as D3D10_1_DDIARG_STANDARD_MULTISAMPLE_PATTERN, except all the samples overlap the center of the pixel.

## See also

[CheckMultisampleQualityLevels](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_checkmultisamplequalitylevels)