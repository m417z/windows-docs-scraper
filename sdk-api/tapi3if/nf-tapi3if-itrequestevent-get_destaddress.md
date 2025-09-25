# ITRequestEvent::get_DestAddress

## Description

The
**get_DestAddress** method gets the destination address.

## Parameters

### `ppDestAddress` [out]

Pointer to a **BSTR** containing the destination address.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Method succeeded. |
| **E_POINTER** | The *ppDestAddress* is not a valid pointer. |
| **E_OUTOFMEMORY** | Insufficient memory exists to perform the operation. |

## Remarks

The application must use
[SysFreeString](https://learn.microsoft.com/previous-versions/windows/desktop/api/oleauto/nf-oleauto-sysfreestring) to free the memory allocated for the *ppDestAddress* parameter.

## See also

[ITRequestEvent](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itrequestevent)