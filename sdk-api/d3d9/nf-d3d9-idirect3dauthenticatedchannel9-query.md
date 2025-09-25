# IDirect3DAuthenticatedChannel9::Query

## Description

Sends a query to the authenticated channel.

## Parameters

### `InputSize`

The size of the *pInput* array, in bytes.

### `pInput`

A pointer to a byte array that contains input data for the query. This array always starts with a [D3DAUTHENTICATEDCHANNEL_QUERY_INPUT](https://learn.microsoft.com/windows/desktop/medfound/d3dauthenticatedchannel-query-input) structure. The **QueryType** member of the structure specifies the query and defines the meaning of the rest of the array.

### `OutputSize`

The size of the *pOutput* array, in bytes.

### `pOutput`

A pointer to a byte array that receives the result of the query. This array always starts with a [D3DAUTHENTICATEDCHANNEL_QUERY_OUTPUT](https://learn.microsoft.com/windows/desktop/medfound/d3dauthenticatedchannel-query-output) structure. The meaning of the rest of the array depends on the query.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

For a list of queries, see [Content Protection Queries](https://learn.microsoft.com/windows/desktop/medfound/content-protection-queries).

## See also

[GPU-Based Content Protection](https://learn.microsoft.com/windows/desktop/medfound/gpu-based-content-protection)

[IDirect3DAuthenticatedChannel9](https://learn.microsoft.com/windows/desktop/api/d3d9/nn-d3d9-idirect3dauthenticatedchannel9)