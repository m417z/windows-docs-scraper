# EndNtmsDeviceChangeDetection function

## Description

[[Removable Storage Manager](https://learn.microsoft.com/previous-versions/windows/desktop/bb540725(v=vs.85)) is no longer available as of Windows 7 and Windows Server 2008 R2.]

The
**EndNtmsDeviceChangeDetection** function ends device change detection for any target devices specified using the
[SetNtmsDeviceChangeDetection](https://learn.microsoft.com/windows/desktop/api/ntmsapi/nf-ntmsapi-setntmsdevicechangedetection) function and closes the change detection handle.

## Parameters

### `hSession` [in]

Handle to the session returned by the
[OpenNtmsSession](https://learn.microsoft.com/windows/desktop/api/ntmsapi/nf-ntmsapi-openntmssessiona) function

### `DetectHandle` [in]

Device change detection handle returned by the
[BeginNtmsDeviceChangeDetection](https://learn.microsoft.com/windows/desktop/api/ntmsapi/nf-ntmsapi-beginntmsdevicechangedetection) function.

## Return value

This function returns one of the following values.

| Value | Meaning |
| --- | --- |
| **ERROR_INVALID_HANDLE** | The session handle or detection handle is not valid. |
| **ERROR_SUCCESS** | The operator request has been canceled. |

## Remarks

Closing the Removable Storage Manager session also ends all device change detection sessions.

## See also

[BeginNtmsDeviceChangeDetection](https://learn.microsoft.com/windows/desktop/api/ntmsapi/nf-ntmsapi-beginntmsdevicechangedetection)

[Change Detection Functions](https://learn.microsoft.com/previous-versions/windows/desktop/rsm/removable-storage-manager-functions)

[SetNtmsDeviceChangeDetection](https://learn.microsoft.com/windows/desktop/api/ntmsapi/nf-ntmsapi-setntmsdevicechangedetection)