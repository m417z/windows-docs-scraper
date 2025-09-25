## Description

Specifies the occlusion state of a camera.

## Constants

### `MFCameraOcclusionState_Open`

The camera is not occluded.

### `MFCameraOcclusionState_OccludedByLid`

The camera is occluded by the lid of the device.

### `MFCameraOcclusionState_OccludedByCameraHardware`

The camera is occluded by camera hardware.

## Remarks

A value from this enumeration is returned by [IMFCameraOcclusionStateReport::GetOcclusionState](https://learn.microsoft.com/windows/win32/api/mfidl/nf-mfidl-imfcameraocclusionstatereport-getocclusionstate). To get the occlusion states that are supported on the current device, and therefore may be returned by **GetOcclusionState**, call [IMFCameraOcclusionStateMonitor::GetSupportedStates](https://learn.microsoft.com/windows/win32/api/mfidl/nf-mfidl-imfcameraocclusionstatemonitor-getsupportedstates).

## See also

[IMFCameraOcclusionStateReport::GetOcclusionState](https://learn.microsoft.com/windows/win32/api/mfidl/nf-mfidl-imfcameraocclusionstatereport-getocclusionstate)

[IMFCameraOcclusionStateMonitor::GetSupportedStates](https://learn.microsoft.com/windows/win32/api/mfidl/nf-mfidl-imfcameraocclusionstatemonitor-getsupportedstates)