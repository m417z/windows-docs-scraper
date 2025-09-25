# ID2D1Properties::GetValueByName(PCWSTR,BYTE,UINT32)

## Description

Gets the property value by name.

## Parameters

### `name` [in]

Type: **PCWSTR**

The property name to get.

### `data` [out]

Type: **BYTE***

When this method returns, contains the buffer with the data value.

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

## Remarks

If *name* does not exist, no information is retrieved.

Any error not in the standard set returned by a property implementation will be mapped into the standard error range.

## See also

[ID2D1DeviceContext::CreateEffect](https://learn.microsoft.com/windows/desktop/api/d2d1_1/nf-d2d1_1-id2d1devicecontext-createeffect)

[ID2D1Properties](https://learn.microsoft.com/windows/desktop/api/d2d1_1/nn-d2d1_1-id2d1properties)