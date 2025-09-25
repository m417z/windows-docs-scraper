# ID3D12PipelineLibrary::LoadComputePipeline

## Description

Retrieves the requested PSO from the library. The input desc is matched against the data in the current library database, and remembered in order to prevent duplication of PSO contents.

## Parameters

### `pName` [in]

Type: **LPCWSTR**

The unique name of the PSO.

### `pDesc` [in]

Type: **const [D3D12_COMPUTE_PIPELINE_STATE_DESC](https://learn.microsoft.com/windows/desktop/api/d3d12/ns-d3d12-d3d12_compute_pipeline_state_desc)***

Specifies a description of the required PSO in a [D3D12_COMPUTE_PIPELINE_STATE_DESC](https://learn.microsoft.com/windows/desktop/api/d3d12/ns-d3d12-d3d12_compute_pipeline_state_desc) structure. This input description is matched against the data in the current library database, and stored in order to prevent duplication of PSO contents.

### `riid`

Type: **REFIID**

Specifies a REFIID for the [ID3D12PipelineState](https://learn.microsoft.com/windows/desktop/api/d3d12/nn-d3d12-id3d12pipelinestate) object. Typically set this, and the following parameter, with the macro `IID_PPV_ARGS(&PSO1)`, where *PSO1* is the name of the object.

### `ppPipelineState` [out]

Type: **void****

Specifies a pointer that will reference the returned PSO.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

This method returns an HRESULT success or error code, which can include E_INVALIDARG if the name doesn’t exist, or if the input description doesn’t match the data in the library, and E_OUTOFMEMORY if unable to allocate the return PSO.

## Remarks

Refer to the remarks and examples for [CreatePipelineLibrary](https://learn.microsoft.com/windows/desktop/api/d3d12/nf-d3d12-id3d12device1-createpipelinelibrary).

## See also

[ID3D12PipelineLibrary](https://learn.microsoft.com/windows/desktop/api/d3d12/nn-d3d12-id3d12pipelinelibrary)