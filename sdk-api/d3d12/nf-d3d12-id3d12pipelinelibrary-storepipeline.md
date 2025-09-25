# ID3D12PipelineLibrary::StorePipeline

## Description

Adds the input PSO to an internal database with the corresponding name.

## Parameters

### `pName` [in, optional]

Type: **LPCWSTR**

Specifies a unique name for the library. Overwriting is not supported.

### `pPipeline` [in]

Type: **ID3D12PipelineState***

Specifies the [ID3D12PipelineState](https://learn.microsoft.com/windows/desktop/api/d3d12/nn-d3d12-id3d12pipelinestate) to add.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

This method returns an HRESULT success or error code, including E_INVALIDARG if the name already exists, E_OUTOFMEMORY if unable to allocate storage in the library.

## Remarks

Refer to the remarks and examples for [CreatePipelineLibrary](https://learn.microsoft.com/windows/desktop/api/d3d12/nf-d3d12-id3d12device1-createpipelinelibrary).

## See also

[ID3D12PipelineLibrary](https://learn.microsoft.com/windows/desktop/api/d3d12/nn-d3d12-id3d12pipelinelibrary)