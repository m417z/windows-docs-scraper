# EnumerateNtmsObject function

## Description

[[Removable Storage Manager](https://learn.microsoft.com/previous-versions/windows/desktop/bb540725(v=vs.85)) is no longer available as of Windows 7 and Windows Server 2008 R2.]

The
**EnumerateNtmsObject** function enumerates the RSM objects contained in the *lpContainerId* parameter.

## Parameters

### `hSession` [in]

Handle to the session returned by the
[OpenNtmsSession](https://learn.microsoft.com/windows/desktop/api/ntmsapi/nf-ntmsapi-openntmssessiona) function.

### `lpContainerId` [in]

Unique identifier of the RSM object container whose objects are to be enumerated. This parameter can be the GUID of a library, media pool, partition ID, physical media, or logical media. To enumerate all objects of the type specified by the *dwType* parameter, regardless of the container, set this parameter to **NULL**. For more information about the object-container relationship, see
[NtmsObjectsTypes](https://learn.microsoft.com/windows/desktop/api/ntmsapi/ne-ntmsapi-ntmsobjectstypes).

### `lpList` [out]

Buffer for the array of libraries, drives, media or other RSM object IDs.

### `lpdwListSize` [in, out]

Pointer to a variable that specifies the maximum number of IDs the function can return through the *lpList* parameter. At return time, the number of IDs in *lpList* is returned in *lpdwListSize*.

### `dwType` [in]

Type of objects to be enumerated in the *lpContainerId* container. If *lpContainerId* is **NULL**, all objects of this type supported by RSM are enumerated. This parameter can be one of the following values from the
[NtmsObjectsTypes](https://learn.microsoft.com/windows/desktop/api/ntmsapi/ne-ntmsapi-ntmsobjectstypes) enumeration type.

| Value | Meaning |
| --- | --- |
| **NTMS_CHANGER** | Changers. <br><br>The *lpContainerId* parameter must be **NULL** or a library GUID. |
| **NTMS_CHANGER_TYPE** | Changer types. <br><br>The *lpContainerId* parameter must be **NULL**. |
| **NTMS_COMPUTER** | Current computer object. <br><br>The *lpContainerId* parameter must be **NULL**. |
| **NTMS_DRIVE** | Drives. <br><br>The *lpContainerId* parameter must be **NULL** or a library GUID. |
| **NTMS_DRIVE_TYPE** | Drive types. <br><br>The *lpContainerId* parameter must be **NULL**. |
| **NTMS_IEDOOR** | Doors. <br><br>The *lpContainerId* parameter must be **NULL** or a library GUID. |
| **NTMS_IEPORT** | Insert/eject ports contained in a library specified by the *lpContainerId* parameter or all the insert/eject ports supported by RSM if a **NULL** container ID is supplied. <br><br>The *lpContainerId* parameter must be **NULL** or a library GUID. |
| **NTMS_LIBRARY** | Library objects. These include the physical library units and the offline library. <br><br>The *lpContainerId* parameter must be **NULL**. |
| **NTMS_LIBREQUEST** | Library active requests (or work items) queued to the library specified by the *lpContainerId* parameter or all the library work items queued within RSM if a **NULL** container ID is supplied. <br><br>The *lpContainerId* parameter must be **NULL** or a library GUID. |
| **NTMS_LOGICAL_MEDIA** | Logical media object. This is a medium allocated to an application that might contain more than one side or piece of physical media. <br><br>The *lpContainerId* parameter must be NUL, a media pool GUID, or a partition GUID. |
| **NTMS_MEDIA_POOL** | Media pool object that contains logical and/or physical media, and configuration parameters to manage them. If **NULL** is specified as a container ID, only the top-level names are returned. <br><br>The *lpContainerId* parameter must be **NULL** or a media pool GUID. |
| **NTMS_MEDIA_TYPE** | Media type object that contains the attributes of a type of medium that is supported by RSM. Enumerating with a **NULL** will give all possible media types, not just those available on the current server. <br><br>The *lpContainerId* parameter must be **NULL** or a library GUID. |
| **NTMS_OPREQUEST** | Operator requests that are on this RSM server. <br><br>The *lpContainerId* parameter must be **NULL**. |
| **NTMS_PARTITION** | Side on a piece of physical media. The piece of physical media can contain multiple physical sides (for example, an optical disk contains two sides). <br><br>The *lpContainerId* parameter must be **NULL**, a logical media GUID, a physical media GUID, or a media pool GUID. |
| **NTMS_PHYSICAL_MEDIA** | Item of physical media (a tape, optical disk, CD-ROM, or magnetic cartridge). A piece of physical media can contain multiple physical sides (for example, sides of an optical disk). <br><br>The *lpContainerId* parameter must be **NULL**, a media pool GUID, or a library GUID. |
| **NTMS_STORAGESLOT** | Media slots contained in a library specified by the *lpContainerId* parameter or all the storage slots supported by RSM if a **NULL** container ID is supplied. <br><br>The *lpContainerId* parameter must be **NULL** or a library GUID. |

### `dwOptions` [in]

Enumeration options. This is applicable only when *dwType* is NTMS_MEDIA_POOL.

| Value | Meaning |
| --- | --- |
| **NTMS_ENUM_ROOTPOOL** | This enumerates the root pool in addition to all other top-level media pools; it is always returned as the first GUID in the list. Enumerating the root pool is only required to get or set the security attributes on the object. *dwType* must be NTMS_MEDIA_POOL and *lpContainerId* must be **NULL**. |
| **NTMS_ENUM_DEFAULT** | Does not include enumeration of the root pool when enumerating the media pools. |

**Windows XP:** This parameter is reserved and must be set to zero.

## Return value

This function returns one of the following values.

| Value | Meaning |
| --- | --- |
| **ERROR_INVALID_PARAMETER** | The *lpdwListSize* pointer is missing, or *lpContainerId* is not a valid container for the object type specified by *dwType*. |
| **ERROR_INSUFFICIENT_BUFFER** | The buffer size specified by *lpdwListSize* is too small for all the objects found. The function truncates the list and returns the actual size in *lpdwListSize*. |
| **ERROR_INVALID_HANDLE** | The session handle is missing or is not valid. |
| **ERROR_NOT_ENOUGH_MEMORY** | An allocation failure occurred during processing. |
| **ERROR_OBJECT_NOT_FOUND** | The GUID specified by *lpContainerId* is not the GUID of any container object in the database. |
| **ERROR_SUCCESS** | The function was successful. If *lpContainerId* contains no objects of the type specified by *dwType*, the function returns ERROR_SUCCESS and a *lpdwListSize* of zero. |

## Remarks

Security functions are also available to get and set specific access rights on RSM objects.

If the available number of IDs specified in the *lpdwListSize* parameter is greater than the current buffer size, *lpdwListSize* returns the number of IDs required. The application should then allocate a larger buffer and try again.

Since it is possible for IDs to be added by another process, it is possible for a subsequent function with a resized list to get an error indicating that the list is too small.

If the *lpContainerId* parameter is set to **NULL**, RSM enumerates top-level objects (such as libraries).

If more than one object is listed, the object may be enumerated from more than one container. The **NULL** container is the highest-level container and enumerates all objects in a system. For example, you can enumerate media in a particular library or all media in the system.

## See also

[CreateNtmsMediaPool](https://learn.microsoft.com/windows/desktop/api/ntmsapi/nf-ntmsapi-createntmsmediapool)

[GetNtmsObjectInformation](https://learn.microsoft.com/windows/desktop/api/ntmsapi/nf-ntmsapi-getntmsobjectinformation)

[GetNtmsObjectSecurity](https://learn.microsoft.com/windows/desktop/api/ntmsapi/nf-ntmsapi-getntmsobjectsecurity)

[Object Management Functions](https://learn.microsoft.com/previous-versions/windows/desktop/rsm/removable-storage-manager-functions)

[SetNtmsObjectInformation](https://learn.microsoft.com/windows/desktop/api/ntmsapi/nf-ntmsapi-setntmsobjectinformation)

[SetNtmsObjectSecurity](https://learn.microsoft.com/windows/desktop/api/ntmsapi/nf-ntmsapi-setntmsobjectsecurity)