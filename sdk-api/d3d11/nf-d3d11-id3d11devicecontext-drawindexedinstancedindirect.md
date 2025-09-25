## Description

Draw indexed, instanced, GPU-generated primitives.

## Parameters

### `pBufferForArgs` [in]

Type: **[ID3D11Buffer](https://learn.microsoft.com/windows/win32/api/d3d11/nn-d3d11-id3d11buffer)\***

A pointer to an [ID3D11Buffer](https://learn.microsoft.com/windows/win32/api/d3d11/nn-d3d11-id3d11buffer), which is a buffer containing the GPU-generated primitives.

### `AlignedByteOffsetForArgs` [in]

Type: **[UINT](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

A DWORD-aligned byte offset in *pBufferForArgs* to the start of the GPU generated primitives.

## Remarks

When an application creates a buffer that is associated with the [ID3D11Buffer](https://learn.microsoft.com/windows/win32/api/d3d11/nn-d3d11-id3d11buffer) interface that *pBufferForArgs* points to, your application must set the [D3D11_RESOURCE_MISC_DRAWINDIRECT_ARGS](https://learn.microsoft.com/windows/win32/api/d3d11/ne-d3d11-d3d11_resource_misc_flag) flag in the *MiscFlags* member of the [D3D11_BUFFER_DESC](https://learn.microsoft.com/windows/win32/api/d3d11/ns-d3d11-d3d11_buffer_desc) structure that describes the buffer. To create the buffer, your application should call the [ID3D11Device::CreateBuffer](https://learn.microsoft.com/windows/win32/api/d3d11/nf-d3d11-id3d11device-createbuffer) method, and pass a pointer to a **D3D11_BUFFER_DESC** in the *pDesc* parameter.

**Windows Phone 8:** This API is supported.

## See also

[ID3D11DeviceContext](https://learn.microsoft.com/windows/win32/api/d3d11/nn-d3d11-id3d11devicecontext)