# ID3D12PipelineLibrary::Serialize

## Description

Writes the contents of the library to the provided memory, to be provided back to the runtime at a later time.

## Parameters

### `pData` [out]

Type: **void***

Specifies a pointer to the data. This memory must be readable and writable up to the input size. This data can be saved and provided to [CreatePipelineLibrary](https://learn.microsoft.com/windows/desktop/api/d3d12/nf-d3d12-id3d12device1-createpipelinelibrary) at a later time, including future instances of this or other processes. The data becomes invalidated if the runtime or driver is updated, and is not portable to other hardware or devices.

### `DataSizeInBytes`

Type: **SIZE_T**

The size provided must be at least the size returned from [GetSerializedSize](https://learn.microsoft.com/windows/desktop/api/d3d12/nf-d3d12-id3d12pipelinelibrary-getserializedsize).

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

This method returns an HRESULT success or error code, including E_INVALIDARG if the buffer provided isn’t big enough.

## Remarks

Refer to the remarks and examples for [CreatePipelineLibrary](https://learn.microsoft.com/windows/desktop/api/d3d12/nf-d3d12-id3d12device1-createpipelinelibrary).

## See also

[ID3D12PipelineLibrary](https://learn.microsoft.com/windows/desktop/api/d3d12/nn-d3d12-id3d12pipelinelibrary)