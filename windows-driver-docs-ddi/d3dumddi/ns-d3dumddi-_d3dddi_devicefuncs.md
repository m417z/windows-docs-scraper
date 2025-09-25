# _D3DDDI_DEVICEFUNCS structure

## Description

The D3DDDI_DEVICEFUNCS structure contains functions that the user-mode display driver can implement to render graphics primitives and process state changes.

## Members

### `pfnSetRenderState`

A pointer to the driver [SetRenderState](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_setrenderstate) function that updates the render state.

### `pfnUpdateWInfo`

A pointer to the driver [UpdateWInfo](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_updatewinfo) function that updates the w range for w buffering.

### `pfnValidateDevice`

A pointer to the driver [ValidateDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_validatedevice) function that returns the number of passes in which the hardware can perform the blending operations that are specified in the current state.

### `pfnSetTextureStageState`

A pointer to the driver [SetTextureStageState](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_settexturestagestate) function that updates the state of a texture at a particular stage in a multiple-texture group.

### `pfnSetTexture`

A pointer to the driver [SetTexture](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_settexture) function that sets a texture to a particular stage in a multiple-texture group.

### `pfnSetPixelShader`

A pointer to the driver [SetPixelShader](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_setpixelshader) function that sets the current pixel shader.

### `pfnSetPixelShaderConst`

A pointer to the driver [SetPixelShaderConst](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_setpixelshaderconst) function that sets one or more pixel shader constant registers with float values.

### `pfnSetStreamSourceUm`

A pointer to the driver [SetStreamSourceUM](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_setstreamsourceum) function that binds a vertex stream source to a user memory buffer.

### `pfnSetIndices`

A pointer to the driver [SetIndices](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_setindices) function that sets the current index buffer.

### `pfnSetIndicesUm`

A pointer to the driver [SetIndicesUM](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_setindicesum) function that binds an index buffer to a user memory buffer.

### `pfnDrawPrimitive`

A pointer to the driver [DrawPrimitive](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_drawprimitive) function that draws nonindexed primitives in which the Microsoft Direct3D runtime has not transformed the vertex data.

### `pfnDrawIndexedPrimitive`

A pointer to the driver [DrawIndexedPrimitive](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_drawindexedprimitive) function that draws indexed primitives in which the Direct3D runtime has not transformed the vertex data.

### `pfnDrawRectPatch`

A pointer to the driver [DrawRectPatch](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_drawrectpatch) function that draws a new or cached rectangular patch or updates the specification of a previously defined patch.

### `pfnDrawTriPatch`

A pointer to the driver [DrawTriPatch](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_drawtripatch) function that draws a new or cached triangular patch or updates the specification of a previously defined patch.

### `pfnDrawPrimitive2`

A pointer to the driver [DrawPrimitive2](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_drawprimitive2) function that draws nonindexed primitives in which the Direct3D runtime has transformed the vertex data.

### `pfnDrawIndexedPrimitive2`

A pointer to the driver [DrawIndexedPrimitive2](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_drawindexedprimitive2) function that draws indexed primitives in which the Direct3D runtime has transformed the vertex data.

### `pfnVolBlt`

A pointer to the driver [VolBlt](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_volblt) function that performs a bit-block transfer (bitblt) from a source volume texture to a destination volume texture.

### `pfnBufBlt`

A pointer to the driver [BufBlt](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_bufblt) function that performs a bitblt from a source vertex or index buffer to a destination vertex or index buffer.

### `pfnTexBlt`

A pointer to the driver [TexBlt](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_texblt) function that performs a bitblt from a source texture to a destination texture.

### `pfnStateSet`

A pointer to the driver [StateSet](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_stateset) function that performs a state-set operation.

### `pfnSetPriority`

A pointer to the driver [SetPriority](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_setpriority) function that sets the eviction-from-memory priority for a managed texture.

### `pfnClear`

A pointer to the driver [Clear](https://learn.microsoft.com/windows-hardware/drivers/ddi/) function that performs hardware-assisted clearing on the rendering target, depth buffer, or stencil buffer.

### `pfnUpdatePalette`

A pointer to the driver [UpdatePalette](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_updatepalette) function that updates a texture palette.

### `pfnSetPalette`

A pointer to the driver [SetPalette](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_setpalette) function that sets the palette for a texture.

### `pfnSetVertexShaderConst`

A pointer to the driver [SetVertexShaderConst](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_setvertexshaderconst) function that sets one or more vertex shader constant registers with float values.

### `pfnMultiplyTransform`

A pointer to the driver [MultiplyTransform](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_multiplytransform) function that multiplies a current transform.

### `pfnSetTransform`

A pointer to the driver [SetTransform](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_settransform) function that sets up a transform.

### `pfnSetViewport`

A pointer to the driver [SetViewport](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_setviewport) function that informs guard-band aware drivers of the view-clipping rectangle.

### `pfnSetZRange`

A pointer to the driver [SetZRange](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_setzrange) function that informs the driver about the range of z values.

### `pfnSetMaterial`

A pointer to the driver [SetMaterial](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_setmaterial) function that sets the material properties that devices on the system use to create the required effect during rendering.

### `pfnSetLight`

A pointer to the driver [SetLight](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_setlight) function that sets properties for a light source.

### `pfnCreateLight`

A pointer to the driver [CreateLight](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_createlight) function that creates a light source.

### `pfnDestroyLight`

A pointer to the driver [DestroyLight](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_destroylight) function that deactivates a light source.

### `pfnSetClipPlane`

A pointer to the driver [SetClipPlane](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_setclipplane) function that sets a clip plane.

### `pfnGetInfo`

A pointer to the driver [GetInfo](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfinterrupt-getinfo) function that retrieves information about the device.

### `pfnLock`

A pointer to the driver [Lock](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_lock) function that locks a resource or a surface within the resource.

### `pfnUnlock`

A pointer to the driver [Unlock](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_unlock) function that unlocks a resource or a surface within the resource that the [Lock](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_lock) function previously locked.

### `pfnCreateResource`

A pointer to the driver [CreateResource](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_createresource) function that creates a resource.

### `pfnDestroyResource`

A pointer to the driver [DestroyResource](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_destroyresource) function that releases the resource that the [CreateResource](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_createresource) function created.

### `pfnSetDisplayMode`

A pointer to the driver [SetDisplayMode](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_setdisplaymode) function that sets a surface for displaying.

### `pfnPresent`

A pointer to the driver [Present](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_present) function that requests that the source surface be displayed by either copying or flipping.

### `pfnFlush`

A pointer to the user-mode display driver [Flush](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfworkitem-flush) function that submits outstanding hardware commands that are in the hardware command buffer to the display miniport driver.

### `pfnCreateVertexShaderFunc`

A pointer to the driver [CreateVertexShaderFunc](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_createvertexshaderfunc) function that converts the vertex shader code into a hardware-specific format and associates this code with the given shader handle.

### `pfnDeleteVertexShaderFunc`

A pointer to the driver [DeleteVertexShaderFunc](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_deletevertexshaderfunc) function that cleans up driver-side resources that are associated with vertex shader code.

### `pfnSetVertexShaderFunc`

A pointer to the driver [SetVertexShaderFunc](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_setvertexshaderfunc) function that sets the vertex shader code so that all of the subsequent drawing operations use that code.

### `pfnCreateVertexShaderDecl`

A pointer to the driver [CreateVertexShaderDecl](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_createvertexshaderdecl) function that converts the vertex shader declaration into a hardware-specific format and associates this declaration with the given shader handle.

### `pfnDeleteVertexShaderDecl`

A pointer to the driver [DeleteVertexShaderDecl](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_deletevertexshaderdecl) function that cleans up driver-side resources that are associated with the vertex shader declaration.

### `pfnSetVertexShaderDecl`

A pointer to the driver [SetVertexShaderDecl](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_setvertexshaderdecl) function that sets the vertex shader declaration so that all of the subsequent drawing operations use that declaration.

### `pfnSetVertexShaderConstI`

A pointer to the driver [SetVertexShaderConstI](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_setvertexshaderconsti) function that sets one or more vertex shader constant registers with integer values.

### `pfnSetVertexShaderConstB`

A pointer to the driver [SetVertexShaderConstB](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_setvertexshaderconstb) function that sets one or more vertex shader constant registers with Boolean values.

### `pfnSetScissorRect`

A pointer to the driver [SetScissorRect](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_setscissorrect) function that marks a portion of a render target to which rendering is restricted.

### `pfnSetStreamSource`

A pointer to the driver [SetStreamSource](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_setstreamsource) function that binds a portion of a vertex stream source to a vertex buffer.

### `pfnSetStreamSourceFreq`

A pointer to the driver [SetStreamSourceFreq](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_setstreamsourcefreq) function that sets the frequency divisor of a stream source that is bound to a vertex buffer.

### `pfnSetConvolutionKernelMono`

A pointer to the driver [SetConvolutionKernelMono](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_setconvolutionkernelmono) function that sets the monochrome convolution kernel.

### `pfnComposeRects`

A pointer to the driver [ComposeRects](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_composerects) function that composes rectangular areas.

### `pfnBlt`

A pointer to the driver [Blt](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_blt) function that copies the contents of a source surface to a destination surface.

### `pfnColorFill`

A pointer to the driver [ColorFill](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_colorfill) function that fills a rectangular area on a surface with a particular A8R8G8B8 color.

### `pfnDepthFill`

A pointer to the driver [DepthFill](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_depthfill) function that fills a depth buffer with a pixel value that is specified in native format.

### `pfnCreateQuery`

A pointer to the driver [CreateQuery](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_createquery) function that creates driver-side resources for a query that the Direct3D runtime subsequently issues for processing.

### `pfnDestroyQuery`

A pointer to the driver [DestroyQuery](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_destroyquery) function that releases resources for the query that the [CreateQuery](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_createquery) function created.

### `pfnIssueQuery`

A pointer to the driver [IssueQuery](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_issuequery) function that processes the query that the [CreateQuery](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_createquery) function created.

### `pfnGetQueryData`

A pointer to the driver [GetQueryData](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_getquerydata) function that retrieves information about a query.

### `pfnSetRenderTarget`

A pointer to the driver [SetRenderTarget](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_setrendertarget) function that sets the render target surface in the driver's context.

### `pfnSetDepthStencil`

A pointer to the driver [SetDepthStencil](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_setdepthstencil) function that sets the depth buffer in the driver's context.

### `pfnGenerateMipSubLevels`

A pointer to the driver [GenerateMipSubLevels](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_generatemipsublevels) function that regenerates the sublevels of a MIP-map texture.

### `pfnSetPixelShaderConstI`

A pointer to the driver [SetPixelShaderConstI](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_setpixelshaderconsti) function that sets one or more pixel shader constant registers with integer values.

### `pfnSetPixelShaderConstB`

A pointer to the driver [SetPixelShaderConstB](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_setpixelshaderconstb) function that sets one or more pixel shader constant registers with Boolean values.

### `pfnCreatePixelShader`

A pointer to the driver [CreatePixelShader](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_createpixelshader) function that converts the pixel shader code into a hardware-specific format and associates this code with a shader handle.

### `pfnDeletePixelShader`

A pointer to the driver [DeletePixelShader](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_deletepixelshader) function that cleans up driver-side resources that are associated with pixel shader code.

### `pfnCreateDecodeDevice`

A pointer to the driver [CreateDecodeDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_createdecodedevice) function that creates a representation of a Microsoft DirectX Video Acceleration (VA) decode device from supplied parameters.

### `pfnDestroyDecodeDevice`

A pointer to the driver [DestroyDecodeDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_destroydecodedevice) function that releases resources for a DirectX VA decode device.

### `pfnSetDecodeRenderTarget`

A pointer to the driver [SetDecodeRenderTarget](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_setdecoderendertarget) function that sets the render target for decoding. *SetDecodeRenderTarget* can be called only outside of a [DecodeBeginFrame](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_decodebeginframe)/[DecodeEndFrame](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_decodeendframe) block.

### `pfnDecodeBeginFrame`

A pointer to the driver [DecodeBeginFrame](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_decodebeginframe) function that indicates that decoding of a frame can begin.

### `pfnDecodeEndFrame`

A pointer to the driver [DecodeEndFrame](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_decodeendframe) function that indicates that frame decoding operations must be completed.

### `pfnDecodeExecute`

A pointer to the driver [DecodeExecute](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_decodeexecute) function that performs a DirectX VA decode operation. *DecodeExecute* must be called inside a [DecodeBeginFrame](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_decodebeginframe)/[DecodeEndFrame](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_decodeendframe) block.

### `pfnDecodeExtensionExecute`

A pointer to the driver [DecodeExtensionExecute](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_decodeextensionexecute) function that performs a nonstandard DirectX VA decode operation. *DecodeExtensionExecute* must be called inside a [DecodeBeginFrame](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_decodebeginframe)/[DecodeEndFrame](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_decodeendframe) block.

### `pfnCreateVideoProcessDevice`

A pointer to the driver [CreateVideoProcessDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_createvideoprocessdevice) function that creates a representation of a DirectX VA video processing device from supplied parameters.

### `pfnDestroyVideoProcessDevice`

A pointer to the driver [DestroyVideoProcessDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_destroyvideoprocessdevice) function that releases resources for a DirectX VA video processing device.

### `pfnVideoProcessBeginFrame`

A pointer to the driver [VideoProcessBeginFrame](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_videoprocessbeginframe) function that indicates that video processing of a frame can begin.

### `pfnVideoProcessEndFrame`

A pointer to the driver [VideoProcessEndFrame](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_videoprocessendframe) function that indicates that video processing operations must be completed.

### `pfnSetVideoProcessRenderTarget`

A pointer to the driver [SetVideoProcessRenderTarget](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_setvideoprocessrendertarget) function that sets the render target for video processing. *SetVideoProcessRenderTarget* can be called only outside of a [VideoProcessBeginFrame](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_videoprocessbeginframe)/[VideoProcessEndFrame](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_videoprocessendframe) block.

### `pfnVideoProcessBlt`

A pointer to the driver [VideoProcessBlt](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_videoprocessblt) function that processes DirectX VA video. *VideoProcessBlt* must be called inside a [VideoProcessBeginFrame](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_videoprocessbeginframe)/[VideoProcessEndFrame](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_videoprocessendframe) block.

### `pfnCreateExtensionDevice`

A pointer to the driver [CreateExtensionDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_createextensiondevice) function that creates a representation of a DirectX VA extension device from supplied parameters.

### `pfnDestroyExtensionDevice`

A pointer to the driver [DestroyExtensionDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_destroyextensiondevice) function that releases resources for a DirectX VA extension device.

### `pfnExtensionExecute`

A pointer to the driver [ExtensionExecute](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_extensionexecute) function that performs an operation that is specific to the given DirectX VA extension device.

### `pfnCreateOverlay`

A pointer to the driver [CreateOverlay](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_createoverlay) function that allocates overlay hardware and makes the overlay visible.

### `pfnUpdateOverlay`

A pointer to the driver [UpdateOverlay](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_updateoverlay) function that reconfigures or moves an overlay that is being displayed.

### `pfnFlipOverlay`

A pointer to the driver [FlipOverlay](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_flipoverlay) function that causes the overlay hardware to start displaying the new allocation.

### `pfnGetOverlayColorControls`

A pointer to the driver [GetOverlayColorControls](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_getoverlaycolorcontrols) function that retrieves color-control settings for an overlay.

### `pfnSetOverlayColorControls`

A pointer to the driver [SetOverlayColorControls](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_setoverlaycolorcontrols) function that changes color-control settings for an overlay.

### `pfnDestroyOverlay`

A pointer to the driver [DestroyOverlay](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_destroyoverlay) function that disables the overlay hardware and frees the overlay handle.

### `pfnDestroyDevice`

A pointer to the driver [DestroyDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_destroydevice) function that releases resources for the display device.

### `pfnQueryResourceResidency`

A pointer to the driver [QueryResourceResidency](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_queryresourceresidency) function that determines the residency of resources.

### `pfnOpenResource`

A pointer to the driver [OpenResource](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_openresource) function that informs the driver that a shared resource is opened.

### `pfnGetCaptureAllocationHandle`

A pointer to the driver [GetCaptureAllocationHandle](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_getcaptureallocationhandle) function that maps the given capture resource to an allocation.

### `pfnCaptureToSysMem`

A pointer to the driver [CaptureToSysMem](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_capturetosysmem) function that copies a capture buffer to a video memory surface.

### `pfnLockAsync`

A pointer to the driver [LockAsync](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_lockasync) function that locks a resource or a surface within the resource.

### `pfnUnlockAsync`

A pointer to the driver [UnlockAsync](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_unlockasync) function that unlocks a resource or a surface within the resource that the [LockAsync](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_lockasync) function previously locked.

### `pfnRename`

A pointer to the driver [Rename](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_rename) function that renames, with a new allocation, a resource or a surface within the resource.

### `pfnCreateVideoProcessor`

A pointer to the driver [CreateVideoProcessor](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_dxvahd_createvideoprocessor) function that creates a video processor.

### `pfnSetVideoProcessBltState`

A pointer to the driver [SetVideoProcessBltState](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_dxvahd_setvideoprocessbltstate) function that sets the state of a bitblt for a video processor.

### `pfnGetVideoProcessBltStatePrivate`

A pointer to the driver [GetVideoProcessBltStatePrivate](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_dxvahd_getvideoprocessbltstateprivate) function that retrieves the state data of a private bitblt for a video processor.

### `pfnSetVideoProcessStreamState`

A pointer to the driver [SetVideoProcessStreamState](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_dxvahd_setvideoprocessstreamstate) function that sets the state of a stream for a video processor.

### `pfnGetVideoProcessStreamStatePrivate`

A pointer to the driver [GetVideoProcessStreamStatePrivate](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_dxvahd_getvideoprocessstreamstateprivate) function that retrieves the private stream-state data for a video processor.

### `pfnVideoProcessBltHD`

A pointer to the driver [VideoProcessBltHD](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_dxvahd_videoprocessblthd) function that processes video input streams and composes to an output surface.

### `pfnDestroyVideoProcessor`

A pointer to the driver [DestroyVideoProcessor](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11_1ddi_destroyvideoprocessor) function that releases resources for a previously created video processor.

### `pfnCreateAuthenticatedChannel`

A pointer to the driver [CreateAuthenticatedChannel](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_createauthenticatedchannel) function that creates a channel that the Direct3D runtime and the driver can use to set and query protections.

### `pfnAuthenticatedChannelKeyExchange`

A pointer to the driver [AuthenticatedChannelKeyExchange](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_authenticatedchannelkeyexchange) function that negotiates the session key.

### `pfnQueryAuthenticatedChannel`

A pointer to the driver [QueryAuthenticatedChannel](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_queryauthenticatedchannel) function that queries an authenticated channel for capability and state information.

### `pfnConfigureAuthenticatedChannel`

A pointer to the driver [ConfigureAuthenticatedChannel](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_configureauthenicatedchannel) function that sets the state within an authenticated channel.

### `pfnDestroyAuthenticatedChannel`

A pointer to the driver [DestroyAuthenticatedChannel](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11_1ddi_destroyauthenticatedchannel) function that releases resources for an authenticated channel.

### `pfnCreateCryptoSession`

A pointer to the driver [CreateCryptoSession](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11_1ddi_createcryptosession) function that creates an encryption session.

### `pfnCryptoSessionKeyExchange`

A pointer to the driver [CryptoSessionKeyExchange](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_cryptosessionkeyexchange) function that performs a key exchange during an encryption session.

### `pfnDestroyCryptoSession`

A pointer to the driver [DestroyCryptoSession](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11_1ddi_destroycryptosession) function that releases resources for an encryption session.

### `pfnEncryptionBlt`

A pointer to the driver [EncryptionBlt](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_encryptionblt) function that performs an encrypted bitblt operation.

### `pfnGetPitch`

A pointer to the driver [GetPitch](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_getpitch) function that retrieves the pitch of an encrypted surface.

### `pfnStartSessionKeyRefresh`

A pointer to the driver [StartSessionKeyRefresh](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11_1ddi_startsessionkeyrefresh) function that sets the current video session to protected mode.

### `pfnFinishSessionKeyRefresh`

A pointer to the driver [FinishSessionKeyRefresh](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11_1ddi_finishsessionkeyrefresh) function that sets the current video session to unprotected mode.

### `pfnGetEncryptionBltKey`

A pointer to the driver [GetEncryptionBltKey](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11_1ddi_getencryptionbltkey) function that retrieves the key of an encrypted bitblt session.

### `pfnDecryptionBlt`

A pointer to the driver [DecryptionBlt](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_decryptionblt) function that writes data to a protected surface.

### `pfnResolveSharedResource`

A pointer to the driver [ResolveSharedResource](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_resolvesharedresource) function that resolves a shared resource.

### `pfnVolBlt1`

A pointer to the driver [VolBlt1](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_volblt1) function that performs a volume bit-block transfer (bitblt) operation.

Supported starting with Windows 8.

### `pfnBufBlt1`

A pointer to the driver [BufBlt1](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_bufblt1) function that performs a bit-block transfer (bitblt) operation.

Supported starting with Windows 8.

### `pfnTexBlt1`

A pointer to the driver [TexBlt1](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_texblt1) function that performs a texture bit-block transfer (bitblt) operation.

Supported starting with Windows 8.

### `pfnDiscard`

A pointer to the driver [Discard](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_discard) function that discards (evicts) a set of subresources from video display memory.

Supported starting with Windows 8.

### `pfnOfferResources`

A pointer to the driver [OfferResources](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_offerresources) function that requests that the user-mode display driver offer video memory resources for reuse.

Supported starting with Windows 8.

### `pfnReclaimResources`

A pointer to the driver [ReclaimResources](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_reclaimresources) function that's called by the Direct3D runtime to reclaim video memory resources that it previously offered for reuse.

Supported starting with Windows 8.

### `pfnCheckDirectFlipSupport`

A pointer to the driver [CheckDirectFlipSupport](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_checkdirectflipsupport) function that's called by the DWM to verify that the user-mode driver supports Direct Flip operations.

Supported starting with Windows 8.

### `pfnCreateResource2`

A pointer to the driver [CreateResource2](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_createresource2) function that creates a resource.

Supported starting with Windows 8.

### `pfnCheckMultiPlaneOverlaySupport`

A pointer to the driver [pfnCheckMultiPlaneOverlaySupport (D3D)](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_checkmultiplaneoverlaysupport) function that's called by the Direct3D runtime to check the details on hardware support for multiplane overlays.

Supported starting with Windows 8.1.

### `pfnPresentMultiPlaneOverlay`

A pointer to the driver [pfnPresentMultiplaneOverlay (D3D)](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_presentmultiplaneoverlay) function that's called by the Direct3D runtime to notify the user-mode display driver that an application finished rendering and requests that the driver display the source surface by either copying or flipping or that the driver perform a color-fill operation.

Supported starting with Windows 8.1.

### `pfnReserved1`

Reserved for system use. Do not use in your driver.

Supported starting with Windows 8.1.

### `pfnFlush1`

A pointer to the driver [pfnFlush1](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_flush1) function that's called by the Direct3D runtime to submit outstanding hardware commands that are in the hardware command buffer to the display miniport driver.

Supported starting with Windows 8.1.

### `pfnCheckCounterInfo`

A pointer to the driver [pfnCheckCounterInfo](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_checkcounterinfo) function that's called by the Direct3D runtime to determine global information that's related to manipulating counters.

Supported starting with Windows 8.1.

### `pfnCheckCounter`

A pointer to the driver [pfnCheckCounter](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_checkcounter) function that's called by the Direct3D runtime to retrieve info that describes a counter.

Supported starting with Windows 8.1.

### `pfnUpdateSubresourceUP`

A pointer to the driver [pfnUpdateSubresourceUP](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_updatesubresourceup) function that's called by the Direct3D runtime to update a destination subresource region from a source system-memory region.

Supported starting with Windows 8.1.

### `pfnPresent1`

A pointer to the driver [pfnPresent1(D3D)](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_present1) function that notifies the user-mode display driver that an application finished rendering and that all ownership of the shared resource is released, and that requests that the driver display to the destination surface.

Supported starting with Windows 8.1.

### `pfnCheckPresentDurationSupport`

A pointer to the driver [CheckPresentDurationSupport](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_checkpresentdurationsupport) function that's called by the Direct3D runtime to request that the user-mode display driver get hardware device capabilities for seamlessly switching to a new monitor refresh rate.

Supported starting with Windows 8.1.

### `pfnSetMarker`

A pointer to the driver [pfnSetMarker](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_setmarker) function that notifies the user-mode display driver that it must generate a new time stamp if any GPU work has completed since the last call to *pfnSetMarker*.

Supported starting with Windows 8.1.

### `pfnSetMarkerMode`

A pointer to the driver [pfnSetMarkerMode](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_setmarkermode) function that notifies the user-mode display driver that it should support a type of Event Tracing for Windows (ETW) marker event.

Supported starting with Windows 8.1.

### `pfnTrimResidencySet`

### `pfnAcquireResource`

### `pfnReleaseResource`

## Remarks

The following code, from D3dumddi.h, shows the function declarations for the functions that the members of **D3DDDI_DEVICEFUNCS** point to.

```cpp
typedef _Check_return_ HRESULT (APIENTRY *PFND3DDDI_SETRENDERSTATE)(
        _In_ HANDLE hDevice, _In_ CONST D3DDDIARG_RENDERSTATE*);
typedef _Check_return_ HRESULT (APIENTRY *PFND3DDDI_UPDATEWINFO)(
        _In_ HANDLE hDevice, _In_ CONST D3DDDIARG_WINFO*);
typedef _Check_return_ HRESULT (APIENTRY *PFND3DDDI_VALIDATEDEVICE)(
        _In_ HANDLE hDevice, _Inout_ D3DDDIARG_VALIDATETEXTURESTAGESTATE*);
typedef _Check_return_ HRESULT (APIENTRY *PFND3DDDI_SETTEXTURESTAGESTATE)(
        _In_ HANDLE hDevice, _In_ CONST D3DDDIARG_TEXTURESTAGESTATE*);
typedef _Check_return_ HRESULT (APIENTRY *PFND3DDDI_SETTEXTURE)(
        _In_ HANDLE hDevice, _In_ UINT, _In_ HANDLE);
typedef _Check_return_ HRESULT (APIENTRY *PFND3DDDI_SETPIXELSHADER)(
        _In_ HANDLE hDevice, _In_ HANDLE);
typedef _Check_return_ HRESULT (APIENTRY *PFND3DDDI_SETPIXELSHADERCONST)(
        _In_ HANDLE hDevice, _In_ CONST D3DDDIARG_SETPIXELSHADERCONST*, _In_ CONST FLOAT*);
typedef _Check_return_ HRESULT (APIENTRY *PFND3DDDI_SETSTREAMSOURCEUM)(
        _In_ HANDLE hDevice, _In_ CONST D3DDDIARG_SETSTREAMSOURCEUM*, _In_ CONST VOID*);
typedef _Check_return_ HRESULT (APIENTRY *PFND3DDDI_SETINDICES)(
        _In_ HANDLE hDevice, _In_ CONST D3DDDIARG_SETINDICES*);
typedef _Check_return_ HRESULT (APIENTRY *PFND3DDDI_SETINDICESUM)(
        _In_ HANDLE hDevice, _In_ UINT, _In_ CONST VOID*);
typedef _Check_return_ HRESULT (APIENTRY *PFND3DDDI_DRAWPRIMITIVE)(
        _In_ HANDLE hDevice, _In_ CONST D3DDDIARG_DRAWPRIMITIVE*, _In_opt_ CONST UINT*);
typedef _Check_return_ HRESULT (APIENTRY *PFND3DDDI_DRAWINDEXEDPRIMITIVE)(
        _In_ HANDLE hDevice, _In_ CONST D3DDDIARG_DRAWINDEXEDPRIMITIVE*);
typedef _Check_return_ HRESULT (APIENTRY *PFND3DDDI_DRAWRECTPATCH)(
        _In_ HANDLE hDevice, _In_ CONST D3DDDIARG_DRAWRECTPATCH*, _In_ CONST D3DDDIRECTPATCH_INFO*, _In_ CONST FLOAT*);
typedef _Check_return_ HRESULT (APIENTRY *PFND3DDDI_DRAWTRIPATCH)(
        _In_ HANDLE hDevice, _In_ CONST D3DDDIARG_DRAWTRIPATCH*, _In_ CONST D3DDDITRIPATCH_INFO*, _In_ CONST FLOAT*);
typedef _Check_return_ HRESULT (APIENTRY *PFND3DDDI_DRAWPRIMITIVE2)(
        _In_ HANDLE hDevice, _In_ CONST D3DDDIARG_DRAWPRIMITIVE2*);
typedef _Check_return_ HRESULT (APIENTRY *PFND3DDDI_DRAWINDEXEDPRIMITIVE2)(
        _In_ HANDLE hDevice, _In_ CONST D3DDDIARG_DRAWINDEXEDPRIMITIVE2*, _In_ UINT, _In_ CONST VOID*, _In_opt_ CONST UINT*);
typedef _Check_return_ HRESULT (APIENTRY *PFND3DDDI_VOLBLT)(
        _In_ HANDLE hDevice, _In_ CONST D3DDDIARG_VOLUMEBLT*);
typedef _Check_return_ HRESULT (APIENTRY *PFND3DDDI_BUFBLT)(
        _In_ HANDLE hDevice, _In_ CONST D3DDDIARG_BUFFERBLT*);
typedef _Check_return_ HRESULT (APIENTRY *PFND3DDDI_TEXBLT)(
        _In_ HANDLE hDevice, _In_ CONST D3DDDIARG_TEXBLT*);
typedef _Check_return_ HRESULT (APIENTRY *PFND3DDDI_STATESET)(
        _In_ HANDLE hDevice, _In_ D3DDDIARG_STATESET*);
typedef _Check_return_ HRESULT (APIENTRY *PFND3DDDI_SETPRIORITY)(
        _In_ HANDLE hDevice, _In_ CONST D3DDDIARG_SETPRIORITY*);
typedef _Check_return_ HRESULT (APIENTRY *PFND3DDDI_CLEAR)(
        _In_ HANDLE hDevice, _In_ CONST D3DDDIARG_CLEAR*, _In_ UINT, _In_ CONST RECT*);
typedef _Check_return_ HRESULT (APIENTRY *PFND3DDDI_UPDATEPALETTE)(
        _In_ HANDLE hDevice, _In_ CONST D3DDDIARG_UPDATEPALETTE*, _In_ CONST PALETTEENTRY*);
typedef _Check_return_ HRESULT (APIENTRY *PFND3DDDI_SETPALETTE)(
        _In_ HANDLE hDevice, _In_ CONST D3DDDIARG_SETPALETTE*);
typedef _Check_return_ HRESULT (APIENTRY *PFND3DDDI_SETVERTEXSHADERCONST)(
        _In_ HANDLE hDevice, _In_ CONST D3DDDIARG_SETVERTEXSHADERCONST*, _In_ CONST VOID*);
typedef _Check_return_ HRESULT (APIENTRY *PFND3DDDI_MULTIPLYTRANSFORM)(
        _In_ HANDLE hDevice, _In_ CONST D3DDDIARG_MULTIPLYTRANSFORM*);
typedef _Check_return_ HRESULT (APIENTRY *PFND3DDDI_SETTRANSFORM)(
        _In_ HANDLE hDevice, _In_ CONST D3DDDIARG_SETTRANSFORM*);
typedef _Check_return_ HRESULT (APIENTRY *PFND3DDDI_SETVIEWPORT)(
        _In_ HANDLE hDevice, _In_ CONST D3DDDIARG_VIEWPORTINFO*);
typedef _Check_return_ HRESULT (APIENTRY *PFND3DDDI_SETZRANGE)(
        _In_ HANDLE hDevice, _In_ CONST D3DDDIARG_ZRANGE*);
typedef _Check_return_ HRESULT (APIENTRY *PFND3DDDI_SETMATERIAL)(
        _In_ HANDLE hDevice, _In_ CONST D3DDDIARG_SETMATERIAL*);
typedef _Check_return_ HRESULT (APIENTRY *PFND3DDDI_SETLIGHT)(
        _In_ HANDLE hDevice, _In_ CONST D3DDDIARG_SETLIGHT*, _In_ CONST D3DDDI_LIGHT*);
typedef _Check_return_ HRESULT (APIENTRY *PFND3DDDI_CREATELIGHT)(
        _In_ HANDLE hDevice, _In_ CONST D3DDDIARG_CREATELIGHT*);
typedef _Check_return_ HRESULT (APIENTRY *PFND3DDDI_DESTROYLIGHT)(
        _In_ HANDLE hDevice, _In_ CONST D3DDDIARG_DESTROYLIGHT*);
typedef _Check_return_ HRESULT (APIENTRY *PFND3DDDI_SETCLIPPLANE)(
        _In_ HANDLE hDevice, _In_ CONST D3DDDIARG_SETCLIPPLANE*);
typedef _Check_return_ HRESULT (APIENTRY *PFND3DDDI_GETINFO)(
        _In_ HANDLE hDevice, _In_ UINT, _Out_writes_bytes_(DevInfoSize)VOID*, _In_ UINT DevInfoSize);
typedef _Check_return_ HRESULT (APIENTRY *PFND3DDDI_LOCK)(
        _In_ HANDLE hDevice, _Inout_ D3DDDIARG_LOCK*);
typedef _Check_return_ HRESULT (APIENTRY *PFND3DDDI_UNLOCK)(
        _In_ HANDLE hDevice, _In_ CONST D3DDDIARG_UNLOCK*);
typedef _Check_return_ HRESULT (APIENTRY *PFND3DDDI_LOCKASYNC)(
        _In_ HANDLE hDevice, _Inout_ D3DDDIARG_LOCKASYNC*);
typedef _Check_return_ HRESULT (APIENTRY *PFND3DDDI_UNLOCKASYNC)(
        _In_ HANDLE hDevice, _In_ CONST D3DDDIARG_UNLOCKASYNC*);
typedef _Check_return_ HRESULT (APIENTRY *PFND3DDDI_RENAME)(
        _In_ HANDLE hDevice, _In_ CONST D3DDDIARG_RENAME*);
typedef _Check_return_ HRESULT (APIENTRY *PFND3DDDI_CREATERESOURCE)(
        _In_ HANDLE hDevice, _Inout_ D3DDDIARG_CREATERESOURCE*);
typedef _Check_return_ HRESULT (APIENTRY *PFND3DDDI_DESTROYRESOURCE)(
        _In_ HANDLE hDevice, _In_ HANDLE);
typedef _Check_return_ HRESULT (APIENTRY *PFND3DDDI_SETDISPLAYMODE)(
        _In_ HANDLE hDevice, _In_ CONST D3DDDIARG_SETDISPLAYMODE*);
typedef _Check_return_ HRESULT (APIENTRY *PFND3DDDI_PRESENT)(
        _In_ HANDLE hDevice, _In_ CONST D3DDDIARG_PRESENT*);
typedef _Check_return_ HRESULT (APIENTRY *PFND3DDDI_FLUSH)(
        _In_ HANDLE hDevice);
typedef _Check_return_ HRESULT (APIENTRY *PFND3DDDI_CREATEVERTEXSHADERDECL)(
        _In_ HANDLE hDevice, _Inout_ D3DDDIARG_CREATEVERTEXSHADERDECL*, _In_ CONST D3DDDIVERTEXELEMENT*);
typedef _Check_return_ HRESULT (APIENTRY *PFND3DDDI_SETVERTEXSHADERDECL)(
        _In_ HANDLE hDevice, _In_ HANDLE);
typedef _Check_return_ HRESULT (APIENTRY *PFND3DDDI_DELETEVERTEXSHADERDECL)(
        _In_ HANDLE hDevice, _In_ HANDLE);
typedef _Check_return_ HRESULT (APIENTRY *PFND3DDDI_CREATEVERTEXSHADERFUNC)(
        _In_ HANDLE hDevice, _Inout_ D3DDDIARG_CREATEVERTEXSHADERFUNC*, _In_ CONST UINT*);
typedef _Check_return_ HRESULT (APIENTRY *PFND3DDDI_SETVERTEXSHADERFUNC)(
        _In_ HANDLE hDevice, _In_ HANDLE);
typedef _In_ HRESULT (APIENTRY *PFND3DDDI_DELETEVERTEXSHADERFUNC)(
        _In_ HANDLE hDevice, _In_ HANDLE);
typedef _Check_return_ HRESULT (APIENTRY *PFND3DDDI_SETVERTEXSHADERCONSTI)(
        _In_ HANDLE hDevice, _In_ CONST D3DDDIARG_SETVERTEXSHADERCONSTI*, _In_ CONST INT*);
typedef _Check_return_ HRESULT (APIENTRY *PFND3DDDI_SETVERTEXSHADERCONSTB)(
        _In_ HANDLE hDevice, _In_ CONST D3DDDIARG_SETVERTEXSHADERCONSTB*, _In_ CONST BOOL*);
typedef _Check_return_ HRESULT (APIENTRY *PFND3DDDI_SETSCISSORRECT)(
        _In_ HANDLE hDevice, _In_ CONST RECT*);
typedef _Check_return_ HRESULT (APIENTRY *PFND3DDDI_SETSTREAMSOURCE)(
        _In_ HANDLE hDevice, _In_ CONST D3DDDIARG_SETSTREAMSOURCE*);
typedef _Check_return_ HRESULT (APIENTRY *PFND3DDDI_SETSTREAMSOURCEFREQ)(
        _In_ HANDLE hDevice, _In_ CONST D3DDDIARG_SETSTREAMSOURCEFREQ*);
typedef _Check_return_ HRESULT (APIENTRY *PFND3DDDI_SETCONVOLUTIONKERNELMONO)(
        _In_ HANDLE hDevice, _In_ CONST D3DDDIARG_SETCONVOLUTIONKERNELMONO*);
typedef _Check_return_ HRESULT (APIENTRY *PFND3DDDI_COMPOSERECTS)(
        _In_ HANDLE hDevice, _In_ CONST D3DDDIARG_COMPOSERECTS*);
typedef _Check_return_ HRESULT (APIENTRY *PFND3DDDI_BLT)(
        _In_ HANDLE hDevice, _In_ CONST D3DDDIARG_BLT*);
typedef _Check_return_ HRESULT (APIENTRY *PFND3DDDI_COLORFILL)(
        _In_ HANDLE hDevice, _In_ CONST D3DDDIARG_COLORFILL*);
typedef _Check_return_ HRESULT (APIENTRY *PFND3DDDI_DEPTHFILL)(
        _In_ HANDLE hDevice, _In_ CONST D3DDDIARG_DEPTHFILL*);
typedef _Check_return_ HRESULT (APIENTRY *PFND3DDDI_CREATEQUERY)(
        _In_ HANDLE hDevice, _Inout_ D3DDDIARG_CREATEQUERY*);
typedef _Check_return_ HRESULT (APIENTRY *PFND3DDDI_DESTROYQUERY)(
        _In_ HANDLE hDevice, _In_ CONST HANDLE);
typedef _Check_return_ HRESULT (APIENTRY *PFND3DDDI_ISSUEQUERY)(
        _In_ HANDLE hDevice, _In_ CONST D3DDDIARG_ISSUEQUERY*);
typedef _Check_return_ HRESULT (APIENTRY *PFND3DDDI_GETQUERYDATA)(
        _In_ HANDLE hDevice, _Inout_ CONST D3DDDIARG_GETQUERYDATA*);
typedef _Check_return_ HRESULT (APIENTRY *PFND3DDDI_SETRENDERTARGET)(
        _In_ HANDLE hDevice, _In_ CONST D3DDDIARG_SETRENDERTARGET*);
typedef _Check_return_ HRESULT (APIENTRY *PFND3DDDI_SETDEPTHSTENCIL)(
        _In_ HANDLE hDevice, _In_ CONST D3DDDIARG_SETDEPTHSTENCIL*);
typedef _Check_return_ HRESULT (APIENTRY *PFND3DDDI_GENERATEMIPSUBLEVELS)(
        _In_ HANDLE hDevice, _In_ CONST D3DDDIARG_GENERATEMIPSUBLEVELS*);
typedef _Check_return_ HRESULT (APIENTRY *PFND3DDDI_SETPIXELSHADERCONSTI)(
        _In_ HANDLE hDevice, _In_ CONST D3DDDIARG_SETPIXELSHADERCONSTI*, _In_ CONST INT*);
typedef _Check_return_ HRESULT (APIENTRY *PFND3DDDI_SETPIXELSHADERCONSTB)(
        _In_ HANDLE hDevice, _In_ CONST D3DDDIARG_SETPIXELSHADERCONSTB*, _In_ CONST BOOL*);
typedef _Check_return_ HRESULT (APIENTRY *PFND3DDDI_CREATEPIXELSHADER)(
        _In_ HANDLE hDevice, _Inout_ D3DDDIARG_CREATEPIXELSHADER*, _In_ CONST UINT*);
typedef _Check_return_ HRESULT (APIENTRY *PFND3DDDI_DELETEPIXELSHADER)(
        _In_ HANDLE hDevice, _In_ HANDLE);
typedef _Check_return_ HRESULT (APIENTRY *PFND3DDDI_CREATEDECODEDEVICE)(
        _In_ HANDLE hDevice, _Inout_ D3DDDIARG_CREATEDECODEDEVICE*);
typedef _Check_return_ HRESULT (APIENTRY *PFND3DDDI_DESTROYDECODEDEVICE)(
        _In_ HANDLE hDevice, _In_ HANDLE);
typedef _Check_return_ HRESULT (APIENTRY *PFND3DDDI_SETDECODERENDERTARGET) (
        _In_ HANDLE hDevice, _In_ CONST D3DDDIARG_SETDECODERENDERTARGET*);
typedef _Check_return_ HRESULT (APIENTRY *PFND3DDDI_DECODEBEGINFRAME) (
        _In_ HANDLE hDevice, _In_ D3DDDIARG_DECODEBEGINFRAME*);
typedef _Check_return_ HRESULT (APIENTRY *PFND3DDDI_DECODEENDFRAME) (
        _In_ HANDLE hDevice, _Inout_ D3DDDIARG_DECODEENDFRAME*);
typedef _Check_return_ HRESULT (APIENTRY *PFND3DDDI_DECODEEXECUTE)(
        _In_ HANDLE hDevice, _In_ CONST D3DDDIARG_DECODEEXECUTE*);
typedef _Check_return_ HRESULT (APIENTRY *PFND3DDDI_DECODEEXTENSIONEXECUTE)(
        _In_ HANDLE hDevice, _Inout_ CONST D3DDDIARG_DECODEEXTENSIONEXECUTE*);
typedef _Check_return_ HRESULT (APIENTRY *PFND3DDDI_CREATEVIDEOPROCESSDEVICE) (
        _In_ HANDLE hDevice, _Inout_ D3DDDIARG_CREATEVIDEOPROCESSDEVICE*);
typedef _Check_return_ HRESULT (APIENTRY *PFND3DDDI_DESTROYVIDEOPROCESSDEVICE) (
        _In_ HANDLE hDevice, _In_ HANDLE hVideoProcessor);
typedef _Check_return_ HRESULT (APIENTRY *PFND3DDDI_VIDEOPROCESSBEGINFRAME) (
        _In_ HANDLE hDevice, _In_ HANDLE hVideoProcess);
typedef _Check_return_ HRESULT (APIENTRY *PFND3DDDI_VIDEOPROCESSENDFRAME) (
        _In_ HANDLE hDevice, _Inout_ D3DDDIARG_VIDEOPROCESSENDFRAME*);
typedef _Check_return_ HRESULT (APIENTRY *PFND3DDDI_SETVIDEOPROCESSRENDERTARGET) (
        _In_ HANDLE hDevice, _In_ CONST D3DDDIARG_SETVIDEOPROCESSRENDERTARGET*);
typedef _Check_return_ HRESULT (APIENTRY *PFND3DDDI_VIDEOPROCESSBLT) (
        _In_ HANDLE hDevice, _In_ CONST D3DDDIARG_VIDEOPROCESSBLT*);
typedef _Check_return_ HRESULT (APIENTRY *PFND3DDDI_CREATEEXTENSIONDEVICE) (
        _In_ HANDLE hDevice, _Inout_ D3DDDIARG_CREATEEXTENSIONDEVICE*);
typedef _Check_return_ HRESULT (APIENTRY *PFND3DDDI_DESTROYEXTENSIONDEVICE) (
        _In_ HANDLE hDevice, _In_ HANDLE hExtension);
typedef _Check_return_ HRESULT (APIENTRY *PFND3DDDI_EXTENSIONEXECUTE) (
        _In_ HANDLE hDevice, _In_ CONST D3DDDIARG_EXTENSIONEXECUTE*);
typedef _Check_return_ HRESULT (APIENTRY *PFND3DDDI_DESTROYDEVICE)(
        _In_ HANDLE hDevice);
typedef _Check_return_ HRESULT (APIENTRY *PFND3DDDI_CREATEOVERLAY) (
        _In_ HANDLE hDevice, _Inout_ D3DDDIARG_CREATEOVERLAY*);
typedef _Check_return_ HRESULT (APIENTRY *PFND3DDDI_UPDATEOVERLAY) (
        _In_ HANDLE hDevice, _In_ CONST D3DDDIARG_UPDATEOVERLAY*);
typedef _Check_return_ HRESULT (APIENTRY *PFND3DDDI_FLIPOVERLAY) (
        _In_ HANDLE hDevice, _In_ CONST D3DDDIARG_FLIPOVERLAY*);
typedef _Check_return_ HRESULT (APIENTRY *PFND3DDDI_GETOVERLAYCOLORCONTROLS) (
        _In_ HANDLE hDevice, _Inout_ D3DDDIARG_GETOVERLAYCOLORCONTROLS*);
typedef _Check_return_ HRESULT (APIENTRY *PFND3DDDI_SETOVERLAYCOLORCONTROLS) (
        _In_ HANDLE hDevice, _In_ CONST D3DDDIARG_SETOVERLAYCOLORCONTROLS*);
typedef _Check_return_ HRESULT (APIENTRY *PFND3DDDI_DESTROYOVERLAY) (
        _In_ HANDLE hDevice, _In_ CONST D3DDDIARG_DESTROYOVERLAY*);
typedef _Check_return_ HRESULT (APIENTRY *PFND3DDDI_QUERYRESOURCERESIDENCY) (
        _In_ HANDLE hDevice, _In_ CONST D3DDDIARG_QUERYRESOURCERESIDENCY*);
typedef _Check_return_ HRESULT (APIENTRY *PFND3DDDI_OPENRESOURCE) (
        _In_ HANDLE hDevice, _Inout_ D3DDDIARG_OPENRESOURCE*);
typedef _Check_return_ HRESULT (APIENTRY *PFND3DDDI_GETCAPTUREALLOCATIONHANDLE)(
        _In_ HANDLE hDevice, _Inout_ D3DDDIARG_GETCAPTUREALLOCATIONHANDLE*);
typedef _Check_return_ HRESULT (APIENTRY *PFND3DDDI_CAPTURETOSYSMEM)(
        _In_ HANDLE hDevice, _In_ CONST D3DDDIARG_CAPTURETOSYSMEM*);
typedef _Check_return_ HRESULT (APIENTRY *PFND3DDDI_DXVAHD_CREATEVIDEOPROCESSOR)(
        _In_ HANDLE, _Inout_ D3DDDIARG_DXVAHD_CREATEVIDEOPROCESSOR*);
typedef _Check_return_ HRESULT (APIENTRY *PFND3DDDI_DXVAHD_SETVIDEOPROCESSBLTSTATE)(
        _In_ HANDLE, _In_ CONST D3DDDIARG_DXVAHD_SETVIDEOPROCESSBLTSTATE*);
typedef _Check_return_ HRESULT (APIENTRY *PFND3DDDI_DXVAHD_GETVIDEOPROCESSBLTSTATEPRIVATE)(
        _In_ HANDLE, _Inout_ D3DDDIARG_DXVAHD_GETVIDEOPROCESSBLTSTATEPRIVATE*);
typedef _Check_return_ HRESULT (APIENTRY *PFND3DDDI_DXVAHD_SETVIDEOPROCESSSTREAMSTATE)(
        _In_ HANDLE, _In_ CONST D3DDDIARG_DXVAHD_SETVIDEOPROCESSSTREAMSTATE*);
typedef _Check_return_ HRESULT (APIENTRY *PFND3DDDI_DXVAHD_GETVIDEOPROCESSSTREAMSTATEPRIVATE)(
        _In_ HANDLE, _Inout_ D3DDDIARG_DXVAHD_GETVIDEOPROCESSSTREAMSTATEPRIVATE*);
typedef _Check_return_ HRESULT (APIENTRY *PFND3DDDI_DXVAHD_VIDEOPROCESSBLTHD)(
        _In_ HANDLE, _In_ CONST D3DDDIARG_DXVAHD_VIDEOPROCESSBLTHD*);
typedef _Check_return_ HRESULT (APIENTRY *PFND3DDDI_DXVAHD_DESTROYVIDEOPROCESSOR)(
        _In_ HANDLE, _In_ HANDLE);
typedef _Check_return_ HRESULT (APIENTRY *PFND3DDDI_CREATEAUTHENTICATEDCHANNEL)(
        _In_ HANDLE hDevice, _Inout_ D3DDDIARG_CREATEAUTHENTICATEDCHANNEL*);
typedef _Check_return_ HRESULT (APIENTRY *PFND3DDDI_AUTHENTICATEDCHANNELKEYEXCHANGE)(
        _In_ HANDLE hDevice, _Inout_ D3DDDIARG_AUTHENTICATEDCHANNELKEYEXCHANGE*);
typedef _Check_return_ HRESULT (APIENTRY *PFND3DDDI_QUERYAUTHENTICATEDCHANNEL)(
        _In_ HANDLE hDevice, _Inout_ CONST D3DDDIARG_QUERYAUTHENTICATEDCHANNEL*);
typedef _Check_return_ HRESULT (APIENTRY *PFND3DDDI_CONFIGUREAUTHENICATEDCHANNEL)(
        _In_ HANDLE hDevice, _Inout_ CONST D3DDDIARG_CONFIGUREAUTHENTICATEDCHANNEL*);
typedef _Check_return_ HRESULT (APIENTRY *PFND3DDDI_DESTROYAUTHENTICATEDCHANNEL)(
        _In_ HANDLE hDevice, _In_ CONST D3DDDIARG_DESTROYAUTHENTICATEDCHANNEL*);
typedef _Check_return_ HRESULT (APIENTRY *PFND3DDDI_CREATECRYPTOSESSION)(
        _In_ HANDLE hDevice, _Inout_ D3DDDIARG_CREATECRYPTOSESSION*);
typedef _Check_return_ HRESULT (APIENTRY *PFND3DDDI_CRYPTOSESSIONKEYEXCHANGE)(
        _In_ HANDLE hDevice, _Inout_ D3DDDIARG_CRYPTOSESSIONKEYEXCHANGE*);
typedef _Check_return_ HRESULT (APIENTRY *PFND3DDDI_DESTROYCRYPTOSESSION)(
        _In_ HANDLE hDevice, _In_ CONST D3DDDIARG_DESTROYCRYPTOSESSION*);
typedef _Check_return_ HRESULT (APIENTRY *PFND3DDDI_ENCRYPTIONBLT)(
        _In_ HANDLE hDevice, _In_ CONST D3DDDIARG_ENCRYPTIONBLT*);
typedef _Check_return_ HRESULT (APIENTRY *PFND3DDDI_GETPITCH)(
        _In_ HANDLE hDevice, _Inout_ D3DDDIARG_GETPITCH*);
typedef _Check_return_ HRESULT (APIENTRY *PFND3DDDI_STARTSESSIONKEYREFRESH)(
        _In_ HANDLE hDevice, _Inout_ CONST D3DDDIARG_STARTSESSIONKEYREFRESH*);
typedef _Check_return_ HRESULT (APIENTRY *PFND3DDDI_FINISHSESSIONKEYREFRESH)(
        _In_ HANDLE hDevice, _In_ CONST D3DDDIARG_FINISHSESSIONKEYREFRESH*);
typedef _Check_return_ HRESULT (APIENTRY *PFND3DDDI_GETENCRYPTIONBLTKEY)(
        _In_ HANDLE hDevice, _Inout_ CONST D3DDDIARG_GETENCRYPTIONBLTKEY*);
typedef _Check_return_ HRESULT (APIENTRY *PFND3DDDI_DECRYPTIONBLT)(
        _In_ HANDLE hDevice, _In_ CONST D3DDDIARG_DECRYPTIONBLT*);
typedef _Check_return_ HRESULT (APIENTRY *PFND3DDDI_RESOLVESHAREDRESOURCE)(
        _In_ HANDLE hDevice, _In_ CONST D3DDDIARG_RESOLVESHAREDRESOURCE*);
#if (D3D_UMD_INTERFACE_VERSION >= D3D_UMD_INTERFACE_VERSION_WIN8)
typedef _Check_return_ HRESULT (APIENTRY *PFND3DDDI_VOLBLT1)(
        _In_ HANDLE hDevice, _In_ CONST D3DDDIARG_VOLUMEBLT1*);
typedef _Check_return_ HRESULT (APIENTRY *PFND3DDDI_BUFBLT1)(
        _In_ HANDLE hDevice, _In_ CONST D3DDDIARG_BUFFERBLT1*);
typedef _Check_return_ HRESULT (APIENTRY *PFND3DDDI_TEXBLT1)(
        _In_ HANDLE hDevice, _In_ CONST D3DDDIARG_TEXBLT1*);
typedef _Check_return_ HRESULT (APIENTRY *PFND3DDDI_DISCARD)(
        _In_ HANDLE hDevice, _In_ CONST D3DDDIARG_DISCARD*);
typedef _Check_return_ HRESULT (APIENTRY *PFND3DDDI_OFFERRESOURCES)(
        _In_ HANDLE hDevice, _In_ CONST D3DDDIARG_OFFERRESOURCES*);
typedef _Check_return_ HRESULT (APIENTRY *PFND3DDDI_RECLAIMRESOURCES)(
        _In_ HANDLE hDevice, _Inout_ CONST D3DDDIARG_RECLAIMRESOURCES*);
typedef _Check_return_ HRESULT (APIENTRY *PFND3DDDI_CHECKDIRECTFLIPSUPPORT)(
        _In_ HANDLE hDevice, _Inout_ D3DDDIARG_CHECKDIRECTFLIPSUPPORT*);
typedef _Check_return_ HRESULT (APIENTRY *PFND3DDDI_CREATERESOURCE2)(
        _In_ HANDLE hDevice, _Inout_ D3DDDIARG_CREATERESOURCE2*);
typedef _Check_return_ HRESULT (APIENTRY *PFND3DDDI_CHECKMULTIPLANEOVERLAYSUPPORT)(
        _In_ HANDLE hDevice, _Inout_ D3DDDIARG_CHECKMULTIPLANEOVERLAYSUPPORT*);
typedef _Check_return_ HRESULT (APIENTRY *PFND3DDDI_PRESENTMULTIPLANEOVERLAY)(
        _In_ HANDLE hDevice, _In_ CONST D3DDDIARG_PRESENTMULTIPLANEOVERLAY*);
#if (D3D_UMD_INTERFACE_VERSION >= D3D_UMD_INTERFACE_VERSION_WDDM1_3)
typedef _Check_return_ HRESULT (APIENTRY *PFND3DDDI_FLUSH1)(
        _In_ HANDLE hDevice, UINT /*D3DDDI_FLUSH_FLAGS*/ FlushFlags);
typedef VOID ( APIENTRY* PFND3DDDI_CHECKCOUNTERINFO )(
        _In_ HANDLE hDevice, _Out_ D3DDDIARG_COUNTER_INFO* );
typedef _Check_return_ HRESULT ( APIENTRY* PFND3DDDI_CHECKCOUNTER )(
        _In_ HANDLE hDevice, _In_ D3DDDIQUERYTYPE, _Out_ D3DDDI_COUNTER_TYPE*, _Out_ UINT*,
        _Out_writes_to_opt_(*pNameLength, *pNameLength) LPSTR,
        _Inout_opt_ UINT* pNameLength,
        _Out_writes_to_opt_(*pUnitsLength, *pUnitsLength) LPSTR,
        _Inout_opt_ UINT* pUnitsLength,
        _Out_writes_to_opt_(*pDescriptionLength, *pDescriptionLength) LPSTR,
        _Inout_opt_ UINT* pDescriptionLength);
typedef _Check_return_ HRESULT (APIENTRY *PFND3DDDI_UPDATESUBRESOURCEUP)(
        _In_ HANDLE hDevice, _In_ CONST D3DDDIARG_UPDATESUBRESOURCEUP*);
typedef _Check_return_ HRESULT (APIENTRY *PFND3DDDI_PRESENT1)(
        _In_ HANDLE hDevice, _In_ CONST D3DDDIARG_PRESENT1*);
typedef _Check_return_ HRESULT (APIENTRY *PFND3DDDI_CHECKPRESENTDURATIONSUPPORT)(
        _In_ HANDLE hDevice, _In_ D3DDDIARG_CHECKPRESENTDURATIONSUPPORT*);
#endif // D3D_UMD_INTERFACE_VERSION
#if (D3D_UMD_INTERFACE_VERSION >= D3D_UMD_INTERFACE_VERSION_WDDM1_3)
typedef _Check_return_ HRESULT (APIENTRY *PFND3DDDI_SETMARKERMODE)(
        _In_ HANDLE hDevice, _In_ D3DDDI_MARKERTYPE Type, /*D3DDDI_SETMARKERMODE*/ UINT Flags );
typedef _Check_return_ HRESULT (APIENTRY *PFND3DDDI_SETMARKER)(
        _In_ HANDLE hDevice);
#endif // D3D_UMD_INTERFACE_VERSION
```

## See also

[CreateDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_createdevice)

[D3DDDIARG_CREATEDEVICE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddiarg_createdevice)