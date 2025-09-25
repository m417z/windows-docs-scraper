# IEnumDirectoryObject::Next

## Description

[Rendezvous IP Telephony Conferencing controls and interfaces are not available for use in Windows Vista, Windows Server 2008, and subsequent versions of the operating system. The RTC Client API
provides similar functionality.]

The
**Next** method gets the next specified number of elements in the enumeration sequence.

## Parameters

### `celt` [in]

Number of elements requested.

### `pVal` [out]

Pointer to the
[ITDirectoryObject](https://learn.microsoft.com/windows/desktop/api/rend/nn-rend-itdirectoryobject) interface.

### `pcFetched` [out]

Pointer to the number of elements actually supplied. May be **NULL** if *celt* is one.

## Return value

This method can return one of these values.

| Value | Meaning |
| --- | --- |
| **S_OK** | Method returned *celt* number of elements. |
| **S_FALSE** | Number of elements remaining was less than *celt*. |
| **E_POINTER** | The *pVal* parameter is not a valid pointer. |

## Remarks

TAPI calls the **AddRef** method on the
[ITDirectoryObject](https://learn.microsoft.com/windows/desktop/api/rend/nn-rend-itdirectoryobject) interface returned by **IEnumDirectoryObject::Next**. The application must call **Release** on the
**ITDirectoryObject** interface to free resources associated with it.

## See also

[IEnumDirectoryObject](https://learn.microsoft.com/windows/desktop/api/rend/nn-rend-ienumdirectoryobject)