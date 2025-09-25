# ID3D11ShaderTrace::ResetTrace

## Description

Resets the shader-trace object.

## Remarks

After you call **ResetTrace**, the [ID3D11ShaderTrace](https://learn.microsoft.com/windows/desktop/api/d3d11shadertracing/nn-d3d11shadertracing-id3d11shadertrace) object behaves as if it had just been created. Thereafter, shader invocations for the trace start from 0 again; calls to [ID3D11ShaderTrace::TraceReady](https://learn.microsoft.com/windows/desktop/api/d3d11shadertracing/nf-d3d11shadertracing-id3d11shadertrace-traceready) return **S_FALSE** until the selected shader invocation number is reached, and **TraceReady** records a new trace.

**Note** This API requires the Windows Software Development Kit (SDK) for Windows 8.

## See also

[ID3D11ShaderTrace](https://learn.microsoft.com/windows/desktop/api/d3d11shadertracing/nn-d3d11shadertracing-id3d11shadertrace)