# ITDirectory::RefreshDirectoryObject

## Description

[Rendezvous IP Telephony Conferencing controls and interfaces are not available for use in Windows Vista, Windows Server 2008, and subsequent versions of the operating system. The RTC Client API
provides similar functionality.]

The
**RefreshDirectoryObject** method refreshes the
[time to live](https://learn.microsoft.com/windows/win32/tapi/t-tapgloss) (TTL) for an object on the server. Only applies to dynamic servers.

## Parameters

### `pDirectoryObject` [in]

Pointer to
[ITDirectoryObject](https://learn.microsoft.com/windows/desktop/api/rend/nn-rend-itdirectoryobject) to be refreshed.

## Return value

This method can return one of these values.

| Value | Meaning |
| --- | --- |
| **S_OK** | Method succeeded. |
| **E_POINTER** | The *pDirectoryObject* parameter is not a valid pointer. |
| **RND_NOT_CONNECTED** | The [ITDirectory::Connect](https://learn.microsoft.com/windows/desktop/api/rend/nf-rend-itdirectory-connect) method has not been invoked or did not succeed. |

## See also

[ITDirectory](https://learn.microsoft.com/windows/desktop/api/rend/nn-rend-itdirectory)