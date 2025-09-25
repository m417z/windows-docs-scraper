# ITRequestEvent::get_Comment

## Description

The
**get_Comment** method gets the comment.

## Parameters

### `ppComment` [out]

Pointer to a **BSTR** containing the comment.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Method succeeded. |
| **E_POINTER** | The *ppComment* is not a valid pointer. |
| **E_OUTOFMEMORY** | Insufficient memory exists to perform the operation. |

## Remarks

The application must use
[SysFreeString](https://learn.microsoft.com/previous-versions/windows/desktop/api/oleauto/nf-oleauto-sysfreestring) to free the memory allocated for the *ppComment* parameter.

## See also

[ITRequestEvent](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itrequestevent)