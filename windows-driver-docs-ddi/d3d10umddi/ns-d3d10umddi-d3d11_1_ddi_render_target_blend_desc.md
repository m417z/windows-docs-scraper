# D3D11_1_DDI_RENDER_TARGET_BLEND_DESC structure

## Description

Describes a blend state for a render target. Used by Windows Display Driver Model (WDDM) 1.2 and later user-mode display drivers.

## Members

### `BlendEnable` [in]

A Boolean value that specifies whether blending is enabled for the associated render target. **TRUE** indicates blending is enabled; **FALSE** indicates blending is disabled.

> [!NOTE]
> The **LogicOpEnable** and **BlendEnable** members must not both be **TRUE**.

### `LogicOpEnable`

Specifies whether shader logic operations given by the **LogicOp** member are available in the blend state. The user-mode display driver sets **LogicOpEnable** to **TRUE** if logic operations are available in the blend state and **FALSE** otherwise.

This member is **FALSE** if the driver supports Direct3D feature level 9.1, 9.2, and 9.3. This member is optional if the driver supports feature level 10, 10.1, and 11.

This member is **TRUE** if the driver supports feature level 11.1 and later.

> [!NOTE]
> The **LogicOpEnable** and **BlendEnable** members must not both be **TRUE**.

### `SrcBlend` [in]

A value of type [**D3D10_DDI_BLEND**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ne-d3d10umddi-d3d10_ddi_blend) that indicates the blend mode of the source for the enabled render target.

### `DestBlend` [in]

A value of type [**D3D10_DDI_BLEND**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ne-d3d10umddi-d3d10_ddi_blend) that indicates the blend mode of the destination for the enabled render target.

### `BlendOp` [in]

A value of type [**D3D10_DDI_BLEND_OP**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ne-d3d10umddi-d3d10_ddi_blend_op) that indicates the blending operation for the enabled render target.

### `SrcBlendAlpha` [in]

A value of type [**D3D10_DDI_BLEND**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ne-d3d10umddi-d3d10_ddi_blend) that indicates the transparency blend mode of the source for the enabled render target.

### `DestBlendAlpha` [in]

A value of type [**D3D10_DDI_BLEND**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ne-d3d10umddi-d3d10_ddi_blend) that indicates the transparency blend mode of the destination for the enabled render target.

### `BlendOpAlpha` [in]

A value of type [**D3D10_DDI_BLEND_OP**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ne-d3d10umddi-d3d10_ddi_blend_op) that indicates the transparency blending operation for the enabled render target.

### `LogicOp` [in]

A value of type [**D3D11_1_DDI_LOGIC_OP**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ne-d3d10umddi-d3d11_1_ddi_logic_op) that specifies shader logic operations that are available in the blend state.

### `RenderTargetWriteMask` [in]

An 8-bit bitwise value that indicates the write properties for the enabled render target. Each bit must be set to one of the following values from the D3D10_DDI_COLOR_WRITE_ENABLE enumeration.

|Value|Meaning|
|--- |--- |
|D3D10_DDI_COLOR_WRITE_ENABLE_RED (1) |Writes red|
|D3D10_DDI_COLOR_WRITE_ENABLE_GREEN (2) |Writes green|
|D3D10_DDI_COLOR_WRITE_ENABLE_BLUE (4) |Writes blue|
|D3D10_DDI_COLOR_WRITE_ENABLE_ALPHA (8) |Writes a transparency level|
|D3D10_DDI_COLOR_WRITE_ENABLE_ALL (bitwise OR of 1,2,4,8)|Writes red, green, blue, and a transparency level|

## See also

[**CalcPrivateBlendStateSize**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_calcprivateblendstatesize)

[**CreateBlendState(D3D11_1)**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11_1ddi_createblendstate)

[**D3D10_DDI_BLEND**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ne-d3d10umddi-d3d10_ddi_blend)

[**D3D10_DDI_BLEND_OP**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ne-d3d10umddi-d3d10_ddi_blend_op)

[**D3D11_1_DDI_BLEND_DESC**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d11_1_ddi_blend_desc)

[**D3D11_1_DDI_LOGIC_OP**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ne-d3d10umddi-d3d11_1_ddi_logic_op)