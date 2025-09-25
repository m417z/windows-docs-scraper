# ITDirectory::put_DefaultObjectTTL

## Description

[Rendezvous IP Telephony Conferencing controls and interfaces are not available for use in Windows Vista, Windows Server 2008, and subsequent versions of the operating system. The RTC Client API
provides similar functionality.]

 The
**put_DefaultObjectTTL** method sets the default
[time to live](https://learn.microsoft.com/windows/win32/tapi/t-tapgloss) (TTL) value, in seconds, for objects created. Only applies to dynamic servers. The minimum value is 300 seconds.

## Parameters

### `TTL` [in]

TTL value, in seconds.

## Return value

This method can return one of these values.

| Value | Meaning |
| --- | --- |
| **S_OK** | Method succeeded. |
| **E_INVALIDARG** | The *TTL* parameter is not valid. |
| **E_OUTOFMEMORY** | Insufficient memory exists to perform the operation. |
| **E_FAIL** | Unspecified error. |
| **E_NOTIMPL** | This method is not yet implemented. |

## See also

[ITDirectory](https://learn.microsoft.com/windows/desktop/api/rend/nn-rend-itdirectory)

[ITDirectory::get_DefaultObjectTTL](https://learn.microsoft.com/windows/desktop/api/rend/nf-rend-itdirectory-get_defaultobjectttl)