# ID3D11DeviceContext::DispatchIndirect

## Description

Execute a command list over one or more thread groups.

## Parameters

### `pBufferForArgs` [in]

Type: **[ID3D11Buffer](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11buffer)***

A pointer to an [ID3D11Buffer](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11buffer), which must be loaded with data that matches the argument list for [ID3D11DeviceContext::Dispatch](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11devicecontext-dispatch).

### `AlignedByteOffsetForArgs` [in]

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A byte-aligned offset between the start of the buffer and the arguments.

## Remarks

You call the **DispatchIndirect** method to execute commands in a [compute shader](https://learn.microsoft.com/windows/desktop/direct3d11/direct3d-11-advanced-stages-compute-shader).

When an application creates a buffer that is associated with the [ID3D11Buffer](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11buffer) interface that *pBufferForArgs* points to, the application must set the [D3D11_RESOURCE_MISC_DRAWINDIRECT_ARGS](https://learn.microsoft.com/windows/desktop/api/d3d11/ne-d3d11-d3d11_resource_misc_flag) flag in the **MiscFlags** member of the [D3D11_BUFFER_DESC](https://learn.microsoft.com/windows/desktop/api/d3d11/ns-d3d11-d3d11_buffer_desc) structure that describes the buffer. To create the buffer, the application calls the [ID3D11Device::CreateBuffer](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11device-createbuffer) method and in this call passes a pointer to **D3D11_BUFFER_DESC** in the *pDesc* parameter.

## See also

[ID3D11DeviceContext](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11devicecontext)