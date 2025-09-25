# IEnumSubStream::Next

## Description

The
**Next** method gets the next specified number of elements in the enumeration sequence.

## Parameters

### `celt` [in]

Number of elements requested.

### `ppElements` [out]

Pointer to
[ITSubStream](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itsubstream) pointers returned.

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

TAPI calls the [AddRef](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-addref) method on the
[ITSubStream](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itsubstream) interface returned by **IEnumSubStream::Next**. The application must call [Release](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-release) on the
**ITSubStream** interface to free resources associated with it.

## See also

[IEnumSubStream](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-ienumsubstream)

[ITSubStream](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itsubstream)

[Media Service Provider Interface (MSPI)](https://learn.microsoft.com/windows/desktop/Tapi/media-service-provider-interface-mspi-)