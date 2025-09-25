## Description

Creates an instance of [IMFCameraControlMonitor](https://learn.microsoft.com/windows/win32/api/mfidl/nn-mfidl-imfcameracontrolmonitor)

## Parameters

### `symbolicLink` [in]

String symbolic link name of the video capture device that is active.

### `callback` [in]

Pointer to an object that implements the [IMFCameraControlNotify](https://learn.microsoft.com/windows/win32/api/mfidl/nn-mfidl-imfcameracontrolnotify) callback interface.

### `ppCameraControlMonitor` [out]

Receives a pointer to the created **IMFCameraControlMonitor** object.

## Return value

An HRESULT including the following:

| Value | Description |
|-------|-------------|
| S_OK | Success. |
| E_INVALIDARG | The symbolic link specified in *symbolicLink* doesn't match a known camera device. |

## Remarks

The symbolic link can be obtained from an [MF_DEVSOURCE_ATTRIBUTE_SOURCE_TYPE_VIDCAP_SYMBOLIC_LINK](https://learn.microsoft.com/windows/win32/medfound/mf-devsource-attribute-source-type-vidcap-symbolic-link) attribute returned by [MFEnumDeviceSources](https://learn.microsoft.com/windows/win32/api/mfidl/nf-mfidl-mfenumdevicesources) or obtained by accessing the [DeviceInformation.Id](https://learn.microsoft.com/uwp/api/windows.devices.enumeration.deviceinformation.id) property obtained through the [Windows.Devices.Enumeration](https://learn.microsoft.com/uwp/api/windows.devices.enumeration) APIs.

## See also