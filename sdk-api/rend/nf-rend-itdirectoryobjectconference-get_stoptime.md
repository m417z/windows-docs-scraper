# ITDirectoryObjectConference::get_StopTime

## Description

[Rendezvous IP Telephony Conferencing controls and interfaces are not available for use in Windows Vista, Windows Server 2008, and subsequent versions of the operating system. The RTC Client API
provides similar functionality.]

The
**get_StopTime** method gets the stop time of the conference. If the end time is zero, the session is not bounded.

## Parameters

### `pDate` [out]

Pointer to the conference stop time.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Method succeeded. |
| **E_POINTER** | The *pDate* parameter is not a valid pointer. |
| **E_OUTOFMEMORY** | Insufficient memory exists to perform the operation. |
| **E_FAIL** | Unspecified error. |
| **E_NOTIMPL** | This method is not yet implemented. |

## See also

[ITDirectoryObjectConference](https://learn.microsoft.com/windows/desktop/api/rend/nn-rend-itdirectoryobjectconference)

[ITDirectoryObjectConference::put_StopTime](https://learn.microsoft.com/windows/desktop/api/rend/nf-rend-itdirectoryobjectconference-put_stoptime)