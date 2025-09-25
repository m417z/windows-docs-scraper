# D3D11_1DDI_D3D11_OPTIONS_DATA structure

## Description

Specifies options to provide data to the user-mode display driver.

## Members

### `OutputMergerLogicOp`

Specifies whether logic operations are available in the blend state. The user-mode display driver sets this member to **TRUE** if logic operations are available in the blend state and **FALSE** otherwise. This member is **FALSE** if the driver supports Direct3D feature level 9.1, 9.2, and 9.3. This member is optional if the driver supports feature level 10, 10.1, and 11. This member is **TRUE** if the driver supports feature level 11.1 and later.

### `AssignDebugBinarySupport`

Specifies whether the driver supports the [AssignDebugBinary](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11_1ddi_assigndebugbinary) function, which provides the full shader binary that is available after shader creation.

## See also

[AssignDebugBinary](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11_1ddi_assigndebugbinary)