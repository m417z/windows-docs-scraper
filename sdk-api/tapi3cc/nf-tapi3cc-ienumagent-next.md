# IEnumAgent::Next

## Description

The
**Next** method gets the next specified number of elements in the enumeration sequence.

## Parameters

### `celt` [in]

Number of elements requested.

### `ppElements` [out]

Pointer to
[ITAgent](https://learn.microsoft.com/windows/desktop/api/tapi3/nn-tapi3-itagent) pointer.

### `pceltFetched` [out]

Pointer to number of elements actually supplied. May be **NULL** if *celt* is one.

## Return value

This method can return one of these values.

| Value | Meaning |
| --- | --- |
| **S_OK** | Method returned *celt* number of elements. |
| **S_FALSE** | Number of elements remaining was less than *celt*. |
| **E_POINTER** | The *ppElements* parameter is not a valid pointer. |
| **E_OUTOFMEMORY** | Insufficient memory exists to perform the operation. |

## Remarks

TAPI calls the **AddRef** method on the
[ITAgent](https://learn.microsoft.com/windows/desktop/api/tapi3/nn-tapi3-itagent) interface returned by **IEnumAgent::Next**. The application must call **Release** on the
**ITAgent** interface to free resources associated with it.

## See also

[IEnumAgent](https://learn.microsoft.com/windows/desktop/api/tapi3/nn-tapi3-ienumagent)

[ITAgent](https://learn.microsoft.com/windows/desktop/api/tapi3/nn-tapi3-itagent)