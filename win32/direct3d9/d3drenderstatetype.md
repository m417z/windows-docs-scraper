# D3DRENDERSTATETYPE enumeration

Render states define set-up states for all kinds of vertex and pixel processing. Some render states set up vertex processing, and some set up pixel processing (see [Render States (Direct3D 9)](https://learn.microsoft.com/windows/win32/direct3d9/render-states)). Render states can be saved and restored using stateblocks (see [State Blocks Save and Restore State (Direct3D 9)](https://learn.microsoft.com/windows/win32/direct3d9/state-blocks-save-and-restore-state)).

## Constants

**D3DRS\_ZENABLE**

Depth-buffering state as one member of the [**D3DZBUFFERTYPE**](https://learn.microsoft.com/windows/win32/direct3d9/d3dzbuffertype) enumerated type. Set this state to D3DZB\_TRUE to enable z-buffering, D3DZB\_USEW to enable w-buffering, or D3DZB\_FALSE to disable depth buffering.

The default value for this render state is D3DZB\_TRUE if a depth stencil was created along with the swap chain by setting the EnableAutoDepthStencil member of the [**D3DPRESENT\_PARAMETERS**](https://learn.microsoft.com/windows/win32/direct3d9/d3dpresent-parameters) structure to **TRUE**, and D3DZB\_FALSE otherwise.

**D3DRS\_FILLMODE**

One or more members of the [**D3DFILLMODE**](https://learn.microsoft.com/windows/win32/direct3d9/d3dfillmode) enumerated type. The default value is D3DFILL\_SOLID.

**D3DRS\_SHADEMODE**

One or more members of the [**D3DSHADEMODE**](https://learn.microsoft.com/windows/win32/direct3d9/d3dshademode) enumerated type. The default value is D3DSHADE\_GOURAUD.

**D3DRS\_ZWRITEENABLE**

**TRUE** to enable the application to write to the depth buffer. The default value is **TRUE**. This member enables an application to prevent the system from updating the depth buffer with new depth values. If **FALSE**, depth comparisons are still made according to the render state D3DRS\_ZFUNC, assuming that depth buffering is taking place, but depth values are not written to the buffer.

**D3DRS\_ALPHATESTENABLE**

**TRUE** to enable per pixel alpha testing. If the test passes, the pixel is processed by the frame buffer. Otherwise, all frame-buffer processing is skipped for the pixel.

The test is done by comparing the incoming alpha value with the reference alpha value, using the comparison function provided by the D3DRS\_ALPHAFUNC render state. The reference alpha value is determined by the value set for D3DRS\_ALPHAREF. For more information, see [Alpha Testing State (Direct3D 9)](https://learn.microsoft.com/windows/win32/direct3d9/alpha-testing-state).

The default value of this parameter is **FALSE**.

**D3DRS\_LASTPIXEL**

The default value is **TRUE**, which enables drawing of the last pixel in a line. To prevent drawing of the last pixel, set this value to **FALSE**. For more information, see [Outline and Fill State (Direct3D 9)](https://learn.microsoft.com/windows/win32/direct3d9/outline-and-fill-state).

**D3DRS\_SRCBLEND**

One member of the [**D3DBLEND**](https://learn.microsoft.com/windows/win32/direct3d9/d3dblend) enumerated type. The default value is D3DBLEND\_ONE.

**D3DRS\_DESTBLEND**

One member of the [**D3DBLEND**](https://learn.microsoft.com/windows/win32/direct3d9/d3dblend) enumerated type. The default value is D3DBLEND\_ZERO.

**D3DRS\_CULLMODE**

Specifies how back-facing triangles are culled, if at all. This can be set to one member of the [**D3DCULL**](https://learn.microsoft.com/windows/win32/direct3d9/d3dcull) enumerated type. The default value is D3DCULL\_CCW.

**D3DRS\_ZFUNC**

One member of the [**D3DCMPFUNC**](https://learn.microsoft.com/windows/win32/direct3d9/d3dcmpfunc) enumerated type. The default value is D3DCMP\_LESSEQUAL. This member enables an application to accept or reject a pixel, based on its distance from the camera.

The depth value of the pixel is compared with the depth-buffer value. If the depth value of the pixel passes the comparison function, the pixel is written.

The depth value is written to the depth buffer only if the render state is **TRUE**.

Software rasterizers and many hardware accelerators work faster if the depth test fails, because there is no need to filter and modulate the texture if the pixel is not going to be rendered.

**D3DRS\_ALPHAREF**

Value that specifies a reference alpha value against which pixels are tested when alpha testing is enabled. This is an 8-bit value placed in the low 8 bits of the DWORD render-state value. Values can range from 0x00000000 through 0x000000FF. The default value is 0.

**D3DRS\_ALPHAFUNC**

One member of the [**D3DCMPFUNC**](https://learn.microsoft.com/windows/win32/direct3d9/d3dcmpfunc) enumerated type. The default value is D3DCMP\_ALWAYS. This member enables an application to accept or reject a pixel, based on its alpha value.

**D3DRS\_DITHERENABLE**

**TRUE** to enable dithering. The default value is **FALSE**.

**D3DRS\_ALPHABLENDENABLE**

**TRUE** to enable alpha-blended transparency. The default value is **FALSE**.

The type of alpha blending is determined by the D3DRS\_SRCBLEND and D3DRS\_DESTBLEND render states.

**D3DRS\_FOGENABLE**

**TRUE** to enable fog blending. The default value is **FALSE**. For more information about using fog blending, see [Fog](https://learn.microsoft.com/windows/win32/direct3d9/fog).

**D3DRS\_SPECULARENABLE**

**TRUE** to enable specular highlights. The default value is **FALSE**.

Specular highlights are calculated as though every vertex in the object being lit is at the object's origin. This gives the expected results as long as the object is modeled around the origin and the distance from the light to the object is relatively large. In other cases, the results as undefined.

When this member is set to **TRUE**, the specular color is added to the base color after the texture cascade but before alpha blending.

**D3DRS\_FOGCOLOR**

Value whose type is [**D3DCOLOR**](https://learn.microsoft.com/windows/win32/direct3d9/d3dcolor). The default value is 0. For more information about fog color, see [Fog Color (Direct3D 9)](https://learn.microsoft.com/windows/win32/direct3d9/fog-color).

**D3DRS\_FOGTABLEMODE**

The fog formula to be used for pixel fog. Set to one of the members of the [**D3DFOGMODE**](https://learn.microsoft.com/windows/win32/direct3d9/d3dfogmode) enumerated type. The default value is D3DFOG\_NONE. For more information about pixel fog, see [Pixel Fog (Direct3D 9)](https://learn.microsoft.com/windows/win32/direct3d9/pixel-fog).

**D3DRS\_FOGSTART**

Depth at which pixel or vertex fog effects begin for linear fog mode. The default value is 0.0f. Depth is specified in world space for vertex fog and either device space \[0.0, 1.0\] or world space for pixel fog. For pixel fog, these values are in device space when the system uses z for fog calculations and world-world space when the system is using eye-relative fog (w-fog). For more information, see [Fog Parameters (Direct3D 9)](https://learn.microsoft.com/windows/win32/direct3d9/fog-parameters) and [Eye-Relative vs. Z-based Depth](https://learn.microsoft.com/windows/win32/direct3d9/pixel-fog).

Values for this render state are floating-point values. Because the [**IDirect3DDevice9::SetRenderState**](https://learn.microsoft.com/windows/win32/api/d3d9helper/nf-d3d9helper-idirect3ddevice9-setrenderstate) method accepts DWORD values, your application must cast a variable that contains the value, as shown in the following code example.

```
pDevice9->SetRenderState(D3DRS_FOGSTART,
                         *((DWORD*) (&fFogStart)));
```

**D3DRS\_FOGEND**

Depth at which pixel or vertex fog effects end for linear fog mode. The default value is 1.0f. Depth is specified in world space for vertex fog and either device space \[0.0, 1.0\] or world space for pixel fog. For pixel fog, these values are in device space when the system uses z for fog calculations and in world space when the system is using eye-relative fog (w-fog). For more information, see [Fog Parameters (Direct3D 9)](https://learn.microsoft.com/windows/win32/direct3d9/fog-parameters) and [Eye-Relative vs. Z-based Depth](https://learn.microsoft.com/windows/win32/direct3d9/pixel-fog).

Values for this render state are floating-point values. Because the [**IDirect3DDevice9::SetRenderState**](https://learn.microsoft.com/windows/win32/api/d3d9helper/nf-d3d9helper-idirect3ddevice9-setrenderstate) method accepts DWORD values, your application must cast a variable that contains the value, as shown in the following code example.

```
m_pDevice9->SetRenderState(D3DRS_FOGEND, *((DWORD*) (&fFogEnd)));
```

**D3DRS\_FOGDENSITY**

Fog density for pixel or vertex fog used in the exponential fog modes (D3DFOG\_EXP and D3DFOG\_EXP2). Valid density values range from 0.0 through 1.0. The default value is 1.0. For more information, see [Fog Parameters (Direct3D 9)](https://learn.microsoft.com/windows/win32/direct3d9/fog-parameters).

Values for this render state are floating-point values. Because the [**IDirect3DDevice9::SetRenderState**](https://learn.microsoft.com/windows/win32/api/d3d9helper/nf-d3d9helper-idirect3ddevice9-setrenderstate) method accepts DWORD values, your application must cast a variable that contains the value, as shown in the following code example.

```
    m_pDevice9->SetRenderState(D3DRS_FOGDENSITY, *((DWORD*) (&fFogDensity)));
```

**D3DRS\_RANGEFOGENABLE**

**TRUE** to enable range-based vertex fog. The default value is **FALSE**, in which case the system uses depth-based fog. In range-based fog, the distance of an object from the viewer is used to compute fog effects, not the depth of the object (that is, the z-coordinate) in the scene. In range-based fog, all fog methods work as usual, except that they use range instead of depth in the computations.

Range is the correct factor to use for fog computations, but depth is commonly used instead because range is time-consuming to compute and depth is generally already available. Using depth to calculate fog has the undesirable effect of having the fogginess of peripheral objects change as the viewer's eye moves - in this case, the depth changes and the range remains constant.

Because no hardware currently supports per-pixel range-based fog, range correction is offered only for vertex fog.

For more information, see [Vertex Fog (Direct3D 9)](https://learn.microsoft.com/windows/win32/direct3d9/vertex-fog).

**D3DRS\_STENCILENABLE**

**TRUE** to enable stenciling, or **FALSE** to disable stenciling. The default value is **FALSE**. For more information, see [Stencil Buffer Techniques (Direct3D 9)](https://learn.microsoft.com/windows/win32/direct3d9/stencil-buffer-techniques).

**D3DRS\_STENCILFAIL**

Stencil operation to perform if the stencil test fails. Values are from the [**D3DSTENCILOP**](https://learn.microsoft.com/windows/win32/direct3d9/d3dstencilop) enumerated type. The default value is D3DSTENCILOP\_KEEP.

**D3DRS\_STENCILZFAIL**

Stencil operation to perform if the stencil test passes and the depth test (z-test) fails. Values are from the [**D3DSTENCILOP**](https://learn.microsoft.com/windows/win32/direct3d9/d3dstencilop) enumerated type. The default value is D3DSTENCILOP\_KEEP.

**D3DRS\_STENCILPASS**

Stencil operation to perform if both the stencil and the depth (z) tests pass. Values are from the [**D3DSTENCILOP**](https://learn.microsoft.com/windows/win32/direct3d9/d3dstencilop) enumerated type. The default value is D3DSTENCILOP\_KEEP.

**D3DRS\_STENCILFUNC**

Comparison function for the stencil test. Values are from the [**D3DCMPFUNC**](https://learn.microsoft.com/windows/win32/direct3d9/d3dcmpfunc) enumerated type. The default value is D3DCMP\_ALWAYS.

The comparison function is used to compare the reference value to a stencil buffer entry. This comparison applies only to the bits in the reference value and stencil buffer entry that are set in the stencil mask (set by the D3DRS\_STENCILMASK render state). If **TRUE**, the stencil test passes.

**D3DRS\_STENCILREF**

An int reference value for the stencil test. The default value is 0.

**D3DRS\_STENCILMASK**

Mask applied to the reference value and each stencil buffer entry to determine the significant bits for the stencil test. The default mask is 0xFFFFFFFF.

**D3DRS\_STENCILWRITEMASK**

Write mask applied to values written into the stencil buffer. The default mask is 0xFFFFFFFF.

**D3DRS\_TEXTUREFACTOR**

Color used for multiple-texture blending with the D3DTA\_TFACTOR texture-blending argument or the D3DTOP\_BLENDFACTORALPHA texture-blending operation. The associated value is a [**D3DCOLOR**](https://learn.microsoft.com/windows/win32/direct3d9/d3dcolor) variable. The default value is opaque white (0xFFFFFFFF).

**D3DRS\_WRAP0**

Texture-wrapping behavior for multiple sets of texture coordinates. Valid values for this render state can be any combination of the D3DWRAPCOORD\_0 (or D3DWRAP\_U), D3DWRAPCOORD\_1 (or D3DWRAP\_V), D3DWRAPCOORD\_2 (or D3DWRAP\_W), and D3DWRAPCOORD\_3 flags. These cause the system to wrap in the direction of the first, second, third, and fourth dimensions, sometimes referred to as the s, t, r, and q directions, for a given texture. The default value for this render state is 0 (wrapping disabled in all directions).

**D3DRS\_WRAP1**

See D3DRS\_WRAP0.

**D3DRS\_WRAP2**

See D3DRS\_WRAP0.

**D3DRS\_WRAP3**

See D3DRS\_WRAP0.

**D3DRS\_WRAP4**

See D3DRS\_WRAP0.

**D3DRS\_WRAP5**

See D3DRS\_WRAP0.

**D3DRS\_WRAP6**

See D3DRS\_WRAP0.

**D3DRS\_WRAP7**

See D3DRS\_WRAP0.

**D3DRS\_CLIPPING**

**TRUE** to enable primitive clipping by Direct3D, or **FALSE** to disable it. The default value is **TRUE**.

**D3DRS\_LIGHTING**

**TRUE** to enable Direct3D lighting, or **FALSE** to disable it. The default value is **TRUE**. Only vertices that include a vertex normal are properly lit; vertices that do not contain a normal employ a dot product of 0 in all lighting calculations.

**D3DRS\_AMBIENT**

Ambient light color. This value is of type [**D3DCOLOR**](https://learn.microsoft.com/windows/win32/direct3d9/d3dcolor). The default value is 0.

**D3DRS\_FOGVERTEXMODE**

Fog formula to be used for vertex fog. Set to one member of the [**D3DFOGMODE**](https://learn.microsoft.com/windows/win32/direct3d9/d3dfogmode) enumerated type. The default value is D3DFOG\_NONE.

**D3DRS\_COLORVERTEX**

**TRUE** to enable per-vertex color or **FALSE** to disable it. The default value is **TRUE**. Enabling per-vertex color allows the system to include the color defined for individual vertices in its lighting calculations.

For more information, see the following render states:

- D3DRS\_DIFFUSEMATERIALSOURCE
- D3DRS\_SPECULARMATERIALSOURCE
- D3DRS\_AMBIENTMATERIALSOURCE
- D3DRS\_EMISSIVEMATERIALSOURCE

**D3DRS\_LOCALVIEWER**

**TRUE** to enable camera-relative specular highlights, or **FALSE** to use orthogonal specular highlights. The default value is **TRUE**. Applications that use orthogonal projection should specify **FALSE**.

**D3DRS\_NORMALIZENORMALS**

**TRUE** to enable automatic normalization of vertex normals, or **FALSE** to disable it. The default value is **FALSE**. Enabling this feature causes the system to normalize the vertex normals for vertices after transforming them to camera space, which can be computationally time-consuming.

**D3DRS\_DIFFUSEMATERIALSOURCE**

Diffuse color source for lighting calculations. Valid values are members of the [**D3DMATERIALCOLORSOURCE**](https://learn.microsoft.com/windows/win32/direct3d9/d3dmaterialcolorsource) enumerated type. The default value is D3DMCS\_COLOR1. The value for this render state is used only if the D3DRS\_COLORVERTEX render state is set to **TRUE**.

**D3DRS\_SPECULARMATERIALSOURCE**

Specular color source for lighting calculations. Valid values are members of the [**D3DMATERIALCOLORSOURCE**](https://learn.microsoft.com/windows/win32/direct3d9/d3dmaterialcolorsource) enumerated type. The default value is D3DMCS\_COLOR2.

**D3DRS\_AMBIENTMATERIALSOURCE**

Ambient color source for lighting calculations. Valid values are members of the [**D3DMATERIALCOLORSOURCE**](https://learn.microsoft.com/windows/win32/direct3d9/d3dmaterialcolorsource) enumerated type. The default value is D3DMCS\_MATERIAL.

**D3DRS\_EMISSIVEMATERIALSOURCE**

Emissive color source for lighting calculations. Valid values are members of the [**D3DMATERIALCOLORSOURCE**](https://learn.microsoft.com/windows/win32/direct3d9/d3dmaterialcolorsource) enumerated type. The default value is D3DMCS\_MATERIAL.

**D3DRS\_VERTEXBLEND**

Number of matrices to use to perform geometry blending, if any. Valid values are members of the [**D3DVERTEXBLENDFLAGS**](https://learn.microsoft.com/windows/win32/direct3d9/d3dvertexblendflags) enumerated type. The default value is D3DVBF\_DISABLE.

**D3DRS\_CLIPPLANEENABLE**

Enables or disables user-defined clipping planes. Valid values are any DWORD in which the status of each bit (set or not set) toggles the activation state of a corresponding user-defined clipping plane. The least significant bit (bit 0) controls the first clipping plane at index 0, and subsequent bits control the activation of clipping planes at higher indexes. If a bit is set, the system applies the appropriate clipping plane during scene rendering. The default value is 0.

The [**D3DCLIPPLANEn**](https://learn.microsoft.com/windows/win32/direct3d9/d3dclipplanen) macros are defined to provide a convenient way to enable clipping planes.

**D3DRS\_POINTSIZE**

A float value that specifies the size to use for point size computation in cases where point size is not specified for each vertex. This value is not used when the vertex contains point size. This value is in screen space units if D3DRS\_POINTSCALEENABLE is **FALSE**; otherwise this value is in world space units. The default value is the value a driver returns. If a driver returns 0 or 1, the default value is 64, which allows software point size emulation. Because the [**IDirect3DDevice9::SetRenderState**](https://learn.microsoft.com/windows/win32/api/d3d9helper/nf-d3d9helper-idirect3ddevice9-setrenderstate) method accepts DWORD values, your application must cast a variable that contains the value, as shown in the following code example.

```
m_pDevice9->SetRenderState(D3DRS_POINTSIZE, *((DWORD*)&pointSize));
```

**D3DRS\_POINTSIZE\_MIN**

A float value that specifies the minimum size of point primitives. Point primitives are clamped to this size during rendering. Setting this to values smaller than 1.0 results in points dropping out when the point does not cover a pixel center and antialiasing is disabled or being rendered with reduced intensity when antialiasing is enabled. The default value is 1.0f. The range for this value is greater than or equal to 0.0f. Because the [**IDirect3DDevice9::SetRenderState**](https://learn.microsoft.com/windows/win32/api/d3d9helper/nf-d3d9helper-idirect3ddevice9-setrenderstate) method accepts DWORD values, your application must cast a variable that contains the value, as shown in the following code example.

```
m_pDevice9->SetRenderState(D3DRS_POINTSIZE_MIN, *((DWORD*)&pointSizeMin));
```

**D3DRS\_POINTSPRITEENABLE**

bool value. When **TRUE**, texture coordinates of point primitives are set so that full textures are mapped on each point. When **FALSE**, the vertex texture coordinates are used for the entire point. The default value is **FALSE**. You can achieve DirectX 7 style single-pixel points by setting D3DRS\_POINTSCALEENABLE to **FALSE** and D3DRS\_POINTSIZE to 1.0, which are the default values.

**D3DRS\_POINTSCALEENABLE**

bool value that controls computation of size for point primitives. When **TRUE**, the point size is interpreted as a camera space value and is scaled by the distance function and the frustum to viewport y-axis scaling to compute the final screen-space point size. When **FALSE**, the point size is interpreted as screen space and used directly. The default value is **FALSE**.

**D3DRS\_POINTSCALE\_A**

A float value that controls for distance-based size attenuation for point primitives. Active only when D3DRS\_POINTSCALEENABLE is **TRUE**. The default value is 1.0f. The range for this value is greater than or equal to 0.0f. Because the [**IDirect3DDevice9::SetRenderState**](https://learn.microsoft.com/windows/win32/api/d3d9helper/nf-d3d9helper-idirect3ddevice9-setrenderstate) method accepts DWORD values, your application must cast a variable that contains the value, as shown in the following code example.

```
m_pDevice9->SetRenderState(D3DRS_POINTSCALE_A, *((DWORD*)&pointScaleA));
```

**D3DRS\_POINTSCALE\_B**

A float value that controls for distance-based size attenuation for point primitives. Active only when D3DRS\_POINTSCALEENABLE is **TRUE**. The default value is 0.0f. The range for this value is greater than or equal to 0.0f. Because the [**IDirect3DDevice9::SetRenderState**](https://learn.microsoft.com/windows/win32/api/d3d9helper/nf-d3d9helper-idirect3ddevice9-setrenderstate) method accepts DWORD values, your application must cast a variable that contains the value, as shown in the following code example.

```
m_pDevice9->SetRenderState(D3DRS_POINTSCALE_B, *((DWORD*)&pointScaleB));
```

**D3DRS\_POINTSCALE\_C**

A float value that controls for distance-based size attenuation for point primitives. Active only when D3DRS\_POINTSCALEENABLE is **TRUE**. The default value is 0.0f. The range for this value is greater than or equal to 0.0f. Because the [**IDirect3DDevice9::SetRenderState**](https://learn.microsoft.com/windows/win32/api/d3d9helper/nf-d3d9helper-idirect3ddevice9-setrenderstate) method accepts DWORD values, your application must cast a variable that contains the value, as shown in the following code example.

```
m_pDevice9->SetRenderState(D3DRS_POINTSCALE_C, *((DWORD*)&pointScaleC));
```

**D3DRS\_MULTISAMPLEANTIALIAS**

bool value that determines how individual samples are computed when using a multisample render-target buffer. When set to **TRUE**, the multiple samples are computed so that full-scene antialiasing is performed by sampling at different sample positions for each multiple sample. When set to **FALSE**, the multiple samples are all written with the same sample value, sampled at the pixel center, which allows non-antialiased rendering to a multisample buffer. This render state has no effect when rendering to a single sample buffer. The default value is **TRUE**.

**D3DRS\_MULTISAMPLEMASK**

Each bit in this mask, starting at the least significant bit (LSB), controls modification of one of the samples in a multisample render target. Thus, for an 8-sample render target, the low byte contains the eight write enables for each of the eight samples. This render state has no effect when rendering to a single sample buffer. The default value is 0xFFFFFFFF.

This render state enables use of a multisample buffer as an accumulation buffer, doing multipass rendering of geometry where each pass updates a subset of samples.

If there are n multisamples and k enabled samples, the resulting intensity of the rendered image should be k/n. Each component RGB of every pixel is factored by k/n.

**D3DRS\_PATCHEDGESTYLE**

Sets whether patch edges will use float style tessellation. Possible values are defined by the [**D3DPATCHEDGESTYLE**](https://learn.microsoft.com/windows/win32/direct3d9/d3dpatchedgestyle) enumerated type. The default value is D3DPATCHEDGE\_DISCRETE.

**D3DRS\_DEBUGMONITORTOKEN**

Set only for debugging the monitor. Possible values are defined by the [**D3DDEBUGMONITORTOKENS**](https://learn.microsoft.com/windows/win32/direct3d9/d3ddebugmonitortokens) enumerated type. Note that if D3DRS\_DEBUGMONITORTOKEN is set, the call is treated as passing a token to the debug monitor. For example, if - after passing D3DDMT\_ENABLE or D3DDMT\_DISABLE to D3DRS\_DEBUGMONITORTOKEN - other token values are passed in, the state (enabled or disabled) of the debug monitor will still persist.

This state is only useful for debug builds. The debug monitor defaults to D3DDMT\_ENABLE.

**D3DRS\_POINTSIZE\_MAX**

A float value that specifies the maximum size to which point sprites will be clamped. The value must be less than or equal to the MaxPointSize member of [**D3DCAPS9**](https://learn.microsoft.com/windows/desktop/api/D3D9Caps/ns-d3d9caps-d3dcaps9) and greater than or equal to D3DRS\_POINTSIZE\_MIN. The default value is 64.0. Because the [**IDirect3DDevice9::SetRenderState**](https://learn.microsoft.com/windows/win32/api/d3d9helper/nf-d3d9helper-idirect3ddevice9-setrenderstate) method accepts DWORD values, your application must cast a variable that contains the value, as shown in the following code example.

```
m_pDevice9->SetRenderState(D3DRS_PONTSIZE_MAX, *((DWORD*)&pointSizeMax));
```

**D3DRS\_INDEXEDVERTEXBLENDENABLE**

bool value that enables or disables indexed vertex blending. The default value is **FALSE**. When set to **TRUE**, indexed vertex blending is enabled. When set to **FALSE**, indexed vertex blending is disabled. If this render state is enabled, the user must pass matrix indices as a packed DWORDwith every vertex. When the render state is disabled and vertex blending is enabled through the D3DRS\_VERTEXBLEND state, it is equivalent to having matrix indices 0, 1, 2, 3 in every vertex.

**D3DRS\_COLORWRITEENABLE**

UINT value that enables a per-channel write for the render-target color buffer. A set bit results in the color channel being updated during 3D rendering. A clear bit results in the color channel being unaffected. This functionality is available if the D3DPMISCCAPS\_COLORWRITEENABLE capabilities bit is set in the PrimitiveMiscCaps member of the [**D3DCAPS9**](https://learn.microsoft.com/windows/desktop/api/D3D9Caps/ns-d3d9caps-d3dcaps9) structure for the device. This render state does not affect the clear operation. The default value is 0x0000000F.

Valid values for this render state can be any combination of the D3DCOLORWRITEENABLE\_ALPHA, D3DCOLORWRITEENABLE\_BLUE, D3DCOLORWRITEENABLE\_GREEN, or D3DCOLORWRITEENABLE\_RED flags.

**D3DRS\_TWEENFACTOR**

A float value that controls the tween factor. The default value is 0.0f. Because the [**IDirect3DDevice9::SetRenderState**](https://learn.microsoft.com/windows/win32/api/d3d9helper/nf-d3d9helper-idirect3ddevice9-setrenderstate) method accepts DWORD values, your application must cast a variable that contains the value, as shown in the following code example.

```
m_pDevice9->SetRenderState(D3DRS_TWEENFACTOR, *((DWORD*)&TweenFactor));
```

**D3DRS\_BLENDOP**

Value used to select the arithmetic operation applied when the alpha blending render state, D3DRS\_ALPHABLENDENABLE, is set to **TRUE**. Valid values are defined by the [**D3DBLENDOP**](https://learn.microsoft.com/windows/win32/direct3d9/d3dblendop) enumerated type. The default value is D3DBLENDOP\_ADD.

If the D3DPMISCCAPS\_BLENDOP device capability is not supported, then D3DBLENDOP\_ADD is performed.

**D3DRS\_POSITIONDEGREE**

N-patch position interpolation degree. The values can be D3DDEGREE\_CUBIC (default) or D3DDEGREE\_LINEAR. For more information, see [**D3DDEGREETYPE**](https://learn.microsoft.com/windows/win32/direct3d9/d3ddegreetype).

**D3DRS\_NORMALDEGREE**

N-patch normal interpolation degree. The values can be D3DDEGREE\_LINEAR (default) or D3DDEGREE\_QUADRATIC. For more information, see [**D3DDEGREETYPE**](https://learn.microsoft.com/windows/win32/direct3d9/d3ddegreetype).

**D3DRS\_SCISSORTESTENABLE**

**TRUE** to enable scissor testing and **FALSE** to disable it. The default value is **FALSE**.

**D3DRS\_SLOPESCALEDEPTHBIAS**

Used to determine how much bias can be applied to co-planar primitives to reduce z-fighting. The default value is 0.

bias = (max \* D3DRS\_SLOPESCALEDEPTHBIAS) + D3DRS\_DEPTHBIAS.

where max is the maximum depth slope of the triangle being rendered.

**D3DRS\_ANTIALIASEDLINEENABLE**

**TRUE** to enable line antialiasing, **FALSE** to disable line antialiasing. The default value is **FALSE**.

When rendering to a multisample render target, D3DRS\_ANTIALIASEDLINEENABLE is ignored and all lines are rendered aliased. Use [**ID3DXLine**](https://learn.microsoft.com/windows/win32/direct3d9/id3dxline) for antialiased line rendering in a multisample render target.

**D3DRS\_MINTESSELLATIONLEVEL**

Minimum tessellation level. The default value is 1.0f. See [Tessellation (Direct3D 9)](https://learn.microsoft.com/windows/win32/direct3d9/tessellation).

**D3DRS\_MAXTESSELLATIONLEVEL**

Maximum tessellation level. The default value is 1.0f. See [Tessellation (Direct3D 9)](https://learn.microsoft.com/windows/win32/direct3d9/tessellation).

**D3DRS\_ADAPTIVETESS\_X**

Amount to adaptively tessellate, in the x direction. Default value is 0.0f. See [Adaptive Tessellation](https://learn.microsoft.com/windows/win32/direct3d9/tessellation).

**D3DRS\_ADAPTIVETESS\_Y**

Amount to adaptively tessellate, in the y direction. Default value is 0.0f. See [Adaptive\_Tessellation](https://learn.microsoft.com/windows/win32/direct3d9/tessellation).

**D3DRS\_ADAPTIVETESS\_Z**

Amount to adaptively tessellate, in the z direction. Default value is 1.0f. See [Adaptive\_Tessellation](https://learn.microsoft.com/windows/win32/direct3d9/tessellation).

**D3DRS\_ADAPTIVETESS\_W**

Amount to adaptively tessellate, in the w direction. Default value is 0.0f. See [Adaptive\_Tessellation](https://learn.microsoft.com/windows/win32/direct3d9/tessellation).

**D3DRS\_ENABLEADAPTIVETESSELLATION**

**TRUE** to enable adaptive tessellation, **FALSE** to disable it. The default value is **FALSE**. See [Adaptive\_Tessellation](https://learn.microsoft.com/windows/win32/direct3d9/tessellation).

**D3DRS\_TWOSIDEDSTENCILMODE**

**TRUE** enables two-sided stenciling, **FALSE** disables it. The default value is **FALSE**. The application should set D3DRS\_CULLMODE to D3DCULL\_NONE to enable two-sided stencil mode. If the triangle winding order is clockwise, the D3DRS\_STENCIL\* operations will be used. If the winding order is counterclockwise, the D3DRS\_CCW\_STENCIL\* operations will be used.

To see if two-sided stencil is supported, check the StencilCaps member of [**D3DCAPS9**](https://learn.microsoft.com/windows/desktop/api/D3D9Caps/ns-d3d9caps-d3dcaps9) for D3DSTENCILCAPS\_TWOSIDED. See also [D3DSTENCILCAPS](https://learn.microsoft.com/windows/win32/direct3d9/d3dstencilcaps).

**D3DRS\_CCW\_STENCILFAIL**

Stencil operation to perform if CCW stencil test fails. Values are from the [**D3DSTENCILOP**](https://learn.microsoft.com/windows/win32/direct3d9/d3dstencilop) enumerated type. The default value is D3DSTENCILOP\_KEEP.

**D3DRS\_CCW\_STENCILZFAIL**

Stencil operation to perform if CCW stencil test passes and z-test fails. Values are from the [**D3DSTENCILOP**](https://learn.microsoft.com/windows/win32/direct3d9/d3dstencilop) enumerated type. The default value is D3DSTENCILOP\_KEEP.

**D3DRS\_CCW\_STENCILPASS**

Stencil operation to perform if both CCW stencil and z-tests pass. Values are from the [**D3DSTENCILOP**](https://learn.microsoft.com/windows/win32/direct3d9/d3dstencilop) enumerated type. The default value is D3DSTENCILOP\_KEEP.

**D3DRS\_CCW\_STENCILFUNC**

The comparison function. CCW stencil test passes if ((ref & mask) stencil function (stencil & mask)) is **TRUE**. Values are from the [**D3DCMPFUNC**](https://learn.microsoft.com/windows/win32/direct3d9/d3dcmpfunc) enumerated type. The default value is D3DCMP\_ALWAYS.

**D3DRS\_COLORWRITEENABLE1**

Additional ColorWriteEnable values for the devices. See D3DRS\_COLORWRITEENABLE. This functionality is available if the D3DPMISCCAPS\_INDEPENDENTWRITEMASKS capabilities bit is set in the PrimitiveMiscCaps member of the [**D3DCAPS9**](https://learn.microsoft.com/windows/desktop/api/D3D9Caps/ns-d3d9caps-d3dcaps9) structure for the device. The default value is 0x0000000f.

**D3DRS\_COLORWRITEENABLE2**

Additional ColorWriteEnable values for the devices. See D3DRS\_COLORWRITEENABLE. This functionality is available if the D3DPMISCCAPS\_INDEPENDENTWRITEMASKS capabilities bit is set in the PrimitiveMiscCaps member of the [**D3DCAPS9**](https://learn.microsoft.com/windows/desktop/api/D3D9Caps/ns-d3d9caps-d3dcaps9) structure for the device. The default value is 0x0000000f.

**D3DRS\_COLORWRITEENABLE3**

Additional ColorWriteEnable values for the devices. See D3DRS\_COLORWRITEENABLE. This functionality is available if the D3DPMISCCAPS\_INDEPENDENTWRITEMASKS capabilities bit is set in the PrimitiveMiscCaps member of the [**D3DCAPS9**](https://learn.microsoft.com/windows/desktop/api/D3D9Caps/ns-d3d9caps-d3dcaps9) structure for the device. The default value is 0x0000000f.

**D3DRS\_BLENDFACTOR**

[**D3DCOLOR**](https://learn.microsoft.com/windows/win32/direct3d9/d3dcolor) used for a constant blend-factor during alpha blending. This functionality is available if the D3DPBLENDCAPS\_BLENDFACTOR capabilities bit is set in the SrcBlendCaps member of [**D3DCAPS9**](https://learn.microsoft.com/windows/desktop/api/D3D9Caps/ns-d3d9caps-d3dcaps9) or the DestBlendCaps member of **D3DCAPS9**. See [**D3DRENDERSTATETYPE**](). The default value is 0xffffffff.

**D3DRS\_SRGBWRITEENABLE**

Enable render-target writes to be gamma corrected to sRGB. The format must expose D3DUSAGE\_SRGBWRITE. The default value is 0.

**D3DRS\_DEPTHBIAS**

A floating-point value that is used for comparison of depth values. See [Depth Bias (Direct3D 9)](https://learn.microsoft.com/windows/win32/direct3d9/depth-bias). The default value is 0.

**D3DRS\_WRAP8**

See D3DRS\_WRAP0.

**D3DRS\_WRAP9**

See D3DRS\_WRAP0.

**D3DRS\_WRAP10**

See D3DRS\_WRAP0.

**D3DRS\_WRAP11**

See D3DRS\_WRAP0.

**D3DRS\_WRAP12**

See D3DRS\_WRAP0.

**D3DRS\_WRAP13**

See D3DRS\_WRAP0.

**D3DRS\_WRAP14**

See D3DRS\_WRAP0.

**D3DRS\_WRAP15**

See D3DRS\_WRAP0.

**D3DRS\_SEPARATEALPHABLENDENABLE**

**TRUE** enables the separate blend mode for the alpha channel. The default value is **FALSE**.

When set to **FALSE**, the render-target blending factors and operations applied to alpha are forced to be the same as those defined for color. This mode is effectively hardwired to **FALSE** on implementations that don't set the cap D3DPMISCCAPS\_SEPARATEALPHABLEND. See [D3DPMISCCAPS](https://learn.microsoft.com/windows/win32/direct3d9/d3dpmisccaps).

The type of separate alpha blending is determined by the D3DRS\_SRCBLENDALPHA and D3DRS\_DESTBLENDALPHA render states.

**D3DRS\_SRCBLENDALPHA**

One member of the [**D3DBLEND**](https://learn.microsoft.com/windows/win32/direct3d9/d3dblend) enumerated type. This value is ignored unless D3DRS\_SEPARATEALPHABLENDENABLE is **TRUE**. The default value is D3DBLEND\_ONE.

**D3DRS\_DESTBLENDALPHA**

One member of the [**D3DBLEND**](https://learn.microsoft.com/windows/win32/direct3d9/d3dblend) enumerated type. This value is ignored unless D3DRS\_SEPARATEALPHABLENDENABLE is **TRUE**. The default value is D3DBLEND\_ZERO.

**D3DRS\_BLENDOPALPHA**

Value used to select the arithmetic operation applied to separate alpha blending when the render state, D3DRS\_SEPARATEALPHABLENDENABLE, is set to **TRUE**.

Valid values are defined by the [**D3DBLENDOP**](https://learn.microsoft.com/windows/win32/direct3d9/d3dblendop) enumerated type. The default value is D3DBLENDOP\_ADD.

If the D3DPMISCCAPS\_BLENDOP device capability is not supported, then D3DBLENDOP\_ADD is performed. See [D3DPMISCCAPS](https://learn.microsoft.com/windows/win32/direct3d9/d3dpmisccaps).

**D3DRS\_FORCE\_DWORD**

Forces this enumeration to compile to 32 bits in size. Without this value, some compilers would allow this enumeration to compile to a size other than 32 bits. This value is not used.

## Remarks

| Render states | Texture sampler |
|----------------------|--------------------|
| ps\_1\_1 to ps\_1\_3 | 4 texture samplers |

Direct3D defines the D3DRENDERSTATE\_WRAPBIAS constant as a convenience for applications to enable or disable texture wrapping, based on the zero-based integer of a texture coordinate set (rather than explicitly using one of the D3DRS\_WRAP n state values). Add the D3DRENDERSTATE\_WRAPBIAS value to the zero-based index of a texture coordinate set to calculate the D3DRS\_WRAP n value that corresponds to that index, as shown in the following example.

```
// Enable U/V wrapping for textures that use the texture
// coordinate set at the index within the dwIndex variable

HRESULT hr = pd3dDevice->SetRenderState(
dwIndex + D3DRENDERSTATE_WRAPBIAS,
D3DWRAPCOORD_0 | D3DWRAPCOORD_1);

// If dwIndex is 3, the value that results from
// the addition equals D3DRS_WRAP3 (131)
```

## Requirements

| Requirement | Value |
|-------------------|----------------------------------------------------------------------------------------|
| Header<br> | D3D9Types.h |

## See also

[Direct3D Enumerations](https://learn.microsoft.com/windows/win32/direct3d9/dx9-graphics-reference-d3d-enums)

[**IDirect3DDevice9::GetRenderState**](https://learn.microsoft.com/windows/win32/api/d3d9helper/nf-d3d9helper-idirect3ddevice9-getrenderstate)

[**IDirect3DDevice9::SetRenderState**](https://learn.microsoft.com/windows/win32/api/d3d9helper/nf-d3d9helper-idirect3ddevice9-setrenderstate)

