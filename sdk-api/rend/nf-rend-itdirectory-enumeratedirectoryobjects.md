# ITDirectory::EnumerateDirectoryObjects

## Description

[Rendezvous IP Telephony Conferencing controls and interfaces are not available for use in Windows Vista, Windows Server 2008, and subsequent versions of the operating system. The RTC Client API
provides similar functionality.]

The
**EnumerateDirectoryObjects** method creates an enumeration of directory objects of a given type and name.

## Parameters

### `DirectoryObjectType` [in]

The
[DIRECTORY_OBJECT_TYPE](https://learn.microsoft.com/windows/desktop/api/rend/ne-rend-directory_object_type) criteria for object desired.

### `pName` [in]

Pointer to a **BSTR** containing the full or partial name of the object. The "*" wildcard is supported.

### `ppEnumObject` [out]

Pointer to receive
[IEnumDirectoryObject](https://learn.microsoft.com/windows/desktop/api/rend/nn-rend-ienumdirectoryobject) interface pointer for the enumerator of matching objects.

## Return value

This method can return one of these values.

| Value | Meaning |
| --- | --- |
| **S_OK** | Method succeeded. |
| **RND_NOT_CONNECTED** | The [ITDirectory::Connect](https://learn.microsoft.com/windows/desktop/api/rend/nf-rend-itdirectory-connect) method has not been invoked or did not succeed. |
| **E_NOTIMPL** | This method is not implemented. |

## Remarks

The application must use
[SysAllocString](https://learn.microsoft.com/previous-versions/windows/desktop/api/oleauto/nf-oleauto-sysallocstring) to allocate memory for the *pName* parameter and use
[SysFreeString](https://learn.microsoft.com/previous-versions/windows/desktop/api/oleauto/nf-oleauto-sysfreestring) to free the memory when the variable is no longer needed.

TAPI calls the **AddRef** method on the
[IEnumDirectoryObject](https://learn.microsoft.com/windows/desktop/api/rend/nn-rend-ienumdirectoryobject) interface returned by **ITDirectory::EnumerateDirectoryObjects**. The application must call **Release** on the
**IEnumDirectoryObject** interface to free resources associated with it.

## See also

[DIRECTORY_OBJECT_TYPE](https://learn.microsoft.com/windows/desktop/api/rend/ne-rend-directory_object_type)

[IEnumDirectoryObject](https://learn.microsoft.com/windows/desktop/api/rend/nn-rend-ienumdirectoryobject)

[ITDirectory](https://learn.microsoft.com/windows/desktop/api/rend/nn-rend-itdirectory)