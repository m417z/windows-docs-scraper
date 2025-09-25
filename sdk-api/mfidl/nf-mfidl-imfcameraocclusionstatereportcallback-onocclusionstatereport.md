## Description

Called by the system when the camera occlusion state changes.

## Parameters

### `occlusionStateReport`

An [IMFCameraOcclusionStateReport](https://learn.microsoft.com/windows/win32/api/mfidl/nn-mfidl-imfcameraocclusionstatereport) that can be used to obtain the new camera occlusion state.

## Return value

If this method succeeds, it returns S_OK. Otherwise, it returns an HRESULT error code.

## Remarks

To avoid any possible circular locking situation do not call any IMFCameraOcclusionStateMonitor object methods from this callback function.

Register the callback interface by calling [MFCreateCameraOcclusionStateMonitor](https://learn.microsoft.com/windows/win32/api/mfidl/nf-mfidl-mfcreatecameraocclusionstatemonitor).

## See also

[MFCreateCameraOcclusionStateMonitor](https://learn.microsoft.com/windows/win32/api/mfidl/nf-mfidl-mfcreatecameraocclusionstatemonitor)

[IMFCameraOcclusionStateReport](https://learn.microsoft.com/windows/win32/api/mfidl/nn-mfidl-imfcameraocclusionstatereport)