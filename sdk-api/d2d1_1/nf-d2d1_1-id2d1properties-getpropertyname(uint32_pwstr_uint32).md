# ID2D1Properties::GetPropertyName(UINT32,PWSTR,UINT32)

## Description

Gets the property name that corresponds to the given index.

## Parameters

### `index`

Type: **UINT32**

The index of the property for which the name is being returned.

### `name` [out]

Type: **PWSTR**

When this method returns, contains the name being retrieved.

### `nameCount`

Type: **UINT32**

The number of characters in the *name* buffer.

## Return value

Type: **HRESULT**

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| HRESULT | Description |
| --- | --- |
| S_OK | No error occurred. |
| HRESULT_FROM_WIN32(ERROR_INSUFFICIENT_BUFFER) | The supplied buffer was too small to accommodate the data. |
| D2DERR_INVALID_PROPERTY | The specified property does not exist. |

## Remarks

This method returns an empty string if *index* is invalid. If the method returns **RESULT_FROM_WIN32(ERROR_INSUFFICIENT_BUFFER)**, *name* will still be filled and truncated.

## See also

[D2D1_PROPERTY](https://learn.microsoft.com/windows/desktop/api/d2d1_1/ne-d2d1_1-d2d1_property)

[D2D1_SUBPROPERTY](https://learn.microsoft.com/windows/desktop/api/d2d1_1/ne-d2d1_1-d2d1_subproperty)

[ID2D1DeviceContext::CreateEffect](https://learn.microsoft.com/windows/desktop/api/d2d1_1/nf-d2d1_1-id2d1devicecontext-createeffect)

[ID2D1Properties](https://learn.microsoft.com/windows/desktop/api/d2d1_1/nn-d2d1_1-id2d1properties)