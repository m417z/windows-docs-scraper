# ITDirectoryObject::put_SecurityDescriptor

## Description

[Rendezvous IP Telephony Conferencing controls and interfaces are not available for use in Windows Vista, Windows Server 2008, and subsequent versions of the operating system. The RTC Client API
provides similar functionality.]

The
**put_SecurityDescriptor** method sets an **IDispatch** pointer on a directory service security descriptor object describing current security permissions. For additional information on security descriptors, please search the Platform Software Development Kit (SDK) under "IADsSecurityDescriptor".

## Parameters

### `pSecDes` [in]

**IDispatch** pointer on a directory service security descriptor object.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Method succeeded. |
| **E_POINTER** | The *pSecDes* parameter is not a valid pointer. |
| **E_OUTOFMEMORY** | Insufficient memory exists to perform the operation. |
| **E_FAIL** | Unspecified error. |
| **E_NOTIMPL** | This method is not yet implemented. |

## Remarks

Changes made will not take effect on the server until the
[ITDirectory::ModifyDirectoryObject](https://learn.microsoft.com/windows/desktop/api/rend/nf-rend-itdirectory-modifydirectoryobject) method is called.

## See also

[ITDirectoryObject](https://learn.microsoft.com/windows/desktop/api/rend/nn-rend-itdirectoryobject)

[ITDirectoryObject::get_SecurityDescriptor](https://learn.microsoft.com/windows/desktop/api/rend/nf-rend-itdirectoryobject-get_securitydescriptor)