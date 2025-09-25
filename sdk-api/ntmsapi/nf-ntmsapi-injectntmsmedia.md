# InjectNtmsMedia function

## Description

[[Removable Storage Manager](https://learn.microsoft.com/previous-versions/windows/desktop/bb540725(v=vs.85)) is no longer available as of Windows 7 and Windows Server 2008 R2.]

The
**InjectNtmsMedia** function allows media to be inserted into the port of the specified library. If the library is busy, RSM queues
**InjectNtmsMedia** and returns success.

## Parameters

### `hSession` [in]

Handle to the session returned by the
[OpenNtmsSession](https://learn.microsoft.com/windows/desktop/api/ntmsapi/nf-ntmsapi-openntmssessiona) function.

### `lpLibraryId` [in]

Unique identifier of a library object.

### `lpInjectOperation` [out]

GUID of the insert library operation. If *dwAction* is NTMS_INJECT_START, this parameter receives the GUID for the operation. If *dwAction* is NTMS_INJECT_STOP, this parameter must be set to the GUID for the operation to be stopped.

### `dwAction` [in]

This parameter can be one of the following values.

| Value | Meaning |
| --- | --- |
| **NTMS_INJECT_START** | Start the insert operation with a port. Media is repeatedly inserted until the time-out event occurs or the function is called again with NTMS_INJECT_STOP. |
| **NTMS_INJECT_STOP** | Terminate the insertion process prior to the time-out event lapsing. |
| **NTMS_INJECT_RETRACT** | Direct the library to retract the insert/eject port and check for media placed there by the operator. |
| **NTMS_INJECT_START_MANY** | Direct the insert/eject port to open continually and check for media placed there by the operator. If a medium is found, the insert/eject port is reopened to receive more media. |

## Return value

This function returns one of the following values.

| Value | Meaning |
| --- | --- |
| **ERROR_ACCESS_DENIED** | NTMS_CONTROL_ACCESS to the library is denied. Other security errors are also possible, but they would indicate a security subsystem error. |
| **ERROR_DATABASE_FAILURE** | The database is inaccessible or damaged. |
| **ERROR_DATABASE_FULL** | The database is full. |
| **ERROR_DEVICE_NOT_AVAILABLE** | The library is disabled. |
| **ERROR_INVALID_HANDLE** | The session ID is missing or is not valid. |
| **ERROR_INVALID_OPERATION** | A Stop action was performed on an operation ID that was not valid. |
| **ERROR_INVALID_PARAMETER** | The library ID or operation ID pointer is missing. |
| **ERROR_LIBRARY_OFFLINE** | The library ID refers to an offline library that cannot eject media. |
| **ERROR_NOT_ENOUGH_MEMORY** | There was an allocation failure during processing. |
| **ERROR_SUCCESS** | The insert is queued. |

## Remarks

This function returns to the application as soon as the insert request is queued.

If the library specified by the
**InjectNtmsMedia** function does not have a port, use the
[AccessNtmsLibraryDoor](https://learn.microsoft.com/windows/desktop/api/ntmsapi/nf-ntmsapi-accessntmslibrarydoor) function to insert and eject media.

This function cannot be used with the offline library.

Insert begins the process of inserting media into a library. Because libraries vary on the functionality of the NTMS_IEPORT object, each device may operate slightly differently. The following steps describe how RSM generally handles an inject:

**To insert media into a library**

1. Allow/unlock/extend the NTMS_IEPORT.
2. Poll for a full NTMS_IEPORT, a retracted NTMS_IEPORT, a Stop Inject command, or a time-out value. If none of these have occurred, continue to wait. (Multi-cartridge insert/eject ports are not scanned for full status.)
3. When one of the preceding events occurs, the NTMS_IEPORT is locked, each medium in the NTMS_IEPORT is moved to a slot, and an identify medium command is queued for each medium.

If there are not enough slots for the media in the NTMS_IEPORT object, the media remains in the NTMS_IEPORT object and an Operator Request is posted to have media removed from the library.

If there are no free slots, the
**InjectNtmsMedia** function receives an error.

## See also

[EjectNtmsMedia](https://learn.microsoft.com/windows/desktop/api/ntmsapi/nf-ntmsapi-ejectntmsmedia)

[Library Control Functions](https://learn.microsoft.com/previous-versions/windows/desktop/rsm/removable-storage-manager-functions)