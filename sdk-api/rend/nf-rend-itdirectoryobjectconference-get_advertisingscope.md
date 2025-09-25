# ITDirectoryObjectConference::get_AdvertisingScope

## Description

[Rendezvous IP Telephony Conferencing controls and interfaces are not available for use in Windows Vista, Windows Server 2008, and subsequent versions of the operating system. The RTC Client API
provides similar functionality.]

The
**get_AdvertisingScope** method gets the advertising scope.

## Parameters

### `pAdvertisingScope` [out]

Pointer to
[RND_ADVERTISING_SCOPE](https://learn.microsoft.com/windows/desktop/api/rend/ne-rend-rnd_advertising_scope) enumeration.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Method succeeded. |
| **E_POINTER** | The *pAdvertisingScope* parameter is not a valid pointer. |
| **E_OUTOFMEMORY** | Insufficient memory exists to perform the operation. |
| **E_FAIL** | Unspecified error. |
| **E_NOTIMPL** | This method is not yet implemented. |

## See also

[ITDirectoryObjectConference](https://learn.microsoft.com/windows/desktop/api/rend/nn-rend-itdirectoryobjectconference)

[ITDirectoryObjectConference::put_AdvertisingScope](https://learn.microsoft.com/windows/desktop/api/rend/nf-rend-itdirectoryobjectconference-put_advertisingscope)

[RND_ADVERTISING_SCOPE](https://learn.microsoft.com/windows/desktop/api/rend/ne-rend-rnd_advertising_scope)