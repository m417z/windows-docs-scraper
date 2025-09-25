# ID2D1Properties::GetValue

## Description

Gets the value of the specified property by index.

## Parameters

### `index`

Type: **UINT32**

The index of the property from which the data is to be obtained.

### `type`

TBD

### `data` [out]

Type: **BYTE***

When this method returns, contains a pointer to the data requested.

### `dataSize`

Type: **UINT32**

The number of bytes in the data to be retrieved.

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

## See also

[D2D1_PROPERTY](https://learn.microsoft.com/windows/desktop/api/d2d1_1/ne-d2d1_1-d2d1_property)

[D2D1_SUBPROPERTY](https://learn.microsoft.com/windows/desktop/api/d2d1_1/ne-d2d1_1-d2d1_subproperty)

[ID2D1DeviceContext::CreateEffect](https://learn.microsoft.com/windows/desktop/api/d2d1_1/nf-d2d1_1-id2d1devicecontext-createeffect)

[ID2D1Properties](https://learn.microsoft.com/windows/desktop/api/d2d1_1/nn-d2d1_1-id2d1properties)