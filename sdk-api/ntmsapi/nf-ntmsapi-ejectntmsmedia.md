# EjectNtmsMedia function

## Description

[[Removable Storage Manager](https://learn.microsoft.com/previous-versions/windows/desktop/bb540725(v=vs.85)) is no longer available as of Windows 7 and Windows Server 2008 R2.]

The
**EjectNtmsMedia** function ejects the specified medium from the port of the current library. If the library is busy, RSM queues
**EjectNtmsMedia** and returns success.

## Parameters

### `hSession` [in]

Handle to the session returned by the
[OpenNtmsSession](https://learn.microsoft.com/windows/desktop/api/ntmsapi/nf-ntmsapi-openntmssessiona) function.

### `lpMediaId` [in]

Unique identifier of a piece of physical media (PMID).

### `lpEjectOperation` [in, out]

GUID of the eject process library request. If *dwAction* is NTMS_EJECT_START, this parameter receives the GUID for the operation. If *dwAction* is NTMS_EJECT_STOP, this parameter must be set to the GUID for the operation to be stopped. This parameter is not used with NTMS_EJECT_QUEUE.

### `dwAction` [in]

Action to perform. This parameter can be one of the following values.

| Value | Meaning |
| --- | --- |
| **NTMS_EJECT_START** | Start the eject operation with a port. The specified medium is ejected until the time-out event occurs or the function is called again with NTMS_EJECT_STOP. The time-out value is specified in the library object and is applied to all ejections in the library. |
| **NTMS_EJECT_STOP** | Terminate the ejection process specified by *lpEjectOperation* before the time-out event lapses. |
| **NTMS_EJECT_QUEUE** | Queue the specified media for ejection. Used to group media for multi-slot NTMS_IEPORT objects. |

## Return value

This function returns one of the following values.

| Value | Meaning |
| --- | --- |
| **ERROR_ACCESS_DENIED** | NTMS_CONTROL_ACCESS to the library is denied. Other security errors are also possible, but they would indicate a security subsystem error. |
| **ERROR_BUSY** | More media was queued than slots available in the NTMS_IEPORT object. |
| **ERROR_DATABASE_FAILURE** | The database is inaccessible or damaged. |
| **ERROR_DATABASE_FULL** | The database is full. |
| **ERROR_DEVICE_NOT_AVAILABLE** | The library is disabled. |
| **ERROR_INVALID_HANDLE** | The session ID is missing or is not valid. |
| **ERROR_INVALID_OPERATION** | A stop was performed on an operation ID that was not valid. |
| **ERROR_INVALID_PARAMETER** | A library ID or operation ID pointer is missing. |
| **ERROR_LIBRARY_OFFLINE** | The library ID refers to an offline library that cannot eject media. |
| **ERROR_MEDIA_NOT_AVAILABLE** | The media is disabled. |
| **ERROR_NOT_ENOUGH_MEMORY** | There was an allocation failure during processing. |
| **ERROR_SUCCESS** | The eject is queued. |

## Remarks

The
**EjectNtmsMedia** function returns to the application as soon as the eject request is queued.

Media ejected using the
**EjectNtmsMedia** function is moved to the offline library or deleted from the database. Cleaner cartridges, import media, unrecognized media, and incompatible media are deleted when ejected.

The NTMS_EJECT_QUEUE flag is used to bundle or batch media marked for ejection into a multi-slot library. You can queue media for ejection using the queue action when the application has queued all the necessary media. The application uses the start command to begin the physical eject operation. If more media is queued than slots in the NTMS_IEPORT object,
**EjectNtmsMedia** returns ERROR_BUSY. To begin the physical eject operation, the application can use NTMS_EJECT_START with the last media ID or **NULL**.

If the media is currently in use (mounted or opened), this function returns an error.

If the library does not have a port, use the
[AccessNtmsLibraryDoor](https://learn.microsoft.com/windows/desktop/api/ntmsapi/nf-ntmsapi-accessntmslibrarydoor) function to insert and eject media.

The
**EjectNtmsMedia** function does not work with the offline library.

## See also

[InjectNtmsMedia](https://learn.microsoft.com/windows/desktop/api/ntmsapi/nf-ntmsapi-injectntmsmedia)

[Library Control Functions](https://learn.microsoft.com/previous-versions/windows/desktop/rsm/removable-storage-manager-functions)