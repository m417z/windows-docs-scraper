# ITDirectoryObjectUser::get_IPPhonePrimary

## Description

[Rendezvous IP Telephony Conferencing controls and interfaces are not available for use in Windows Vista, Windows Server 2008, and subsequent versions of the operating system. The RTC Client API
provides similar functionality.]

The
**get_IPPhonePrimary** method gets the name of a computer that is the primary IP phone for the user.

## Parameters

### `ppName` [out]

Pointer to the **BSTR** representation of the user's IP primary phone.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Method succeeded. |
| **E_POINTER** | Invalid pointer. |

## Remarks

The application must use
[SysFreeString](https://learn.microsoft.com/previous-versions/windows/desktop/api/oleauto/nf-oleauto-sysfreestring) to free the memory allocated for the *ppName* parameter.

## See also

[ITDirectoryObjectUser](https://learn.microsoft.com/windows/desktop/api/rend/nn-rend-itdirectoryobjectuser)

[ITDirectoryObjectUser::put_IPPhonePrimary](https://learn.microsoft.com/windows/desktop/api/rend/nf-rend-itdirectoryobjectuser-put_ipphoneprimary)