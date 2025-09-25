# ID3D11ShaderTrace::GetWrittenRegister

## Description

Retrieves information about a register that was written by a step in the trace.

## Parameters

### `stepIndex` [in]

The index of the step within the trace. The range of the index is [0...NumTraceSteps-1], where **NumTraceSteps** is a member of the [D3D11_TRACE_STATS](https://learn.microsoft.com/windows/desktop/api/d3d11shadertracing/ns-d3d11shadertracing-d3d11_trace_stats) structure. You can retrieve information in any step order.

### `writtenRegisterIndex` [in]

The index of the register within the trace step. The range of the index is [0...NumRegistersWritten-1], where **NumRegistersWritten** is a member of the [D3D11_TRACE_STEP](https://learn.microsoft.com/windows/desktop/api/d3d11shadertracing/ns-d3d11shadertracing-d3d11_trace_step) structure.

### `pRegister` [out]

A pointer to a [D3D11_TRACE_REGISTER](https://learn.microsoft.com/windows/desktop/api/d3d11shadertracing/ns-d3d11shadertracing-d3d11_trace_register) structure. **GetWrittenRegister** fills the members of this structure with information about the register that was written by the step in the trace.

### `pValue` [out]

A pointer to a [D3D11_TRACE_VALUE](https://learn.microsoft.com/windows/desktop/api/d3d11shadertracing/ns-d3d11shadertracing-d3d11_trace_value) structure. **GetWrittenRegister** fills the members of this structure with information about the value that was written to the register.

## Return value

**GetWrittenRegister** returns:

* **S_OK** if the method retrieves the register information.
* **E_FAIL** if a trace is not available or if the trace was not created with the D3D11_SHADER_TRACE_FLAG_RECORD_REGISTER_WRITES flag.
* **E_INVALIDARG** if *stepIndex* or *writtenRegisterIndex* is out of range or if *pRegister* or *pValue* is NULL.
* Possibly other error codes that are described in [Direct3D 11 Return Codes](https://learn.microsoft.com/windows/desktop/direct3d11/d3d11-graphics-reference-returnvalues).

## Remarks

This API requires the Windows Software Development Kit (SDK) for Windows 8.

## See also

[ID3D11ShaderTrace](https://learn.microsoft.com/windows/desktop/api/d3d11shadertracing/nn-d3d11shadertracing-id3d11shadertrace)