# ID3D11DeviceContext::PSGetConstantBuffers

## Description

Get the constant buffers used by the pixel shader pipeline stage.

## Parameters

### `StartSlot` [in]

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Index into the device's zero-based array to begin retrieving constant buffers from (ranges from 0 to D3D11_COMMONSHADER_CONSTANT_BUFFER_API_SLOT_COUNT - 1).

### `NumBuffers` [in]

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Number of buffers to retrieve (ranges from 0 to D3D11_COMMONSHADER_CONSTANT_BUFFER_API_SLOT_COUNT - StartSlot).

### `ppConstantBuffers` [out, optional]

Type: **[ID3D11Buffer](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11buffer)****

Array of constant buffer interface pointers (see [ID3D11Buffer](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11buffer)) to be returned by the method.

## Remarks

Any returned interfaces will have their reference count incremented by one. Applications should call IUnknown::Release on the returned interfaces when they are no longer needed to avoid memory leaks.

## See also

[ID3D11DeviceContext](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11devicecontext)