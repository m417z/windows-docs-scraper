## Description

Creates a cached pipeline library. For pipeline state objects (PSOs) that are expected to share data together, grouping them into a library before serializing them means that there's less overhead due to metadata, as well as the opportunity to avoid redundant or duplicated data being written to disk.

You can query for **ID3D12PipelineLibrary** support with **[ID3D12Device::CheckFeatureSupport](https://learn.microsoft.com/windows/win32/api/d3d12/nf-d3d12-id3d12device-checkfeaturesupport)**, with **[D3D12_FEATURE_SHADER_CACHE](https://learn.microsoft.com/windows/win32/api/d3d12/ne-d3d12-d3d12_feature)** and **[D3D12_FEATURE_DATA_SHADER_CACHE](https://learn.microsoft.com/windows/win32/api/d3d12/ns-d3d12-d3d12_feature_data_shader_cache)**. If the *Flags* member of **[D3D12_FEATURE_DATA_SHADER_CACHE](https://learn.microsoft.com/windows/win32/api/d3d12/ns-d3d12-d3d12_feature_data_shader_cache)** contains the flag **[D3D12_SHADER_CACHE_SUPPORT_LIBRARY](https://learn.microsoft.com/windows/win32/api/d3d12/ne-d3d12-d3d12_shader_cache_support_flags)**, the **ID3D12PipelineLibrary** interface is supported. If not, then **DXGI_ERROR_NOT_SUPPORTED** will always be returned when this function is called.

## Parameters

### `pLibraryBlob`

Type: [in] **const void\***

If the input library blob is empty, then the initial content of the library is empty. If the input library blob is not empty, then it is validated for integrity, parsed, and the pointer is stored. The pointer provided as input to this method must remain valid for the lifetime of the object returned. For efficiency reasons, the data is not copied.

### `BlobLength`

Type: **[SIZE_T](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Specifies the length of *pLibraryBlob* in bytes.

### `riid`

Type: **REFIID**

Specifies a unique REFIID for the [ID3D12PipelineLibrary](https://learn.microsoft.com/windows/win32/api/d3d12/nn-d3d12-id3d12pipelinelibrary) object. Typically set this and the following parameter with the macro `IID_PPV_ARGS(&Library)`, where **Library** is the name of the object.

### `ppPipelineLibrary`

Type: [out] **void\*\***

Returns a pointer to the created library.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

If the function succeeds, it returns **S_OK**. Otherwise, it returns an [**HRESULT**](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes) [error code](https://learn.microsoft.com/windows/win32/com/com-error-codes-10), including **E_INVALIDARG** if the blob is corrupted or unrecognized, **D3D12_ERROR_DRIVER_VERSION_MISMATCH** if the provided data came from an old driver or runtime, and **D3D12_ERROR_ADAPTER_NOT_FOUND** if the data came from different hardware.

If you pass `nullptr` for *pPipelineLibrary* then the runtime still performs the validation of the blob but avoid creating the actual library and returns S_FALSE if the library would have been created.

Also, the feature requires an updated driver, and attempting to use it on old drivers will return DXGI_ERROR_UNSUPPORTED.

## Remarks

A pipeline library enables the following operations.

- Adding pipeline state objects (PSOs) to an existing library object (refer to [StorePipeline](https://learn.microsoft.com/windows/win32/api/d3d12/nf-d3d12-id3d12pipelinelibrary-storepipeline)).
- Serializing a PSO library into a contiguous block of memory for disk storage (refer to [Serialize](https://learn.microsoft.com/windows/win32/api/d3d12/nf-d3d12-id3d12pipelinelibrary-serialize)).
- De-serializing a PSO library from persistent storage (this is handled by **CreatePipelineLibrary**).
- Retrieving individual PSOs from the library (refer to [LoadComputePipeline](https://learn.microsoft.com/windows/win32/api/d3d12/nf-d3d12-id3d12pipelinelibrary-loadcomputepipeline) and [LoadGraphicsPipeline](https://learn.microsoft.com/windows/win32/api/d3d12/nf-d3d12-id3d12pipelinelibrary-loadgraphicspipeline)).

At no point in the lifecycle of a pipeline library is there duplication between PSOs with identical sub-components.

A recommended solution for managing the lifetime of the provided pointer while only having to ref-count the returned interface is to leverage [ID3D12Object::SetPrivateDataInterface](https://learn.microsoft.com/windows/win32/api/d3d12/nf-d3d12-id3d12object-setprivatedatainterface), and use an object which implements **IUnknown**, and frees the memory when the ref-count reaches 0.

### Thread Safety

The pipeline library is thread-safe to use, and will internally synchronize as necessary, with one exception: multiple threads loading the same PSO (via [**LoadComputePipeline**](https://learn.microsoft.com/windows/win32/api/d3d12/nf-d3d12-id3d12pipelinelibrary-loadcomputepipeline),
[**LoadGraphicsPipeline**](https://learn.microsoft.com/windows/win32/api/d3d12/nf-d3d12-id3d12pipelinelibrary-loadgraphicspipeline), or [**LoadPipeline**](https://learn.microsoft.com/windows/win32/api/d3d12/nf-d3d12-id3d12pipelinelibrary1-loadpipeline)) should synchronize themselves, as this act may modify the state of that pipeline within the library in a non-thread-safe manner.

## Examples

See the [Direct3D 12 pipeline state cache sample](https://github.com/microsoft/DirectX-Graphics-Samples/tree/master/Samples/Desktop/D3D12PipelineStateCache).

## See also

* [ID3D12Device1](https://learn.microsoft.com/windows/win32/api/d3d12/nn-d3d12-id3d12device1)
* [Direct3D 12 pipeline state cache sample](https://github.com/microsoft/DirectX-Graphics-Samples/tree/master/Samples/Desktop/D3D12PipelineStateCache)