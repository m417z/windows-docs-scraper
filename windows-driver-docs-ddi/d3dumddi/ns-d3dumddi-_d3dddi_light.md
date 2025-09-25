# _D3DDDI_LIGHT structure

## Description

The D3DDDI_LIGHT structure describes a set of lighting properties.

## Members

### `Type` [in]

A D3DLIGHTTYPE-typed value that indicates the type of the light source. For more information about D3DLIGHTTYPE, see the Microsoft Windows SDK documentation.

### `Diffuse` [in]

A D3DCOLORVALUE structure that indicates the diffuse color that is emitted by the light. For more information about D3DCOLORVALUE, see the Windows SDK documentation.

### `Specular` [in]

A D3DCOLORVALUE structure that indicates the specular color that is emitted by the light.

### `Ambient` [in]

A D3DCOLORVALUE structure that indicates the ambient color that is emitted by the light.

### `Position` [in]

A D3DVECTOR structure that indicates the position of the light in world space. This member has no meaning for directional lights (that is, if D3DLIGHT_DIRECTIONAL is set in the **Type** member) and is ignored in that situation. For more information about D3DVECTOR, see the Windows SDK documentation.

### `Direction` [in]

A D3DVECTOR structure that indicates the direction that the light is pointing in world space. This member has meaning only for directional lights and spotlights (that is, if D3DLIGHT_DIRECTIONAL and D3DLIGHT_SPOT are set in **Type**). This vector is not required to be normalized, but it should have a nonzero length.

### `Range` [in]

The distance beyond which the light has no effect. The maximum allowable value for this member is D3DLIGHT_RANGE_MAX, which is defined as the square root of FLT_MAX. This member does not affect directional lights.

### `Falloff` [in]

The decrease in illumination between a spotlight's inner cone (the angle that is specified by the **Theta** member) and the outer edge of the outer cone (the angle that is specified by the **Phi** member). The effect of falloff on the lighting is subtle. Furthermore, a small performance penalty is incurred by shaping the falloff curve. For these reasons, most developers set this member to 1.0.

### `Attenuation0` [in]

The light's constant attenuation factor. Attenuation values specify how the light intensity changes over distance. Attenuation does not affect directional lights. Valid values for this member range from 0.0 through infinity.

### `Attenuation1` [in]

The light's linear attenuation factor. Attenuation values specify how the light intensity changes over distance. Attenuation does not affect directional lights. Valid values for this member range from 0.0 through infinity.

### `Attenuation2` [in]

The light's quadratic attenuation factor. Attenuation values specify how the light intensity changes over distance. Attenuation does not affect directional lights. Valid values for this member range from 0.0 through infinity.

### `Theta` [in]

The angle, in radians, of a spotlight's inner cone--that is, the fully illuminated spotlight cone. This value must be in the range from 0 through the value that is specified by the **Phi** member.

### `Phi` [in]

The angle, in radians, that defines the outer edge of the spotlight's outer cone. Points outside this cone are not lit by the spotlight. This value must be between 0 and Pi.

## See also

[SetLight](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_setlight)