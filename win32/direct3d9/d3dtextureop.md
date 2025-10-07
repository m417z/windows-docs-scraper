# D3DTEXTUREOP enumeration

Defines per-stage texture-blending operations.

## Constants

**D3DTOP\_DISABLE**

Disables output from this texture stage and all stages with a higher index. To disable texture mapping, set this as the color operation for the first texture stage (stage 0). Alpha operations cannot be disabled when color operations are enabled. Setting the alpha operation to D3DTOP\_DISABLE when color blending is enabled causes undefined behavior.

**D3DTOP\_SELECTARG1**

Use this texture stage's first color or alpha argument, unmodified, as the output. This operation affects the color argument when used with the D3DTSS\_COLOROP texture-stage state, and the alpha argument when used with D3DTSS\_ALPHAOP.

![equation of this argument (s(rgba) = arg1)](https://learn.microsoft.com/windows/win32/direct3d9/images/topfrm1.png)

**D3DTOP\_SELECTARG2**

Use this texture stage's second color or alpha argument, unmodified, as the output. This operation affects the color argument when used with the D3DTSS\_COLOROP texture stage state, and the alpha argument when used with D3DTSS\_ALPHAOP.

![equation of this argument (s(rgba) = arg2)](https://learn.microsoft.com/windows/win32/direct3d9/images/topfrm2.png)

**D3DTOP\_MODULATE**

Multiply the components of the arguments.

![equation of the modulate operation (s(rgba) = arg1 x arg 2)](https://learn.microsoft.com/windows/win32/direct3d9/images/topfrm3.png)

**D3DTOP\_MODULATE2X**

Multiply the components of the arguments, and shift the products to the left 1 bit (effectively multiplying them by 2) for brightening.

![equation of the modulate2x operation (s(rgba) = (arg1 x arg 2) then shift left 1)](https://learn.microsoft.com/windows/win32/direct3d9/images/topfrm4.png)

**D3DTOP\_MODULATE4X**

Multiply the components of the arguments, and shift the products to the left 2 bits (effectively multiplying them by 4) for brightening.

![equation of the modulate4x operation (s(rgba) = (arg1 x arg 2) then shift left 2)](https://learn.microsoft.com/windows/win32/direct3d9/images/topfrm5.png)

**D3DTOP\_ADD**

Add the components of the arguments.

![equation of the add operation (s(rgba) = arg1 + arg 2)](https://learn.microsoft.com/windows/win32/direct3d9/images/topfrm6.png)

**D3DTOP\_ADDSIGNED**

Add the components of the arguments with a - 0.5 bias, making the effective range of values from - 0.5 through 0.5.

![equation of the add signed operation (s(rgba) = arg1 + arg 2 – 0.5)](https://learn.microsoft.com/windows/win32/direct3d9/images/topfrm7.png)

**D3DTOP\_ADDSIGNED2X**

Add the components of the arguments with a - 0.5 bias, and shift the products to the left 1 bit.

![equation of the add signed 2x operation ((s(rgba) = arg1 + arg 2 - 0.5) then shift left 1)](https://learn.microsoft.com/windows/win32/direct3d9/images/topfrm8.png)

**D3DTOP\_SUBTRACT**

Subtract the components of the second argument from those of the first argument.

![equation of the subtract operation (s(rgba) = arg1 - arg 2)](https://learn.microsoft.com/windows/win32/direct3d9/images/topfrm9.png)

**D3DTOP\_ADDSMOOTH**

Add the first and second arguments; then subtract their product from the sum.

![equation of the add smooth operation (s(rgba) = arg1 + arg 2 x (1 - arg1))](https://learn.microsoft.com/windows/win32/direct3d9/images/topfrm10.png)

**D3DTOP\_BLENDDIFFUSEALPHA**

Linearly blend this texture stage, using the interpolated alpha from each vertex.

![equation of the blend diffuse alpha operation (s(rgba) = arg1 x alpha + arg 2 x (1 - alpha))](https://learn.microsoft.com/windows/win32/direct3d9/images/topfrm11.png)

**D3DTOP\_BLENDTEXTUREALPHA**

Linearly blend this texture stage, using the alpha from this stage's texture.

![equation of the blend texture alpha operation (s(rgba) = arg1 x alpha + arg 2 x (1 - alpha))](https://learn.microsoft.com/windows/win32/direct3d9/images/topfrm11.png)

**D3DTOP\_BLENDFACTORALPHA**

Linearly blend this texture stage, using a scalar alpha set with the D3DRS\_TEXTUREFACTOR render state.

![equation of the blend factor alpha operation (s(rgba) = arg1 x alpha + arg 2 x (1 - alpha))](https://learn.microsoft.com/windows/win32/direct3d9/images/topfrm11.png)

**D3DTOP\_BLENDTEXTUREALPHAPM**

Linearly blend a texture stage that uses a premultiplied alpha.

![equation of the blend texture alpha pm operation (s(rgba) = arg1 + arg 2 x (1 - alpha))](https://learn.microsoft.com/windows/win32/direct3d9/images/topfrm12.png)

**D3DTOP\_BLENDCURRENTALPHA**

Linearly blend this texture stage, using the alpha taken from the previous texture stage.

![equation of the blend current alpha operation (s(rgba) = arg1 x alpha + arg2 x (1 - alpha))](https://learn.microsoft.com/windows/win32/direct3d9/images/topfrm11.png)

**D3DTOP\_PREMODULATE**

D3DTOP\_PREMODULATE is set in stage n. The output of stage n is arg1. Additionally, if there is a texture in stage n + 1, any D3DTA\_CURRENT in stage n + 1 is premultiplied by texture in stage n + 1.

**D3DTOP\_MODULATEALPHA\_ADDCOLOR**

Modulate the color of the second argument, using the alpha of the first argument; then add the result to argument one. This operation is supported only for color operations (D3DTSS\_COLOROP).

![equation of the add color modulate alpha operation (s(rgba) = arg1(rgb) + arg1(a) x arg2(rgb))](https://learn.microsoft.com/windows/win32/direct3d9/images/topfrm13.png)

**D3DTOP\_MODULATECOLOR\_ADDALPHA**

Modulate the arguments; then add the alpha of the first argument. This operation is supported only for color operations (D3DTSS\_COLOROP).

![equation of the add alpha modulate color operation (s(rgba) = arg1(rgb) x arg2(rgb) + arg1(a))](https://learn.microsoft.com/windows/win32/direct3d9/images/topfrm14.png)

**D3DTOP\_MODULATEINVALPHA\_ADDCOLOR**

Similar to D3DTOP\_MODULATEALPHA\_ADDCOLOR, but use the inverse of the alpha of the first argument. This operation is supported only for color operations (D3DTSS\_COLOROP).

![equation of the add color modulate inverse alpha operation (s(rgba) = (1 - arg1(a)) x arg2(rgb) + arg1(rgb))](https://learn.microsoft.com/windows/win32/direct3d9/images/topfrm15.png)

**D3DTOP\_MODULATEINVCOLOR\_ADDALPHA**

Similar to D3DTOP\_MODULATECOLOR\_ADDALPHA, but use the inverse of the color of the first argument. This operation is supported only for color operations (D3DTSS\_COLOROP).

![equation of the add alpha modulate inverse color operation (s(rgba) = (1 - arg1(rgb)) x arg2(rgb) + arg1(a))](https://learn.microsoft.com/windows/win32/direct3d9/images/topfrm16.png)

**D3DTOP\_BUMPENVMAP**

Perform per-pixel bump mapping, using the environment map in the next texture stage, without luminance. This operation is supported only for color operations (D3DTSS\_COLOROP).

**D3DTOP\_BUMPENVMAPLUMINANCE**

Perform per-pixel bump mapping, using the environment map in the next texture stage, with luminance. This operation is supported only for color operations (D3DTSS\_COLOROP).

**D3DTOP\_DOTPRODUCT3**

Modulate the components of each argument as signed components, add their products; then replicate the sum to all color channels, including alpha. This operation is supported for color and alpha operations.

![equation of the dot product 3 operation (s(rgba) = arg1(r) x arg2(r) + arg1(g) x arg2(g) + arg1(b) x arg2(b))](https://learn.microsoft.com/windows/win32/direct3d9/images/topfrm17.png)

In DirectX 6 and DirectX 7, multitexture operations the above inputs are all shifted down by half (y = x - 0.5) before use to simulate signed data, and the scalar result is automatically clamped to positive values and replicated to all three output channels. Also, note that as a color operation this does not updated the alpha it just updates the RGB components.

However, in DirectX 8.1 shaders you can specify that the output be routed to the .rgb or the .a components or both (the default). You can also specify a separate scalar operation on the alpha channel.

**D3DTOP\_MULTIPLYADD**

Performs a multiply-accumulate operation. It takes the last two arguments, multiplies them together, and adds them to the remaining input/source argument, and places that into the result.

SRGBA = Arg1 + Arg2 \* Arg3

**D3DTOP\_LERP**

Linearly interpolates between the second and third source arguments by a proportion specified in the first source argument.

SRGBA = (Arg1) \* Arg2 + (1- Arg1) \* Arg3.

**D3DTOP\_FORCE\_DWORD**

Forces this enumeration to compile to 32 bits in size. Without this value, some compilers would allow this enumeration to compile to a size other than 32 bits. This value is not used.

## Remarks

The members of this type are used when setting color or alpha operations by using the D3DTSS\_COLOROP or D3DTSS\_ALPHAOP values with the [**IDirect3DDevice9::SetTextureStageState**](https://learn.microsoft.com/windows/win32/api/d3d9helper/nf-d3d9helper-idirect3ddevice9-settexturestagestate) method.

In the above formulas, SRGBA is the RGBA color produced by a texture operation, and Arg1, Arg2, and Arg3 represent the complete RGBA color of the texture arguments. Individual components of an argument are shown with subscripts. For example, the alpha component for argument 1 would be shown as Arg1A.

## Requirements

| Requirement | Value |
|-------------------|----------------------------------------------------------------------------------------|
| Header<br> | D3D9Types.h |

## See also

[Direct3D Enumerations](https://learn.microsoft.com/windows/win32/direct3d9/dx9-graphics-reference-d3d-enums)

[**D3DTEXTURESTAGESTATETYPE**](https://learn.microsoft.com/windows/win32/direct3d9/d3dtexturestagestatetype)

