# ID3D11DeviceContext::SOGetTargets

## Description

Get the target output buffers for the stream-output stage of the pipeline.

## Parameters

### `NumBuffers` [in]

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Number of buffers to get.

### `ppSOTargets` [out, optional]

Type: **[ID3D11Buffer](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11buffer)****

An array of output buffers (see [ID3D11Buffer](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11buffer)) to be retrieved from the device.

## Remarks

A maximum of four output buffers can be retrieved.

The offsets to the output buffers pointed to in the returned *ppSOTargets* array may be assumed to be -1 (append), as defined for use in [ID3D11DeviceContext::SOSetTargets](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11devicecontext-sosettargets).

Any returned interfaces will have their reference count incremented by one. Applications should call IUnknown::Release on the returned interfaces when they are no longer needed to avoid memory leaks.

**Windows Phone 8:** This API is supported.

## See also

[ID3D11DeviceContext](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11devicecontext)