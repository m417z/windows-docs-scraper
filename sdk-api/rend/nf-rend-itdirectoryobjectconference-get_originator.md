# ITDirectoryObjectConference::get_Originator

## Description

[Rendezvous IP Telephony Conferencing controls and interfaces are not available for use in Windows Vista, Windows Server 2008, and subsequent versions of the operating system. The RTC Client API
provides similar functionality.]

The
**get_Originator** method gets the originator's user name.

## Parameters

### `ppOriginator` [out]

Pointer to a **BSTR** containing the originator's user name.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Method succeeded. |
| **E_POINTER** | The *ppOriginator* parameter is not a valid pointer. |
| **E_OUTOFMEMORY** | Insufficient memory exists to perform the operation. |
| **E_FAIL** | Unspecified error. |
| **E_NOTIMPL** | This method is not yet implemented. |

## Remarks

The application must use
[SysFreeString](https://learn.microsoft.com/previous-versions/windows/desktop/api/oleauto/nf-oleauto-sysfreestring) to free the memory allocated for the *ppOriginator* parameter.

The originator's name, along with the machine name set in
[put_MachineAddress](https://learn.microsoft.com/windows/desktop/Tapi/itsdp-put-machineaddress), are collectively the originator of the conference, and both are in the o= line of the SDP.

## See also

[ITDirectoryObjectConference](https://learn.microsoft.com/windows/desktop/api/rend/nn-rend-itdirectoryobjectconference)

[ITDirectoryObjectConference::put_Originator](https://learn.microsoft.com/windows/desktop/api/rend/nf-rend-itdirectoryobjectconference-put_originator)