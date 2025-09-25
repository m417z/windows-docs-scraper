# ITRendezvous::CreateDirectoryObject

## Description

[Rendezvous IP Telephony Conferencing controls and interfaces are not available for use in Windows Vista, Windows Server 2008, and subsequent versions of the operating system. The RTC Client API
provides similar functionality.]

 The
**CreateDirectoryObject** method creates a new
[ITDirectoryObject](https://learn.microsoft.com/windows/desktop/api/rend/nn-rend-itdirectoryobject) object.

## Parameters

### `DirectoryObjectType` [in]

The type of the object. See
[DIRECTORY_OBJECT_TYPE](https://learn.microsoft.com/windows/desktop/api/rend/ne-rend-directory_object_type).

### `pName` [in]

Pointer to a **BSTR** containing the name of the object.

### `ppDirectoryObject` [out]

Pointer to receive the interface pointer for the newly created
[ITDirectoryObject](https://learn.microsoft.com/windows/desktop/api/rend/nn-rend-itdirectoryobject) object.

## Return value

This method can return one of these values.

| Value | Meaning |
| --- | --- |
| **S_OK** | Method succeeded. |
| **E_INVALIDARG** | The *DirectoryObjectType* parameter is not valid. |
| **E_OUTOFMEMORY** | Insufficient memory exists to perform the operation. |
| **E_POINTER** | Pointer is invalid. |

## Remarks

The application must use
[SysAllocString](https://learn.microsoft.com/previous-versions/windows/desktop/api/oleauto/nf-oleauto-sysallocstring) to allocate memory for the *pName* parameter and use
[SysFreeString](https://learn.microsoft.com/previous-versions/windows/desktop/api/oleauto/nf-oleauto-sysfreestring) to free the memory when the variable is no longer needed.

TAPI calls the **AddRef** method on the
[ITDirectoryObject](https://learn.microsoft.com/windows/desktop/api/rend/nn-rend-itdirectoryobject) interface returned by **ITRendezvous::CreateDirectoryObject**. The application must call **Release** on the
**ITDirectoryObject** interface to free resources associated with it.

This function may send data over the wire in unencrypted form; therefore, someone eavesdropping on the network may be able to read the data. The security risk of sending the data in clear text should be considered before using this method.

## See also

[DIRECTORY_OBJECT_TYPE](https://learn.microsoft.com/windows/desktop/api/rend/ne-rend-directory_object_type)

[ITDirectoryObject](https://learn.microsoft.com/windows/desktop/api/rend/nn-rend-itdirectoryobject)

[ITRendezvous](https://learn.microsoft.com/windows/desktop/api/rend/nn-rend-itrendezvous)