# ITDirectoryObject::get_ObjectType

## Description

[Rendezvous IP Telephony Conferencing controls and interfaces are not available for use in Windows Vista, Windows Server 2008, and subsequent versions of the operating system. The RTC Client API
provides similar functionality.]

The
**get_ObjectType** method gets a
[DIRECTORY_OBJECT_TYPE](https://learn.microsoft.com/windows/desktop/api/rend/ne-rend-directory_object_type) descriptor of the object.

## Parameters

### `pObjectType` [out]

Pointer to descriptor of directory object type.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Method succeeded. |
| **E_POINTER** | Invalid pointer. |

## See also

[DIRECTORY_OBJECT_TYPE](https://learn.microsoft.com/windows/desktop/api/rend/ne-rend-directory_object_type)

[ITDirectoryObject](https://learn.microsoft.com/windows/desktop/api/rend/nn-rend-itdirectoryobject)