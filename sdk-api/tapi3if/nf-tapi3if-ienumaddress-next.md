# IEnumAddress::Next

## Description

The
**Next** method gets the next specified number of elements in the enumeration sequence. This method is hidden from Visual Basic and scripting languages.

## Parameters

### `celt` [in]

Number of elements requested.

### `ppElements` [out]

Pointer to
[ITAddress](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itaddress) pointer.

### `pceltFetched` [out]

Pointer to number of elements actually supplied. May be **NULL** if *celt* is one.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Method returned *celt* number of elements. |
| **S_FALSE** | Number of elements remaining was less than *celt*. |
| **E_POINTER** | The *ppElements* parameter is not a valid pointer. |
| **E_OUTOFMEMORY** | Insufficient memory exists to perform the operation. |

## Remarks

TAPI calls the [AddRef](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-addref) method on the
[ITAddress](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itaddress) interface returned by this method. The application must call [Release](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-release) on the
**ITAddress** interface to free resources associated with it.

## See also

[IEnumAddress](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-ienumaddress)

[ITAddress](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itaddress)