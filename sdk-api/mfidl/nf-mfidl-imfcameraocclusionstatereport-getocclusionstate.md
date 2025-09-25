## Description

Gets the camera occlusion state associated with the occlusion state report.

## Parameters

### `occlusionState`

A **DWORD** output parameter containing a value from the [MFCameraOcclusionState](https://learn.microsoft.com/windows/win32/api/mfidl/ne-mfidl-mfcameraocclusionstate) enumeration.

## Return value

| Error code | Description |
|------------|-------------|
| S_OK | Succeeded |
| E_INVALIDARG | *occlusionState* is nullptr. |

## Remarks

## See also

[MFCameraOcclusionState](https://learn.microsoft.com/windows/win32/api/mfidl/ne-mfidl-mfcameraocclusionstate)