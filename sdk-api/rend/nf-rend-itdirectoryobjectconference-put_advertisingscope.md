# ITDirectoryObjectConference::put_AdvertisingScope

## Description

[Rendezvous IP Telephony Conferencing controls and interfaces are not available for use in Windows Vista, Windows Server 2008, and subsequent versions of the operating system. The RTC Client API
provides similar functionality.]

The
**put_AdvertisingScope** method sets the advertising scope.

## Parameters

### `AdvertisingScope` [in]

Pointer to
[RND_ADVERTISING_SCOPE](https://learn.microsoft.com/windows/desktop/api/rend/ne-rend-rnd_advertising_scope) enumeration.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Method succeeded. |
| **E_INVALIDARG** | The *AdvertisingScope* parameter is not valid. |
| **E_OUTOFMEMORY** | Insufficient memory exists to perform the operation. |
| **E_FAIL** | Unspecified error. |
| **E_NOTIMPL** | This method is not yet implemented. |

## Remarks

This function may send data over the wire in unencrypted form; therefore, someone eavesdropping on the network may be able to read the data. The security risk of sending the data in clear text should be considered before using this method.

## See also

[ITDirectoryObjectConference](https://learn.microsoft.com/windows/desktop/api/rend/nn-rend-itdirectoryobjectconference)

[ITDirectoryObjectConference::get_AdvertisingScope](https://learn.microsoft.com/windows/desktop/api/rend/nf-rend-itdirectoryobjectconference-get_advertisingscope)

[RND_ADVERTISING_SCOPE](https://learn.microsoft.com/windows/desktop/api/rend/ne-rend-rnd_advertising_scope)