# ID3D11DeviceContext::DSSetConstantBuffers

## Description

Sets the constant buffers used by the domain-shader stage.

## Parameters

### `StartSlot` [in]

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Index into the zero-based array to begin setting constant buffers to (ranges from 0 to **D3D11_COMMONSHADER_CONSTANT_BUFFER_API_SLOT_COUNT** - 1).

### `NumBuffers` [in]

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Number of buffers to set (ranges from 0 to **D3D11_COMMONSHADER_CONSTANT_BUFFER_API_SLOT_COUNT** - *StartSlot*).

### `ppConstantBuffers` [in, optional]

Type: **[ID3D11Buffer](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11buffer)***

Array of constant buffers (see [ID3D11Buffer](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11buffer)) being given to the device.

## Remarks

The method will hold a reference to the interfaces passed in.
This differs from the device state behavior in Direct3D 10.

The Direct3D 11.1 runtime, which is available starting with Windows 8, can bind a larger number of [ID3D11Buffer](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11buffer) resources to the shader than the maximum constant buffer size that is supported by shaders (4096 constants – 4*32-bit components each). When you bind such a large buffer, the shader can access only the first 4096 4*32-bit component constants in the buffer, as if 4096 constants is the full size of the buffer.

If the application wants the shader to access other parts of the buffer, it must call the [DSSetConstantBuffers1](https://learn.microsoft.com/windows/desktop/api/d3d11_1/nf-d3d11_1-id3d11devicecontext1-dssetconstantbuffers1) method instead.

**Windows Phone 8:** This API is supported.

## See also

[ID3D11DeviceContext](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11devicecontext)