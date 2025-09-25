# BeginNtmsDeviceChangeDetection function

## Description

[[Removable Storage Manager](https://learn.microsoft.com/previous-versions/windows/desktop/bb540725(v=vs.85)) is no longer available as of Windows 7 and Windows Server 2008 R2.]

The
**BeginNtmsDeviceChangeDetection** function allows the application to begin a device change detection session.

## Parameters

### `hSession` [in]

Handle to the session returned by the
[OpenNtmsSession](https://learn.microsoft.com/windows/desktop/api/ntmsapi/nf-ntmsapi-openntmssessiona) function.

### `lpDetectHandle` [out]

Pointer to variable that receives the device change detection handle.

## Return value

This function returns one of the following values.

| Value | Meaning |
| --- | --- |
| **ERROR_INVALID_HANDLE** | The value of the *hSession* parameter is not a valid session handle. |
| **ERROR_SUCCESS** | The operator request has been canceled. |

## Remarks

After calling
**BeginNtmsDeviceChangeDetection**, the application can set the stand-alone libraries for which media change detection is required using the
[SetNtmsDeviceChangeDetection](https://learn.microsoft.com/windows/desktop/api/ntmsapi/nf-ntmsapi-setntmsdevicechangedetection) function. The Removable Storage Manager continues to detect changes for the devices specified until the change detection session is closed using the
[EndNtmsDeviceChangeDetection](https://learn.microsoft.com/windows/desktop/api/ntmsapi/nf-ntmsapi-endntmsdevicechangedetection) function.

## See also

[Change Detection Functions](https://learn.microsoft.com/previous-versions/windows/desktop/rsm/removable-storage-manager-functions)

[EndNtmsDeviceChangeDetection](https://learn.microsoft.com/windows/desktop/api/ntmsapi/nf-ntmsapi-endntmsdevicechangedetection)

[SetNtmsDeviceChangeDetection](https://learn.microsoft.com/windows/desktop/api/ntmsapi/nf-ntmsapi-setntmsdevicechangedetection)