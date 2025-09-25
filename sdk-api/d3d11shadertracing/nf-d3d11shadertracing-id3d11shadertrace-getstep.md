# ID3D11ShaderTrace::GetStep

## Description

Retrieves information about the specified step in the trace.

## Parameters

### `stepIndex` [in]

The index of the step within the trace. The range of the index is [0...NumTraceSteps-1], where **NumTraceSteps** is a member of the [D3D11_TRACE_STATS](https://learn.microsoft.com/windows/desktop/api/d3d11shadertracing/ns-d3d11shadertracing-d3d11_trace_stats) structure. You can retrieve information about a step in any step order.

### `pTraceStep` [out]

A pointer to a [D3D11_TRACE_STEP](https://learn.microsoft.com/windows/desktop/api/d3d11shadertracing/ns-d3d11shadertracing-d3d11_trace_step) structure. **GetStep** fills the members of this structure with information about the trace step that is specified by the *stepIndex* parameter.

## Return value

**GetStep** returns:

* **S_OK** if the method retrieves the step information.
* **E_FAIL** if a trace is not available.
* **E_INVALIDARG** if *stepIndex* is out of range or if *pTraceStep* is NULL.
* Possibly other error codes that are described in [Direct3D 11 Return Codes](https://learn.microsoft.com/windows/desktop/direct3d11/d3d11-graphics-reference-returnvalues).

## Remarks

This API requires the Windows Software Development Kit (SDK) for Windows 8.

## See also

[ID3D11ShaderTrace](https://learn.microsoft.com/windows/desktop/api/d3d11shadertracing/nn-d3d11shadertracing-id3d11shadertrace)