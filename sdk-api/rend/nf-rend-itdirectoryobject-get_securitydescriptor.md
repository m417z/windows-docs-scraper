# ITDirectoryObject::get_SecurityDescriptor

## Description

[Rendezvous IP Telephony Conferencing controls and interfaces are not available for use in Windows Vista, Windows Server 2008, and subsequent versions of the operating system. The RTC Client API
provides similar functionality.]

The
**get_SecurityDescriptor** method gets an **IDispatch** pointer on a directory service security descriptor object describing current security permissions. For additional information on security descriptors, please search the Platform Software Development Kit (SDK) under "IADsSecurityDescriptor".

## Parameters

### `ppSecDes` [out]

**IDispatch** pointer on a directory service security descriptor object.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Method succeeded. |
| **E_POINTER** | The *ppSecDes* parameter is not a valid pointer. |
| **E_FAIL** | Initialization of security descriptor failed. |
| **E_OUTOFMEMORY** | Insufficient memory exists to perform the operation. |

## Remarks

If the security descriptor has not been set, this method will set *ppSecDes* to **NULL**.

## See also

[ITDirectoryObject](https://learn.microsoft.com/windows/desktop/api/rend/nn-rend-itdirectoryobject)

[ITDirectoryObject::put_SecurityDescriptor](https://learn.microsoft.com/windows/desktop/api/rend/nf-rend-itdirectoryobject-put_securitydescriptor)