# D3D11_1_DDI_RASTERIZER_DESC structure

## Description

Describes a rasterizer state. Used by Windows Display Driver Model (WDDM) 1.2 and later user-mode display drivers.

## Members

### `FillMode` [in]

A value that specifies the fill mode for primitives. This member must be set to one of the following values from the D3D10_DDI_FILL_MODE enumeration.

|Value|Meaning|
|--- |--- |
|D3D10_DDI_FILL_WIREFRAME (2)|Fills wireframes.|
|D3D10_DDI_FILL_SOLID (3)|Fills solids.|

### `CullMode` [in]

A value that specifies how back-facing triangles are culled, if at all. This member must be set to one of the following values from the D3D10_DDI_CULL_MODE enumeration.

|Value|Meaning|
|--- |--- |
|D3D10_DDI_CULL_NONE (1)|Do not cull any triangles.|
|D3D10_DDI_CULL_FRONT (2)|Cull front faces.|
|D3D10_DDI_CULL_BACK (3)|Cull back faces.|

### `FrontCounterClockwise` [in]

A Boolean value that specifies whether vertices that are provided in a counter-clockwise order (with respect to the rasterizer) are front facing. **TRUE** indicates they are; **FALSE** indicates that counter-clockwise vertices indicate back facing.

### `DepthBias` [in]

A depth-bias constant to use in biasing formulas. For more information about **DepthBias**, see the Remarks section.

### `DepthBiasClamp` [in]

A single-precision float vector that is used in biasing formulas. For more information about **DepthBiasClamp**, see the Remarks section.

### `SlopeScaledDepthBias` [in]

A single-precision float vector that is used in biasing formulas. For more information about **SlopeScaledDepthBias**, see the Remarks section.

### `DepthClipEnable` [in]

A Boolean value that specifies whether the driver should clip vertex z coordinates against the viewport depth range. **TRUE** indicates to clip; **FALSE** indicates not to clip.

### `ScissorEnable` [in]

A Boolean value that specifies whether the driver should discard pixels that fall outside the appropriate scissor rectangular area. **TRUE** indicates to discard; **FALSE** indicates not to discard.

### `MultisampleEnable` [in]

A Boolean value that specifies whether the driver must follow multiple-sampled rasterization rules. **TRUE** indicates to follow the rules; **FALSE** indicates following the rules is not required. Multiple-sampled rasterization rules hold true even if render targets contain only a single sample.

### `AntialiasedLineEnable` [in]

A Boolean value that specifies whether the driver should render lines that follow the antialiased line rasterization rules. **TRUE** indicates to follow the rules; **FALSE** indicates following the rules is not required. The driver ignores the value in **AntialiasedLineEnable** if multiple-sampling rasterization rules are used instead.

### `ForcedSampleCount` [in]

During rendering of unordered access views (UAVs) or rendering target views (RTVs), specifies whether to force a sample count, and if so, the maximum sample count. Valid values are 0, 1, 4, 8, and 16.

If zero, the driver should not force a sample count.

## Remarks

One of the artifacts with shadow buffer-based shadows is "shadow acne" (that is, a surface that shadows itself in an intermittent way because of inexactness in computing the depth of the surface from the shader that is compared against the depth of the same surface in the shadow buffer). One way to alleviate shadow acne is to use the **DepthBias** and **SlopeScaledDepthBias** members when you render a shadow buffer. The intent is to push surfaces out enough when rendering a shadow buffer. When those surfaces are compared against themselves through shader-computed z during the shadow test, the comparison result is consistent across the surface, and local-self-shadowing is avoided.

However, using **DepthBias** and **SlopeScaledDepthBias** alone can introduce a few artifacts. For example, an extremely steep polygon causes the bias equation to explode, which pushes the polygon extremely far away from the originating surface in the shadow map. Consider a steep face, with respect to a light, that is pushed away extremely far in relation to the dimensions of the parent object by depth biasing. Suppose this face is surrounded by shallower faces that the bias equation pushed out much less. The resulting shadow map has a huge discontinuity that can cause holes in the shadow that is cast by one surface onto another surface closer than the exploded faces. One way to help alleviate this particular problem is to use the **DepthBiasClamp** member, which provides an application-settable upper bound (positive or negative) on the magnitude of z biasing.