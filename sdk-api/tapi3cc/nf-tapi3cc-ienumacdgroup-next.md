# IEnumACDGroup::Next

## Description

The
**Next** method gets the next specified number of elements in the enumeration sequence.

## Parameters

### `celt` [in]

Number of elements requested.

### `ppElements` [out]

Pointer to
[ITACDGroup](https://learn.microsoft.com/windows/desktop/api/tapi3/nn-tapi3-itacdgroup) list of pointers returned.

### `pceltFetched` [in, out]

Pointer to number of elements actually supplied. May be **NULL** if *celt* is one.

## Return value

This method can return one of these values.

| Value | Meaning |
| --- | --- |
| **S_OK** | Method returned *celt* number of elements. |
| **S_FALSE** | Number of elements remaining was less than *celt*. |
| **E_OUTOFMEMORY** | Insufficient memory exists to perform the operation. |
| **E_POINTER** | The *ppElements* parameter is not a valid pointer. |

## Remarks

TAPI calls the **AddRef** method on the
[ITACDGroup](https://learn.microsoft.com/windows/desktop/api/tapi3/nn-tapi3-itacdgroup) interface returned by **IEnumACDGroup::Next**. The application must call **Release** on the
**ITACDGroup** interface to free resources associated with it.

## See also

[IEnumACDGroup](https://learn.microsoft.com/windows/desktop/api/tapi3/nn-tapi3-ienumacdgroup)

[ITACDGroup](https://learn.microsoft.com/windows/desktop/api/tapi3/nn-tapi3-itacdgroup)