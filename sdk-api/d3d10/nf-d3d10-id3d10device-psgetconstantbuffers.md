# ID3D10Device::PSGetConstantBuffers

## Description

Get the [constant buffers](https://learn.microsoft.com/windows/desktop/direct3d10/d3d10-graphics-programming-guide-resources-types) used by the [pixel shader](https://learn.microsoft.com/previous-versions/bb205146(v=vs.85)) pipeline stage.

## Parameters

### `StartSlot` [in]

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Index into the device's zero-based array to begin retrieving constant buffers from.

### `NumBuffers` [in]

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Number of buffers to retrieve.

### `ppConstantBuffers` [out]

Type: **[ID3D10Buffer](https://learn.microsoft.com/windows/desktop/api/d3d10/nn-d3d10-id3d10buffer)****

Array of constant buffer interface pointers (see [ID3D10Buffer](https://learn.microsoft.com/windows/desktop/api/d3d10/nn-d3d10-id3d10buffer)) to be returned by the method.

## Remarks

Any returned interfaces will have their reference count incremented by one. Applications should call [IUnknown::Release](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-release) on the returned interfaces when they are no longer needed to avoid memory leaks.

## See also

[ID3D10Device Interface](https://learn.microsoft.com/windows/desktop/api/d3d10/nn-d3d10-id3d10device)