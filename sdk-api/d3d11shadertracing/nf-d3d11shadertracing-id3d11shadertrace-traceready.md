# ID3D11ShaderTrace::TraceReady

## Description

Specifies that the shader trace recorded and is ready to use.

## Parameters

### `pTestCount` [out, optional]

An optional pointer to a variable that receives the number of times that a matching invocation for the trace occurred. If not used, set to NULL.
For more information about this number, see Remarks.

## Return value

**TraceReady** returns:

* **S_OK** if the trace is ready.
* **S_FALSE** if the trace is not ready.
* **E_OUTOFMEMORY** if memory ran out while the trace was in the process of recording. You can try to record the trace again by calling [ID3D11ShaderTrace::ResetTrace](https://learn.microsoft.com/windows/desktop/api/d3d11shadertracing/nf-d3d11shadertracing-id3d11shadertrace-resettrace) and then redrawing. If you decide not to record the trace again, release the [ID3D11ShaderTrace](https://learn.microsoft.com/windows/desktop/api/d3d11shadertracing/nn-d3d11shadertracing-id3d11shadertrace) interface.
* Possibly other error codes that are described in [Direct3D 11 Return Codes](https://learn.microsoft.com/windows/desktop/direct3d11/d3d11-graphics-reference-returnvalues).

## Remarks

If a trace is meant to record invocation 3 but only two invocations have happened so far, **TraceReady** sets the variable to which *pTestCount* points to 2. You can use this value to understand why a trace is not ready yet. Conversely, the variable to which *pTestCount* points might be larger than the requested invocation count for a trace that is ready. You can use this value to determine the number of invocations that ran past the required trace invocation count. For example, you might not know the number of overdraws that occur on a pixel for a given shader in a draw call. If you can redraw the scene identically, you can set up the traces this next time based on the value that **TraceReady** returned at *pTestCount* on the first pass.

If the shader trace recorded, you can successfully call the [ID3D11ShaderTrace::GetTraceStats](https://learn.microsoft.com/windows/desktop/api/d3d11shadertracing/nf-d3d11shadertracing-id3d11shadertrace-gettracestats), [ID3D11ShaderTrace::GetInitialRegisterContents](https://learn.microsoft.com/windows/desktop/api/d3d11shadertracing/nf-d3d11shadertracing-id3d11shadertrace-getinitialregistercontents), and [ID3D11ShaderTrace::GetStep](https://learn.microsoft.com/windows/desktop/api/d3d11shadertracing/nf-d3d11shadertracing-id3d11shadertrace-getstep) methods. You can call the [ID3D11ShaderTrace::ResetTrace](https://learn.microsoft.com/windows/desktop/api/d3d11shadertracing/nf-d3d11shadertracing-id3d11shadertrace-resettrace) and [ID3D11ShaderTrace::PSSelectStamp](https://learn.microsoft.com/windows/desktop/api/d3d11shadertracing/nf-d3d11shadertracing-id3d11shadertrace-psselectstamp) methods regardless of whether the shader trace recorded.

**Note** This API requires the Windows Software Development Kit (SDK) for Windows 8.

## See also

[ID3D11ShaderTrace](https://learn.microsoft.com/windows/desktop/api/d3d11shadertracing/nn-d3d11shadertracing-id3d11shadertrace)