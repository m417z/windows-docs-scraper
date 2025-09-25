# ID3D11ShaderTrace::PSSelectStamp

## Description

Sets the specified pixel-shader stamp.

## Parameters

### `stampIndex` [in]

The index of the stamp to select.

## Return value

**PSSelectStamp** returns:

* **S_OK** if the method set the pixel-shader stamp, and if the primitive covers the pixel and sample for the stamp.
* **S_FALSE** if the method set the pixel-shader stamp, and if the invocation for the selected stamp falls off the primitive.
* **E_FAIL** if you called the method for a vertex shader or geometry shader; **PSSelectStamp** is meaningful only for pixel shaders.
* **E_INVALIDARG** if *stampIndex* is out of range [0..3].
* Possibly other error codes that are described in [Direct3D 11 Return Codes](https://learn.microsoft.com/windows/desktop/direct3d11/d3d11-graphics-reference-returnvalues).

## Remarks

After you call **PSSelectStamp** to set the pixel-shader stamp, you can call the [ID3D11ShaderTrace::GetInitialRegisterContents](https://learn.microsoft.com/windows/desktop/api/d3d11shadertracing/nf-d3d11shadertracing-id3d11shadertrace-getinitialregistercontents), [ID3D11ShaderTrace::GetStep](https://learn.microsoft.com/windows/desktop/api/d3d11shadertracing/nf-d3d11shadertracing-id3d11shadertrace-getstep), [ID3D11ShaderTrace::GetWrittenRegister](https://learn.microsoft.com/windows/desktop/api/d3d11shadertracing/nf-d3d11shadertracing-id3d11shadertrace-getwrittenregister), and [ID3D11ShaderTrace::GetReadRegister](https://learn.microsoft.com/windows/desktop/api/d3d11shadertracing/nf-d3d11shadertracing-id3d11shadertrace-getreadregister) methods to get trace data for that stamp.

**Note** This API requires the Windows Software Development Kit (SDK) for Windows 8.

## See also

[ID3D11ShaderTrace](https://learn.microsoft.com/windows/desktop/api/d3d11shadertracing/nn-d3d11shadertracing-id3d11shadertrace)