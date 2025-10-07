# D3DLIGHT9 structure

Defines a set of lighting properties.

## Members

**Type**

Type: **[**D3DLIGHTTYPE**](https://learn.microsoft.com/windows/win32/direct3d9/d3dlighttype)**

Type of the light source. This value is one of the members of the [**D3DLIGHTTYPE**](https://learn.microsoft.com/windows/win32/direct3d9/d3dlighttype) enumerated type.

**Diffuse**

Type: **[**D3DCOLORVALUE**](https://learn.microsoft.com/windows/win32/direct3d9/d3dcolorvalue)**

Diffuse color emitted by the light. This member is a [**D3DCOLORVALUE**](https://learn.microsoft.com/windows/win32/direct3d9/d3dcolorvalue) structure.

**Specular**

Type: **[**D3DCOLORVALUE**](https://learn.microsoft.com/windows/win32/direct3d9/d3dcolorvalue)**

Specular color emitted by the light. This member is a [**D3DCOLORVALUE**](https://learn.microsoft.com/windows/win32/direct3d9/d3dcolorvalue) structure.

**Ambient**

Type: **[**D3DCOLORVALUE**](https://learn.microsoft.com/windows/win32/direct3d9/d3dcolorvalue)**

Ambient color emitted by the light. This member is a [**D3DCOLORVALUE**](https://learn.microsoft.com/windows/win32/direct3d9/d3dcolorvalue) structure.

**Position**

Type: **[**D3DVECTOR**](https://learn.microsoft.com/windows/win32/direct3d9/d3dvector)**

Position of the light in world space, specified by a [**D3DVECTOR**](https://learn.microsoft.com/windows/win32/direct3d9/d3dvector) structure. This member has no meaning for directional lights and is ignored in that case.

**Direction**

Type: **[**D3DVECTOR**](https://learn.microsoft.com/windows/win32/direct3d9/d3dvector)**

Direction that the light is pointing in world space, specified by a [**D3DVECTOR**](https://learn.microsoft.com/windows/win32/direct3d9/d3dvector) structure. This member has meaning only for directional and spotlights. This vector need not be normalized, but it should have a nonzero length.

**Range**

Type: **float**

Distance beyond which the light has no effect. The maximum allowable value for this member is the square root of FLT\_MAX. This member does not affect directional lights.

**Falloff**

Type: **float**

Decrease in illumination between a spotlight's inner cone (the angle specified by Theta) and the outer edge of the outer cone (the angle specified by Phi).

The effect of falloff on the lighting is subtle. Furthermore, a small performance penalty is incurred by shaping the falloff curve. For these reasons, most developers set this value to 1.0.

**Attenuation0**

Type: **float**

Value specifying how the light intensity changes over distance. Attenuation values are ignored for directional lights. This member represents an attenuation constant. For information about attenuation, see [Light Properties (Direct3D 9)](https://learn.microsoft.com/windows/win32/direct3d9/light-properties). Valid values for this member range from 0.0 to infinity. For non-directional lights, all three attenuation values should not be set to 0.0 at the same time.

**Attenuation1**

Type: **float**

Value specifying how the light intensity changes over distance. Attenuation values are ignored for directional lights. This member represents an attenuation constant. For information about attenuation, see [Light Properties (Direct3D 9)](https://learn.microsoft.com/windows/win32/direct3d9/light-properties). Valid values for this member range from 0.0 to infinity. For non-directional lights, all three attenuation values should not be set to 0.0 at the same time.

**Attenuation2**

Type: **float**

Value specifying how the light intensity changes over distance. Attenuation values are ignored for directional lights. This member represents an attenuation constant. For information about attenuation, see [Light Properties (Direct3D 9)](https://learn.microsoft.com/windows/win32/direct3d9/light-properties). Valid values for this member range from 0.0 to infinity. For non-directional lights, all three attenuation values should not be set to 0.0 at the same time.

**Theta**

Type: **float**

Angle, in radians, of a spotlight's inner cone - that is, the fully illuminated spotlight cone. This value must be in the range from 0 through the value specified by Phi.

**Phi**

Type: **float**

Angle, in radians, defining the outer edge of the spotlight's outer cone. Points outside this cone are not lit by the spotlight. This value must be between 0 and pi.

## Requirements

| Requirement | Value |
|-------------------|----------------------------------------------------------------------------------------|
| Header<br> | D3D9Types.h |

## See also

[Direct3D Structures](https://learn.microsoft.com/windows/win32/direct3d9/dx9-graphics-reference-d3d-structures)

[**GetLight**](https://learn.microsoft.com/windows/win32/api/d3d9helper/nf-d3d9helper-idirect3ddevice9-getlight)

[**SetLight**](https://learn.microsoft.com/windows/win32/api/d3d9helper/nf-d3d9helper-idirect3ddevice9-setlight)

