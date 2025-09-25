# ID3D11VideoContext::QueryAuthenticatedChannel

## Description

Sends a query to an authenticated channel.

## Parameters

### `pChannel` [in]

A pointer to the [ID3D11AuthenticatedChannel](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11authenticatedchannel) interface.

### `InputSize` [in]

The size of the *pInput* array, in bytes.

### `pInput` [in]

A pointer to a byte array that contains input data for the query. This array always starts with a [D3D11_AUTHENTICATED_QUERY_INPUT](https://learn.microsoft.com/windows/desktop/api/d3d11/ns-d3d11-d3d11_authenticated_query_input) structure. The **QueryType** member of the structure specifies the query and defines the meaning of the rest of the array.

### `OutputSize` [in]

The size of the *pOutput* array, in bytes.

### `pOutput` [out]

A pointer to a byte array that receives the result of the query. This array always starts with a [D3D11_AUTHENTICATED_QUERY_OUTPUT](https://learn.microsoft.com/windows/desktop/api/d3d11/ns-d3d11-d3d11_authenticated_query_output) structure. The meaning of the rest of the array depends on the query.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[ID3D11VideoContext](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11videocontext)