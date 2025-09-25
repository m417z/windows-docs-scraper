# ID3D11Device::CreateBuffer

## Description

Creates a buffer (vertex buffer, index buffer, or shader-constant buffer).

## Parameters

### `pDesc` [in]

Type: **const [D3D11_BUFFER_DESC](https://learn.microsoft.com/windows/desktop/api/d3d11/ns-d3d11-d3d11_buffer_desc)***

A pointer to a [D3D11_BUFFER_DESC](https://learn.microsoft.com/windows/desktop/api/d3d11/ns-d3d11-d3d11_buffer_desc) structure that describes the buffer.

### `pInitialData` [in, optional]

Type: **const [D3D11_SUBRESOURCE_DATA](https://learn.microsoft.com/windows/desktop/api/d3d11/ns-d3d11-d3d11_subresource_data)***

A pointer to a [D3D11_SUBRESOURCE_DATA](https://learn.microsoft.com/windows/desktop/api/d3d11/ns-d3d11-d3d11_subresource_data) structure that describes the initialization data;
use **NULL** to allocate space only (with the exception that it cannot be **NULL** if the usage flag is **D3D11_USAGE_IMMUTABLE**).

If you don't pass anything to *pInitialData*, the initial content of the memory for the buffer is undefined.
In this case, you need to write the buffer content some other way before the resource is read.

### `ppBuffer` [out, optional]

Type: **[ID3D11Buffer](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11buffer)****

Address of a pointer to the [ID3D11Buffer](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11buffer) interface for the buffer object created.
Set this parameter to **NULL** to validate the other input parameters (**S_FALSE** indicates a pass).

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

This method returns **E_OUTOFMEMORY** if there is insufficient memory to create the buffer.
See [Direct3D 11 Return Codes](https://learn.microsoft.com/windows/desktop/direct3d11/d3d11-graphics-reference-returnvalues) for other possible return values.

## Remarks

For example code, see [How to: Create a Vertex Buffer](https://learn.microsoft.com/windows/desktop/direct3d11/overviews-direct3d-11-resources-buffers-vertex-how-to),
[How to: Create an Index Buffer](https://learn.microsoft.com/windows/desktop/direct3d11/overviews-direct3d-11-resources-buffers-index-how-to) or
[How to: Create a Constant Buffer](https://learn.microsoft.com/windows/desktop/direct3d11/overviews-direct3d-11-resources-buffers-constant-how-to).

For a constant buffer (**BindFlags** of [D3D11_BUFFER_DESC](https://learn.microsoft.com/windows/desktop/api/d3d11/ns-d3d11-d3d11_buffer_desc) set to [D3D11_BIND_CONSTANT_BUFFER](https://learn.microsoft.com/windows/desktop/api/d3d11/ne-d3d11-d3d11_bind_flag)),
you must set the **ByteWidth** value of **D3D11_BUFFER_DESC** in multiples of 16, and less than or equal to **D3D11_REQ_CONSTANT_BUFFER_ELEMENT_COUNT**.

The Direct3D 11.1 runtime, which is available on Windows 8 and later operating systems, provides the following new functionality for **CreateBuffer**:

You can create a constant buffer that is larger than the maximum constant buffer size that a shader can access (4096 32-bit*4-component constants – 64KB).
When you bind the constant buffer to the pipeline (for example, via [PSSetConstantBuffers](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11devicecontext-pssetconstantbuffers) or [PSSetConstantBuffers1](https://learn.microsoft.com/windows/desktop/api/d3d11_1/nf-d3d11_1-id3d11devicecontext1-pssetconstantbuffers1)),
you can define a range of the buffer that the shader can access that fits within the 4096 constant limit.
The Direct3D 11.1 runtime (available in Windows 8 and later operating systems) emulates this feature for [feature level](https://learn.microsoft.com/windows/win32/direct3d11/overviews-direct3d-11-devices-downlevel-intro) 9.1, 9.2, and 9.3; therefore, this feature is supported for feature level 9.1, 9.2, and 9.3.

This feature is always available on new drivers for feature level 10 and higher.

On runtimes older than Direct3D 11.1, a call to **CreateBuffer** to request a constant buffer that is larger than 4096 fails.

## See also

[ID3D11Device](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11device)