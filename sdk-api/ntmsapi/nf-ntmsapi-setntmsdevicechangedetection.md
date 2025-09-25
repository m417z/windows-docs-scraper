# SetNtmsDeviceChangeDetection function

## Description

[[Removable Storage Manager](https://learn.microsoft.com/previous-versions/windows/desktop/bb540725(v=vs.85)) is no longer available as of Windows 7 and Windows Server 2008 R2.]

The
**SetNtmsDeviceChangeDetection** function sets one or more target devices for change detection.

## Parameters

### `hSession` [in]

Handle to the session returned by the
[OpenNtmsSession](https://learn.microsoft.com/windows/desktop/api/ntmsapi/nf-ntmsapi-openntmssessiona) function.

### `DetectHandle` [in]

Device change detection handle from
[BeginNtmsDeviceChangeDetection](https://learn.microsoft.com/windows/desktop/api/ntmsapi/nf-ntmsapi-beginntmsdevicechangedetection), or **NULL** for a single poll.

### `lpRequestId` [in]

Object identifier for the target device. This parameter can be one or more library, media type, or physical media GUIDs. All GUIDs must be the same type.

### `dwType` [in]

Type of object identifiers specified in the *lpObjectId* parameter. This parameter can be one of the following values from the
[NtmsObjectsTypes](https://learn.microsoft.com/windows/desktop/api/ntmsapi/ne-ntmsapi-ntmsobjectstypes) enumeration type: NTMS_LIBRARY, NTMS_MEDIA_TYPE, or NTMS_PHYSICAL_MEDIA.

### `dwCount` [in]

Number of object identifiers in *lpObjectId*.

## Return value

This function returns one of the following values.

| Value | Meaning |
| --- | --- |
| **ERROR_INVALID_HANDLE** | The session or detection handle is not valid. |
| **ERROR_INVALID_PARAMETER** | The object type is not valid. |
| **ERROR_INVALID_LIBRARY** | The specified library was not found. |
| **ERROR_INVALID_MEDIA** | The specified media or type was not found. |
| **ERROR_SUCCESS** | The operator request has been canceled. |

## Remarks

The device can be specified directly by passing library GUIDs or indirectly by passing physical media or media type GUIDs. When using the indirect specification, all stand-alone libraries that could contain the media or media type are detected. All devices specified continue to be detected until the device change detection handle is closed using the
[EndNtmsDeviceChangeDetection](https://learn.microsoft.com/windows/desktop/api/ntmsapi/nf-ntmsapi-endntmsdevicechangedetection) function.

This function can also be used to poll for changed media in the specified devices. This is typically used by a UI when opening a leaf node or implementing a refresh option.

## See also

[BeginNtmsDeviceChangeDetection](https://learn.microsoft.com/windows/desktop/api/ntmsapi/nf-ntmsapi-beginntmsdevicechangedetection)

[Change Detection Functions](https://learn.microsoft.com/previous-versions/windows/desktop/rsm/removable-storage-manager-functions)

[EndNtmsDeviceChangeDetection](https://learn.microsoft.com/windows/desktop/api/ntmsapi/nf-ntmsapi-endntmsdevicechangedetection)