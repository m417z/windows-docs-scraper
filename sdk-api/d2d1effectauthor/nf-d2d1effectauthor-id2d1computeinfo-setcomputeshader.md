# ID2D1ComputeInfo::SetComputeShader

## Description

Sets the compute shader to the given shader resource. The resource must be loaded before this call is made.

## Parameters

### `shaderId` [in]

Type: **REFGUID**

The GUID of the shader.

## Return value

Type: **HRESULT**

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| HRESULT | Description |
| --- | --- |
| S_OK | No error occurred. |
| E_OUTOFMEMORY | Direct2D could not allocate sufficient memory to complete the call. |
| E_INVALIDARG | An invalid parameter was passed to the returning function. |

## See also

[ID2D1ComputeInfo](https://learn.microsoft.com/windows/desktop/api/d2d1effectauthor/nn-d2d1effectauthor-id2d1computeinfo)