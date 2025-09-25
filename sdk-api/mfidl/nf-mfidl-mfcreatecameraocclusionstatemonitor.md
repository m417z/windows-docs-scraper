## Description

Creates a new instance of [IMFCameraOcclusionStateMonitor](https://learn.microsoft.com/windows/win32/api/mfidl/nn-mfidl-imfcameraocclusionstatemonitor) which allows an application to receive notifications when the camera occlusion state changes.

## Parameters

### `symbolicLink`

The symbolic link name of the video device for which occlusion state will be monitored. This value is enumerated through the standard Windows enumeration APIs such as [MFEnumDeviceSources](https://learn.microsoft.com/windows/win32/api/mfidl/nf-mfidl-mfenumdevicesources) and [DeviceInformation](https://learn.microsoft.com/uwp/api/Windows.Devices.Enumeration.DeviceInformation)

### `callback`

The [IMFCameraOcclusionStateReportCallback](https://learn.microsoft.com/windows/win32/api/mfidl/nn-mfidl-imfcameraocclusionstatereportcallback) implemented by the client to receive camera occlusion state change notifications.

### `occlusionStateMonitor`

An output parameter that receives the [IMFCameraOcclusionStateMonitor](https://learn.microsoft.com/windows/win32/api/mfidl/nf-mfidl-mfcreatecameraocclusionstatemonitor).

## Return value

Returns an HRESULT value, including but not limited to the following values:

| Error code | Description |
|------------|-------------|
| S_OK | Succeeded |
| E_INVALIDARG | One or more parameters is nullptr |

## Remarks

## See also