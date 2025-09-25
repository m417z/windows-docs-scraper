# ITfReadOnlyProperty::GetContext

## Description

Obtains the context object for the property.

## Parameters

### `ppContext` [out]

Pointer to an [ITfContext](https://learn.microsoft.com/windows/desktop/api/msctf/nn-msctf-itfcontext) interface pointer that receives the context object. The caller must release this object when it is no longer required.

## Return value

This method can return one of these values.

| Value | Description |
| --- | --- |
| **S_OK** | The method was successful. |
| **E_INVALIDARG** | *ppContext* is invalid. |
| **E_FAIL** | An unspecified error occurred. |

## See also

[ITfContext](https://learn.microsoft.com/windows/desktop/api/msctf/nn-msctf-itfcontext)

[ITfReadOnlyProperty](https://learn.microsoft.com/windows/desktop/api/msctf/nn-msctf-itfreadonlyproperty)