# CD3DX12\_PIPELINE\_STATE\_STREAM\_PARSE\_HELPER structure

Builds an internal CD3DX12\_PIPELINE\_STATE\_STREAM object from subobject details passed into the corresponding member functions. This struct implements the [**ID3DX12PipelineParserCallbacks**](https://learn.microsoft.com/windows/win32/direct3d12/id3dx12pipelineparsercallbacks) interface.

## Members

**PipelineStream**

The internal [**CD3DX12\_PIPELINE\_STATE\_STREAM1**](https://learn.microsoft.com/windows/win32/direct3d12/cd3dx12-pipeline-state-stream1). Its current state represents the cumulative effect of callback methods that have been called on this object.

**FlagsCb(D3D12\_PIPELINE\_STATE\_FLAGS Flags)**

Initializes the **Flags** member of **PipelineStream** using the value of the *Flags* parameter.

**NodeMaskCb(UINT NodeMask)**

Initializes the **NodeMask** member of **PipelineStream** using the value of the *Nodemask* parameter.

**RootSignatureCb(ID3D12RootSignature\* pRootSignature)**

Initializes the **pRootSignature** member of **PipelineStream** using the value of the *pRootSignature* parameter.

**InputLayoutCb(const D3D12\_INPUT\_LAYOUT\_DESC& InputLayout)**

Initializes the **InputLayout** member of **PipelineStream** using the value of the *InputLayout* parameter.

**IBStripCutValueCb(D3D12\_INDEX\_BUFFER\_STRIP\_CUT\_VALUE IBStripCutValue)**

Initializes the **IBStripCutValue** member of **PipelineStream** using the value of the *IBStripCutValue* parameter.

**PrimitiveTopologyTypeCb(D3D12\_PRIMITIVE\_TOPOLOGY\_TYPE PrimitiveTopologyType)**

Initializes the **PrimitiveTopologyType** member of **PipelineStream** using the value of the *PrimitiveTopologyType* parameter.

**VSCb(const D3D12\_SHADER\_BYTECODE& VS)**

Initializes the **VS** (vertex shader) member of **PipelineStream** using the value of the *VS* parameter.

**GSCb(const D3D12\_SHADER\_BYTECODE& GS)**

Initializes the **GS** (geometry shader) member of **PipelineStream** using the value of the *GS* parameter.

**StreamOutputCb(const D3D12\_STREAM\_OUTPUT\_DESC& StreamOutput)**

Initializes the **StreamOutput** member of **PipelineStream** using the value of the *StreamOutput* parameter.

**HSCb(const D3D12\_SHADER\_BYTECODE& HS)**

Initializes the **HS** (hull shader) member of **PipelineStream** using the value of the *HS* parameter.

**DSCb(const D3D12\_SHADER\_BYTECODE& DS)**

Initializes the **DS** (domain shader) member of **PipelineStream** using the value of the *DS* parameter.

**PSCb(const D3D12\_SHADER\_BYTECODE& PS)**

Initializes the **PS** (pixel shader) member of **PipelineStream** using the value of the *PS* parameter.

**CSCb(const D3D12\_SHADER\_BYTECODE& CS)**

Initializes the **CS** member of **PipelineStream** using the value of the *CS* parameter.

**BlendStateCb(const D3D12\_BLEND\_DESC& BlendState)**

Initializes the **BlendState** member of **PipelineStream** using the value of the *BlendState* parameter.

**DepthStencilStateCb(const D3D12\_DEPTH\_STENCIL\_DESC& DepthStencilState)**

Initializes the **DepthStencilState** member of **PipelineStream** using the value of the *DepthStencilState* parameter, a [**D3D12\_DEPTH\_STENCIL\_DESC**](https://learn.microsoft.com/windows/desktop/api/d3d12/ns-d3d12-d3d12_depth_stencil_desc).

**DepthStencilState1Cb(const D3D12\_DEPTH\_STENCIL\_DESC1& DepthStencilState)**

Initializes the **DepthStencilState** member of **PipelineStream** using the value of the *DepthStencilState* parameter, a [**D3D12\_DEPTH\_STENCIL\_DESC1**](https://learn.microsoft.com/windows/desktop/api/d3d12/ns-d3d12-d3d12_depth_stencil_desc1).

**DSVFormatCb(DXGI\_FORMAT DSVFormat)**

Initializes the **DSVFormat** member of **PipelineStream** using the value of the *DSVFormat* parameter.

**RasterizerStateCb(const D3D12\_RASTERIZER\_DESC& RasterizerState)**

Initializes the **RasterizerState** member of **PipelineStream** using the value of the *RasterizerState* parameter.

**RTVFormatsCb(const D3D12\_RT\_FORMAT\_ARRAY& RTVFormats)**

Initializes the **RTVFormats** member of **PipelineStream** using the value of the *RTVFormats* parameter.

**SampleDescCb(const DXGI\_SAMPLE\_DESC& SampleDesc)**

Initializes the **SampleDesc** member of **PipelineStream** using the value of the *SampleDesc* parameter.

**SampleMaskCb(UINT SampleMask)**

Initializes the **SampleMask** member of **PipelineStream** using the value of the *SampleMask* parameter.

**ViewInstancingCb(const D3D12\_VIEW\_INSTANCING\_DESC& ViewInstancingDesc)**

Initializes the **ViewInstancingDesc** member of **PipelineStream** using the value of the *ViewInstancingDesc* parameter.

**CachedPSOCb(const D3D12\_CACHED\_PIPELINE\_STATE& CachedPSO)**

Initializes the **CachedPSO** member of **PipelineStream** using the value of the *CachedPSO* parameter.

**ErrorBadInputParameter(UINT)**

Does nothing.

**ErrorDuplicateSubobject(D3D12\_PIPELINE\_STATE\_SUBOBJECT\_TYPE)**

Does nothing.

**ErrorUnknownSubobject(UINT)**

Does nothing.

## Remarks

When passed as the second parameter to the [**D3DX12ParsePipelineStream**](https://learn.microsoft.com/windows/win32/direct3d12/d3dx12parsepipelinestream) function, the details of the internal [**CD3DX12\_PIPELINE\_STATE\_STREAM1**](https://learn.microsoft.com/windows/win32/direct3d12/cd3dx12-pipeline-state-stream1) object are cloned from the [**D3D12\_PIPELINE\_STATE\_STREAM\_DESC**](https://learn.microsoft.com/windows/desktop/api/d3d12/ns-d3d12-d3d12_pipeline_state_stream_desc) passed as the first parameter. This process validates the source stream description. If D3DX12ParsePipelineStream returns **S\_OK**, then both the source stream description and the resulting **CD3DX12\_PIPELINE\_STATE\_STREAM1PipelineStream** are valid; otherwise both are invalid. Invalid streams and other errors are reported only through the return value of D3DX12ParsePipelineStream; this structure implements the error callbacks to do nothing.

## Requirements

| Requirement | Value |
|-------------------|-------------------------------------------------------------------------------------|
| Header<br> | D3dx12.h |

## See also

[Helper Structures for Direct3D 12](https://learn.microsoft.com/windows/win32/direct3d12/helper-structures-for-d3d12)

[**ID3DX12PipelineParserCallbacks**](https://learn.microsoft.com/windows/win32/direct3d12/id3dx12pipelineparsercallbacks)

