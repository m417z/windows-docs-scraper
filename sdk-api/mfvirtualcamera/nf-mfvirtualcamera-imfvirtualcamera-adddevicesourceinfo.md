## Description

Informs the pipeline the virtual camera will require exclusive control to the physical camera specified by the specified device symbolic name.

## Parameters

### `DeviceSourceInfo`

A **LPCWSTR** containing the symbolic name for the physical camera. This value is enumerated through the standard Windows enumeration APIs such as [MFEnumDeviceSources](https://learn.microsoft.com/windows/win32/api/mfidl/nf-mfidl-mfenumdevicesources) and [DeviceInformation](https://learn.microsoft.com/uwp/api/Windows.Devices.Enumeration.DeviceInformation)

## Return value

Returns an HRESULT value, including but not limited to the following values:

| Error code | Description |
|------------|-------------|
| S_OK | Succeeded |
| E_INVALIDARG | An input parameter is invalid. |

## Remarks

The function allows the Windows Camera Frame Server service to arbitrate access to the physical camera when the virtual camera is activated.

This API may be called repeatedly if the virtual camera requires exclusive access to more than one physical camera.

> [!NOTE]
> When the virtual camera is activated all physical cameras added to the virtual camera using this API will be marked as in use. So any attempt to access those physical cameras in non-shared mode will result in a sharing violation.

## See also

[MFEnumDeviceSources](https://learn.microsoft.com/windows/win32/api/mfidl/nf-mfidl-mfenumdevicesources)
[DeviceInformation](https://learn.microsoft.com/uwp/api/Windows.Devices.Enumeration.DeviceInformation)