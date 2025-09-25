# ID3D10Device::CreateBuffer

## Description

Create a [buffer](https://learn.microsoft.com/windows/desktop/direct3d10/d3d10-graphics-programming-guide-resources-types) (vertex buffer, index buffer, or shader-constant buffer).

## Parameters

### `pDesc` [in]

Type: **const [D3D10_BUFFER_DESC](https://learn.microsoft.com/windows/desktop/api/d3d10/ns-d3d10-cd3d10_buffer_desc)***

Pointer to a buffer description (see [D3D10_BUFFER_DESC](https://learn.microsoft.com/windows/desktop/api/d3d10/ns-d3d10-cd3d10_buffer_desc)).

### `pInitialData` [in]

Type: **const [D3D10_SUBRESOURCE_DATA](https://learn.microsoft.com/windows/desktop/api/d3d10/ns-d3d10-d3d10_subresource_data)***

Pointer to the initialization data (see [D3D10_SUBRESOURCE_DATA](https://learn.microsoft.com/windows/desktop/api/d3d10/ns-d3d10-d3d10_subresource_data)); use **NULL** to allocate space only.

### `ppBuffer` [out]

Type: **[ID3D10Buffer](https://learn.microsoft.com/windows/desktop/api/d3d10/nn-d3d10-id3d10buffer)****

Address of a pointer to the buffer created (see [ID3D10Buffer Interface](https://learn.microsoft.com/windows/desktop/api/d3d10/nn-d3d10-id3d10buffer)). Set this parameter to **NULL** to validate the other input parameters (S_FALSE indicates a pass).

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

This method returns one of the following [Direct3D 10 Return Codes](https://learn.microsoft.com/windows/desktop/direct3d10/d3d10-graphics-reference-returnvalues).

## Remarks

For example code, see:

* [Create a Vertex Buffer](https://learn.microsoft.com/windows/desktop/direct3d10/d3d10-graphics-programming-guide-resources-creating)
* [Create an Index Buffer](https://learn.microsoft.com/windows/desktop/direct3d10/d3d10-graphics-programming-guide-resources-creating)

## See also

[ID3D10Device Interface](https://learn.microsoft.com/windows/desktop/api/d3d10/nn-d3d10-id3d10device)