# ID2D1Properties::SetValue(UINT32,const BYTE,UINT32)

## Description

Sets the corresponding property by index.

## Parameters

### `index`

Type: **UINT32**

The index of the property to set.

### `data` [in]

Type: **const BYTE***

The data to set.

### `dataSize`

Type: **UINT32**

The number of bytes in the data to set.

## Return value

Type: **HRESULT**

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| HRESULT | Description |
| --- | --- |
| S_OK | No error occurred. |
| D2DERR_INVALID_PROPERTY | The specified property does not exist. |
| E_OUTOFMEMORY | Failed to allocate necessary memory. |
| D3DERR_OUT_OF_VIDEO_MEMORY | Failed to allocate required video memory. |
| E_INVALIDARG | One or more arguments are invalid. |
| E_FAIL | Unspecified failure. |

## Remarks

If the property does not exist, the request is ignored and **D2DERR_INVALID_PROPERTY** is returned.

Any error not in the standard set returned by a property implementation will be mapped into the standard error range.

## See also

[D2D1_PROPERTY](https://learn.microsoft.com/windows/desktop/api/d2d1_1/ne-d2d1_1-d2d1_property)

[D2D1_SUBPROPERTY](https://learn.microsoft.com/windows/desktop/api/d2d1_1/ne-d2d1_1-d2d1_subproperty)

[ID2D1DeviceContext::CreateEffect](https://learn.microsoft.com/windows/desktop/api/d2d1_1/nf-d2d1_1-id2d1devicecontext-createeffect)

[ID2D1Properties](https://learn.microsoft.com/windows/desktop/api/d2d1_1/nn-d2d1_1-id2d1properties)