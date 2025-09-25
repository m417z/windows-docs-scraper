# ID3D11DeviceContext3::Flush1

## Description

Sends queued-up commands in the command buffer to the graphics processing unit (GPU), with a specified context type and an optional event handle to create an event query.

## Parameters

### `ContextType`

Type: **[D3D11_CONTEXT_TYPE](https://learn.microsoft.com/windows/desktop/api/d3d11_3/ne-d3d11_3-d3d11_context_type)**

A [D3D11_CONTEXT_TYPE](https://learn.microsoft.com/windows/desktop/api/d3d11_3/ne-d3d11_3-d3d11_context_type) that specifies the context in which a query occurs, such as a 3D command queue, 3D compute queue, 3D copy queue, video, or image.

### `hEvent` [in, optional]

Type: **HANDLE**

An optional event handle. When specified, this method creates an event query.

**Flush1** operates asynchronously, therefore it can return either before or after the GPU finishes executing the queued graphics commands, which will eventually complete.
To create an event query, you can call [ID3D11Device::CreateQuery](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11device-createquery) with the
value [D3D11_QUERY_EVENT](https://learn.microsoft.com/windows/desktop/api/d3d11/ne-d3d11-d3d11_query) value.
To determine when the GPU is finished processing the graphics commands,
you can then use that event query in a call to [ID3D11DeviceContext::GetData](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11devicecontext-getdata).

## Remarks

**Flush1** has parameters.
For more information, see
[ID3D11DeviceContext::Flush](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11devicecontext-flush), which doesn't have parameters.

## See also

[ID3D11DeviceContext3](https://learn.microsoft.com/windows/desktop/api/d3d11_3/nn-d3d11_3-id3d11devicecontext3)

[ID3D11DeviceContext::Flush](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11devicecontext-flush)