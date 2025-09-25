# IEnumDirectory::Next

## Description

[Rendezvous IP Telephony Conferencing controls and interfaces are not available for use in Windows Vista, Windows Server 2008, and subsequent versions of the operating system. The RTC Client API
provides similar functionality.]

The
**Next** method gets the next specified number of elements in the enumeration sequence.

## Parameters

### `celt` [in]

Number of elements requested.

### `ppElements` [out]

Pointer to the
[ITDirectory](https://learn.microsoft.com/windows/desktop/api/rend/nn-rend-itdirectory) interface.

### `pcFetched` [out]

Pointer to the number of elements actually supplied. May be **NULL** if *celt* is one.

## Return value

This method can return one of these values.

| Value | Meaning |
| --- | --- |
| **S_OK** | Method returned *celt* number of elements. |
| **S_FALSE** | Number of elements remaining was less than *celt*. |
| **E_POINTER** | The *ppElements* parameter is not a valid pointer. |

## Remarks

TAPI calls the **AddRef** method on the
[ITDirectory](https://learn.microsoft.com/windows/desktop/api/rend/nn-rend-itdirectory) interface returned by **IEnumDirectory::Next**. The application must call **Release** on the
**ITDirectory** interface to free resources associated with it.

## See also

[IEnumDirectory](https://learn.microsoft.com/windows/desktop/api/rend/nn-rend-ienumdirectory)