# D3DX12ParsePipelineStream function

Parses a pipeline state stream description, calling a user-defined callback for each subobject instance parsed.

## Parameters

*Desc* \[ref\]

Type: **const [**D3D12\_PIPELINE\_STATE\_STREAM\_DESC**](https://learn.microsoft.com/windows/desktop/api/d3d12/ns-d3d12-d3d12_pipeline_state_stream_desc)**

The pipeline state stream description to parse.

*pCallbacks*

Type: **[**ID3DX12PipelineParserCallbacks**](https://learn.microsoft.com/windows/win32/direct3d12/id3dx12pipelineparsercallbacks)\***

A structure that specifies the callbacks to call for each subobject type and additional callbacks to call in the event of a parsing error.

## Return value

Type: **[**HRESULT**](https://msdn.microsoft.com/library/Bb401631(v=MSDN.10).aspx)**

This method returns an HRESULT success (**S\_OK** or **E\_INVALIDARG** error if an unknown subobject type is encountered, if the stream description is empty, null, or contains duplicate subobjects (including derived subobjects), or if *pCallbacks* is null. In each case that E\_INVALIDARG is returned, a corresponding callback is first called.

## Requirements

| Requirement | Value |
|--------------------|--------------------------------------------------------------------------------------|
| Header<br> | D3dx12.h |
| Library<br> | D3D12.lib |
| DLL<br> | D3D12.dll |

## See also

[Helper Functions for D3D12](https://learn.microsoft.com/windows/win32/direct3d12/helper-functions-for-d3d12)

