# ITDirectory::get_DefaultObjectTTL

## Description

[Rendezvous IP Telephony Conferencing controls and interfaces are not available for use in Windows Vista, Windows Server 2008, and subsequent versions of the operating system. The RTC Client API
provides similar functionality.]

The
**get_DefaultObjectTTL** method gets the default
[time to live](https://learn.microsoft.com/windows/win32/tapi/t-tapgloss) (TTL) value, in seconds, for objects created. Only applies to dynamic servers.

## Parameters

### `pTTL` [out]

Pointer to TTL value, in seconds.

## Return value

This method can return one of these values.

| Value | Meaning |
| --- | --- |
| **S_OK** | Method succeeded. |
| **E_POINTER** | The *pTTL* parameter is not a valid pointer. |
| **E_OUTOFMEMORY** | Insufficient memory exists to perform the operation. |
| **E_FAIL** | Unspecified error. |
| **E_NOTIMPL** | This method is not yet implemented. |

## See also

[ITDirectory](https://learn.microsoft.com/windows/desktop/api/rend/nn-rend-itdirectory)

[ITDirectory::put_DefaultObjectTTL](https://learn.microsoft.com/windows/desktop/api/rend/nf-rend-itdirectory-put_defaultobjectttl)