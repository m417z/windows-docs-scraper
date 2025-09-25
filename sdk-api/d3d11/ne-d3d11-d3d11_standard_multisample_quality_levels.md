# D3D11_STANDARD_MULTISAMPLE_QUALITY_LEVELS enumeration

## Description

Specifies a multi-sample pattern type.

## Constants

### `D3D11_STANDARD_MULTISAMPLE_PATTERN:0xffffffff`

Pre-defined multi-sample patterns required for Direct3D 11 and Direct3D 10.1 hardware.

### `D3D11_CENTER_MULTISAMPLE_PATTERN:0xfffffffe`

Pattern where all of the samples are located at the pixel center.

## Remarks

An app calls [ID3D11Device::CheckMultisampleQualityLevels](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11device-checkmultisamplequalitylevels) to get the number of quality levels available during multisampling. A 0 quality level means the hardware does not support multisampling for the particular format. If the number of quality levels is greater than 0 and the hardware supports the fixed sample patterns for the sample count, the app can request the fixed patterns by specifying quality level as either **D3D11_STANDARD_MULTISAMPLE_PATTERN** or **D3D11_CENTER_MULTISAMPLE_PATTERN**. The app can call [ID3D11Device::CheckFormatSupport](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11device-checkformatsupport) to check for support of the standard fixed patterns. If the hardware only supports the fixed patterns but no additional vendor-specific patterns, the runtime can report the number of quality levels as 1, and the hardware can pretend 0 quality level behaves the same as quality level equal to D3D11_STANDARD_MULTISAMPLE_PATTERN.

The runtime defines the following standard sample patterns for 1(trivial), 2, 4, 8, and 16 sample counts. Hardware must support 1, 4, and 8 sample counts. Hardware vendors can expose more sample counts beyond these. However, if vendors support 2, 4(required), 8(required), or 16, they must also support the corresponding standard pattern or center pattern for each of those sample counts.

![Pattern for 1 Sample Count](https://learn.microsoft.com/windows/win32/api/d3d11/images/D3D11_MSAAGrid.png)

![Patterns for 2 and 4 Sample Count](https://learn.microsoft.com/windows/win32/api/d3d11/images/D3D11_MSAAPatterns_2_4.png)

![Patterns for 8 and 16 Sample Count](https://learn.microsoft.com/windows/win32/api/d3d11/images/D3D11_MSAAPatterns_8_16.png)

## See also

[Resource Enumerations](https://learn.microsoft.com/windows/desktop/direct3d11/d3d11-graphics-reference-resource-enums)