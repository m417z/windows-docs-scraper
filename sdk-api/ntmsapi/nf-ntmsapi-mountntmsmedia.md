# MountNtmsMedia function

## Description

[[Removable Storage Manager](https://learn.microsoft.com/previous-versions/windows/desktop/bb540725(v=vs.85)) is no longer available as of Windows 7 and Windows Server 2008 R2.]

The
**MountNtmsMedia** function synchronously mounts one or more pieces of media.

## Parameters

### `hSession` [in]

Handle to the session returned by the
[OpenNtmsSession](https://learn.microsoft.com/windows/desktop/api/ntmsapi/nf-ntmsapi-openntmssessiona) function.

### `lpMediaId` [in]

Array of unique identifiers of logical media or sides.

### `lpDriveId` [in, out]

Array of drive identifiers that corresponds to the list of media in the *lpMediaId* parameter. This array either specifies a list of drives to mount media into or receives the list of drives that media is mounted into on operation completion. See the NTMS_MOUNT_SPECIFIC_DRIVE value below. If the
**MountNtmsMedia** function times out prior to the completion of the mount, RSM does not return the list of drives.

### `dwCount` [in]

Number of media identifiers and drive identifiers passed in the *lpMediaId* and *lpDriveId* parameters. Note that *lpMediaId* and *lpDriveId* must point to the first element of equal-length arrays.

### `dwOptions` [in]

Options. This parameter can be one or more of the following values.

| Value | Meaning |
| --- | --- |
| **NTMS_MOUNT_SPECIFIC_DRIVE** | Mount the media into the specific drives provided in the *lpDriveId* parameter. |
| **NTMS_MOUNT_READ** | Mount the media for read access. Use this value to mount read-only media. |
| **NTMS_MOUNT_WRITE** | Mount the media for write access. Use this flag to prevent RSM from mounting Completed media. This value can be combined with NTMS_MOUNT_READ for read/write access. <br><br>RSM cannot mount Completed media if this flag is selected. |
| **NTMS_MOUNT_ERROR_NOT_AVAILABLE** | This value returns an error if the media or a drive is not available. |
| **NTMS_MOUNT_ERROR_OFFLINE** | Do not issue an operator request to mount offline media. Return an error if the media specified is not currently in a library. |

### `dwPriority` [in]

Priority of the mount used by RSM to allow access to drives. Priorities range from -15 to 15, with 15 the highest priority and 0 is the default. This parameter can also take one of the following constants. An application should pass NTMS_PRIORITY_NORMAL unless a special mount priority is required.

| Value | Meaning |
| --- | --- |
| **NTMS_PRIORITY_NORMAL** | Mounts that are not time critical. |
| **NTMS_PRIORITY_LOW** | Mounts performed as a background activity. |
| **NTMS_PRIORITY_HIGH** | Mounts that are time critical. |
| **NTMS_PRIORITY_LOWEST** | Lowest priority mount. |
| **NTMS_PRIORITY_HIGHEST** | Highest priority mount. |

### `dwTimeout` [in]

Maximum time allowed to mount the specified media, in milliseconds. Set this parameter to INFINITE to wait until the mount is completed.

### `lpMountInformation`

This parameter is reserved and should be **NULL**.

## Return value

This function returns one of the following values.

| Value | Meaning |
| --- | --- |
| **ERROR_ACCESS_DENIED** | NTMS_USE_ACCESS to the media pool or library that contains the media is denied; other security errors are also possible but they would indicate a security subsystem error. |
| **ERROR_BUSY** | The media or drives are busy. |
| **ERROR_CANCELLED** | The request was canceled by the [CloseNtmsSession](https://learn.microsoft.com/windows/desktop/api/ntmsapi/nf-ntmsapi-closentmssession) function. |
| **ERROR_DATABASE_FAILURE** | The database is inaccessible or damaged. |
| **ERROR_DATABASE_FULL** | The database is full. |
| **ERROR_DRIVE_MEDIA_MISMATCH** | The media and drive specified are not in the same library. |
| **ERROR_INVALID_DRIVE** | At least one of the specified drives is not valid. |
| **ERROR_INVALID_LIBRARY** | The library that contains the drives or media is not valid. |
| **ERROR_INVALID_MEDIA** | One or more of the media specified is not valid, or there are duplicate media IDs in list of media. |
| **ERROR_INVALID_STATE** | An unexpected media or device state occurred during mount. |
| **ERROR_MEDIA_OFFLINE** | The media is offline and cannot be mounted. |
| **ERROR_NOT_ENOUGH_MEMORY** | A memory allocation failure occurred during processing. |
| **ERROR_REQUEST_REFUSED** | The user canceled the request through the user interface. |
| **ERROR_RESOURCE_DISABLED** | One or more resources required to perform the mount are disabled. |
| **ERROR_SUCCESS** | The media has been mounted and is ready for use. |
| **ERROR_TIMEOUT** | The time-out event expired while attempting to acquire one or more required resources. The mount request has been canceled. |
| **ERROR_WRITE_PROTECT** | The media state is set to Completed and the NTMS_MOUNT_WRITE value was specified. |

## Remarks

The
**MountNtmsMedia** function queues a request to mount the specified media, then waits for the number of milliseconds specified in the *dwTimeout* parameter for the mount to complete or for an error to be detected. If RSM cannot complete the mount operation before *dwTimeout* expires, NTMS cancels the request and returns an error. If the specified media is in an offline library, the application might be blocked for an extended period of time. You can use the
[GetNtmsObjectInformation](https://learn.microsoft.com/windows/desktop/api/ntmsapi/nf-ntmsapi-getntmsobjectinformation) function to determine the current location of the specified medium. You can also use the NTMS_MOUNT_ERROR_OFFLINE value to generate an immediate error instead of an operator request when the media is offline.

If the specified medium is in use or a drive is not available, the process blocks up to the time-out value and returns ERROR_BUSY. If the NTMS_MOUNT_ERROR_NOT_AVAILABLE value is specified, the function returns an immediate error when a resource (media or drive) is not available.

The time-out value of INFINITE can be used to make the function wait without timing out. When a non-zero time-out value is specified in the *dwTimeout* parameter, RSM waits for all the media specified in *lpMediaId* to become mounted. If the specified time elapses before all the media is mounted, the
**MountNtmsMedia** function returns an error and cancels the request. The application can examine the status returned and resubmit the request if desired.

When multiple media to be mounted are specified with a single call, all the specified media must be in a single library. If any of the specified media are offline, none of the media will be mounted until all the media are online.

At the completion of the mount the drive state (for example, fix or variable mode) is not defined. The application must set up the drive.

The
[CloseNtmsSession](https://learn.microsoft.com/windows/desktop/api/ntmsapi/nf-ntmsapi-closentmssession) function can be used to cancel a mount that is pending. The default behavior is:

* If the specified medium is offline, RSM posts an operator request to mount the media and the
  **MountNtmsMedia** function waits for the period of time specified in the *dwTimeout* parameter.
* If the specified medium is online, RSM requests the mount.
* If a drive or media is not available, RSM sends the request and the
  **MountNtmsMedia** function waits for the period of time specified in the *dwTimeout* parameter.

## See also

[Media Services Functions](https://learn.microsoft.com/previous-versions/windows/desktop/rsm/removable-storage-manager-functions)