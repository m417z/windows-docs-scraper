# IEnumMcastScope::Next

## Description

[Rendezvous IP Telephony Conferencing controls and interfaces are not available for use in Windows Vista, Windows Server 2008, and subsequent versions of the operating system. The RTC Client API
provides similar functionality.]

The
**Next** method gets the next specified number of elements in the enumeration sequence.

## Parameters

### `celt` [in]

Number of elements requested.

### `ppScopes` [out]

Pointer to the
[IMcastScope](https://learn.microsoft.com/windows/desktop/api/mdhcp/nn-mdhcp-imcastscope) interface.

### `pceltFetched` [out]

Pointer to the number of elements actually supplied. May be **NULL** if *celt* is one.

## Return value

This method can return one of these values.

| Value | Meaning |
| --- | --- |
| **S_OK** | Method returned *celt* number of elements. |
| **S_FALSE** | Number of elements remaining was less than *celt*. |
| **E_POINTER** | The *ppScopes* parameter is not a valid pointer. |

## Remarks

TAPI calls the **AddRef** method on the
[IMcastScope](https://learn.microsoft.com/windows/desktop/api/mdhcp/nn-mdhcp-imcastscope) interface returned by **IEnumMcastScope::Next**. The application must call **Release** on the
**IMcastScope** interface to free resources associated with it.

## See also

[IEnumMcastScope](https://learn.microsoft.com/windows/desktop/api/mdhcp/nn-mdhcp-ienummcastscope)