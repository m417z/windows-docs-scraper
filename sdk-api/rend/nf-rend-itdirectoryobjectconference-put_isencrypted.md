# ITDirectoryObjectConference::put_IsEncrypted

## Description

[Rendezvous IP Telephony Conferencing controls and interfaces are not available for use in Windows Vista, Windows Server 2008, and subsequent versions of the operating system. The RTC Client API
provides similar functionality.]

The
**put_IsEncrypted** method sets whether the conference is encrypted.

## Parameters

### `fEncrypted` [in]

Indicator of whether the conference is encrypted.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Method succeeded. |
| **E_INVALIDARG** | The *fEncrypted* parameter is not valid. |
| **E_OUTOFMEMORY** | Insufficient memory exists to perform the operation. |
| **E_FAIL** | Unspecified error. |
| **E_NOTIMPL** | This method is not yet implemented. |

## See also

[ITDirectoryObjectConference](https://learn.microsoft.com/windows/desktop/api/rend/nn-rend-itdirectoryobjectconference)

[ITDirectoryObjectConference::get_IsEncrypted](https://learn.microsoft.com/windows/desktop/api/rend/nf-rend-itdirectoryobjectconference-get_isencrypted)