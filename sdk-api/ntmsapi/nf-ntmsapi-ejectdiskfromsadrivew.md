# EjectDiskFromSADriveW function

## Description

[[Removable Storage Manager](https://learn.microsoft.com/previous-versions/windows/desktop/bb540725(v=vs.85)) is no longer available as of Windows 7 and Windows Server 2008 R2.]

The
**EjectDiskFromSADrive** function ejects the media that is in a standalone removable
drive.

## Parameters

### `lpComputerName` [in]

Removable Storage Manager (RSM) server name. If this parameter is **NULL**, the current computer name is used.

### `lpAppName` [in]

Unique character string that identifies the application. This name identifies resources and operator requests. This parameter is optional and may be **NULL**.

### `lpDeviceName` [in]

Name of the device to eject. For example, \\.\Cdrom0 or \\.\PhysicalDriveX (where X is the number of the drive being accessed).

### `hWnd` [in]

Handle to a dialog box window for user confirmation.

### `lpTitle` [in]

Title displayed in a dialog box to get user input.

### `lpMessage` [in]

Message displayed in a dialog box to get user input.

### `dwOptions` [in]

Action to perform. This parameter can be one of the following values.

| Value | Meaning |
| --- | --- |
| **NTMS_EJECT_START** | Start the eject operation with a port. The specified medium is ejected until the time-out event occurs or the function is called again with **NTMS_EJECT_STOP**. The time-out value is specified in the library object and is applied to all ejections in the library. |
| **NTMS_EJECT_STOP** | Terminate the ejection process before the time-out event lapses. |
| **NTMS_EJECT_QUEUE** | Allow the eject to be asynchronous. The function queues the specified media for ejection and then returns. |
| **NTMS_EJECT_FORCE** | Force the media to be ejected. For example, NTFS can hold locks on media, and this option will cause the media to be ejected despite that lock. |
| **NTMS_EJECT_IMMEDIATE** | Eject the media immediately and synchronously. The function will not return until the eject is complete. Does not queue the specified media for ejection. |
| **NTMS_EJECT_ASK_USER** | Eject the media immediately and synchronously. The function will not return until the eject is complete. Does not queue the specified media for ejection. If the eject operation fails, prompt the user to either cancel or force the operation. |

## Return value

This function returns one of the following values.

| Value | Meaning |
| --- | --- |
| **ERROR_ACCESS_DENIED** | NTMS_CONTROL_ACCESS to the library is denied. Other security errors are also possible, but they would indicate a security subsystem error. |
| **ERROR_DATABASE_FAILURE** | The database is inaccessible or damaged. |
| **ERROR_DATABASE_FULL** | The database is full. |
| **ERROR_DEVICE_NOT_AVAILABLE** | The library is disabled. |
| **ERROR_INVALID_HANDLE** | The session ID is missing or is not valid. |
| **ERROR_INVALID_OPERATION** | A stop was performed on an operation ID that was not valid. |
| **ERROR_INVALID_PARAMETER** | A library ID or operation ID pointer is missing. |
| **ERROR_LIBRARY_OFFLINE** | The library ID refers to an offline library that cannot eject media. |
| **ERROR_MEDIA_NOT_AVAILABLE** | The media is disabled. |
| **ERROR_NOT_ENOUGH_MEMORY** | There was an allocation failure during processing. |
| **ERROR_SUCCESS** | The eject operation was successful. |

## Remarks

Although [EjectNtmsMedia](https://learn.microsoft.com/windows/desktop/api/ntmsapi/nf-ntmsapi-ejectntmsmedia) can, in some cases, be used to accomplish the same functionality, **EjectDiskFromSADrive** provides a convenient way to eject media from a standalone device, by specifying its drive name instead of its RSM name. In some cases it is the only way to overcome file system locks on the media in order to eject that media.

The
**EjectDiskFromSADrive** function returns to the application as soon as the eject request is queued, unless **NTMS_EJECT_IMMEDIATE** option is specified.

Media ejected using the
**EjectDiskFromSADrive** function is moved to the offline library or deleted from the database. Import media, unrecognized media, and incompatible media are deleted when ejected.

The
**EjectDiskFromSADrive** function does not work with the offline library.

> [!NOTE]
> The ntmsapi.h header defines EjectDiskFromSADrive as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[EjectNtmsMedia](https://learn.microsoft.com/windows/desktop/api/ntmsapi/nf-ntmsapi-ejectntmsmedia)

[InjectNtmsMedia](https://learn.microsoft.com/windows/desktop/api/ntmsapi/nf-ntmsapi-injectntmsmedia)

[Library Control Functions](https://learn.microsoft.com/previous-versions/windows/desktop/rsm/removable-storage-manager-functions)