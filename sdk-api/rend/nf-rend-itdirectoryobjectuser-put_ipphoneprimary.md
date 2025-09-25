# ITDirectoryObjectUser::put_IPPhonePrimary

## Description

[Rendezvous IP Telephony Conferencing controls and interfaces are not available for use in Windows Vista, Windows Server 2008, and subsequent versions of the operating system. The RTC Client API
provides similar functionality.]

 The
**put_IPPhonePrimary** method sets the name of a machine as the primary IP phone for a user.

## Parameters

### `pName` [in]

Pointer to the **BSTR** representation of the user's IP primary phone.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Method succeeded. |
| **E_POINTER** | Invalid pointer. |

## Remarks

This method can be used only on a new object that is subsequently added to the directory. If an application wants to modify the IP phone of an existing user object, it has to enumerate the objects from the server to determine the old IP phones are. This implies that a TAPI 3 application is running on one or more other machines. The application on a local machine has no information about whether those other applications are still running. Therefore, it is not the application's place to change the IP Phone on existing user objects.

To modify an existing user's IP Phone, the user must be deleted and re-added.

The application must use
[SysAllocString](https://learn.microsoft.com/previous-versions/windows/desktop/api/oleauto/nf-oleauto-sysallocstring) to allocate memory for the *pName* parameter and use
[SysFreeString](https://learn.microsoft.com/previous-versions/windows/desktop/api/oleauto/nf-oleauto-sysfreestring) to free the memory when the variable is no longer needed.

This function may send data over the wire in unencrypted form; therefore, someone eavesdropping on the network may be able to read the data. The security risk of sending the data in clear text should be considered before using this method.

## See also

[ITDirectoryObjectUser](https://learn.microsoft.com/windows/desktop/api/rend/nn-rend-itdirectoryobjectuser)

[ITDirectoryObjectUser::get_IPPhonePrimary](https://learn.microsoft.com/windows/desktop/api/rend/nf-rend-itdirectoryobjectuser-get_ipphoneprimary)