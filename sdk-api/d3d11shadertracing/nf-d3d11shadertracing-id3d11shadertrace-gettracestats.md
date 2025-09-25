# ID3D11ShaderTrace::GetTraceStats

## Description

Returns statistics about the trace.

## Parameters

### `pTraceStats` [out]

A pointer to a [D3D11_TRACE_STATS](https://learn.microsoft.com/windows/desktop/api/d3d11shadertracing/ns-d3d11shadertracing-d3d11_trace_stats) structure. **GetTraceStats** fills the members of this structure with statistics about the trace.

## Return value

**GetTraceStats** returns:

* S_OK if statistics about the trace are successfully obtained.
* E_FAIL if no trace statistics are available yet; [ID3D11ShaderTrace::TraceReady](https://learn.microsoft.com/windows/desktop/api/d3d11shadertracing/nf-d3d11shadertracing-id3d11shadertrace-traceready) must return S_OK before **GetTraceStats** can succeed.
* E_INVALIDARG if *pTraceStats* is NULL.
* Possibly other error codes that are described in [Direct3D 11 Return Codes](https://learn.microsoft.com/windows/desktop/direct3d11/d3d11-graphics-reference-returnvalues).

## Remarks

This API requires the Windows Software Development Kit (SDK) for Windows 8.

## See also

[ID3D11ShaderTrace](https://learn.microsoft.com/windows/desktop/api/d3d11shadertracing/nn-d3d11shadertracing-id3d11shadertrace)