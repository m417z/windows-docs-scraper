# ID2D1Properties::SetValueByName(PCWSTR,const T &)

## Description

Sets the named property to the given value. This is a template overload. See Remarks.

## Parameters

### `propertyName` [in]

The name of the property to set.

### `value` [in, ref]

The data to set. The method will convert this type to a BYTE* before setting it as the property value.

## Return value

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

```
template<typename T>
    HRESULT SetValueByName(
        _In_ PCWSTR propertyName,
        _In_ const T &value
        );
```

## See also

[ID2D1Properties](https://learn.microsoft.com/windows/desktop/api/d2d1_1/nn-d2d1_1-id2d1properties)