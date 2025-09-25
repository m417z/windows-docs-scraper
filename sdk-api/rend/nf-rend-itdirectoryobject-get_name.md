# ITDirectoryObject::get_Name

## Description

[Rendezvous IP Telephony Conferencing controls and interfaces are not available for use in Windows Vista, Windows Server 2008, and subsequent versions of the operating system. The RTC Client API
provides similar functionality.]

The
**get_Name** method gets the name of the directory object.

## Parameters

### `ppName` [out]

Pointer to **BSTR** representation of directory name.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Method succeeded. |
| **E_POINTER** | Invalid pointer. |
| **E_OUTOFMEMORY** | Insufficient memory exists to perform the operation. |

## Remarks

The application must use
[SysFreeString](https://learn.microsoft.com/previous-versions/windows/desktop/api/oleauto/nf-oleauto-sysfreestring) to free the memory allocated for the *ppName* parameter.

## See also

[ITDirectoryObject](https://learn.microsoft.com/windows/desktop/api/rend/nn-rend-itdirectoryobject)

[ITDirectoryObject::put_Name](https://learn.microsoft.com/windows/desktop/api/rend/nf-rend-itdirectoryobject-put_name)