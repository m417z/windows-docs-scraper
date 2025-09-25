# ITQueue::get_Name

## Description

The
**get_Name** method gets the queue name.

## Parameters

### `ppName` [out]

Pointer to **BSTR** representation of queue name.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Method succeeded. |
| **E_POINTER** | The *ppName* is not a valid pointer. |
| **E_OUTOFMEMORY** | Insufficient memory exists to perform the operation. |

## Remarks

The application must use
[SysFreeString](https://learn.microsoft.com/previous-versions/windows/desktop/api/oleauto/nf-oleauto-sysfreestring) to free the memory allocated for the *ppName* parameter.

## See also

[ITQueue](https://learn.microsoft.com/windows/desktop/api/tapi3cc/nn-tapi3cc-itqueue)