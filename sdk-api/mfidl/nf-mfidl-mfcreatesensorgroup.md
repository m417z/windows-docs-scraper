# MFCreateSensorGroup function

## Description

Creates an instance of the [IMFSensorGroup](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfsensorgroup) interface based on the provided symbolic link name.

## Parameters

### `SensorGroupSymbolicLink`

The symbolic link for the new [IMFSensorGroup](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfsensorgroup). This name can be obtained through device enumeration APIs such as [SetupDiGetClassDevs](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupdigetclassdevsw) or [MFEnumDeviceSources](https://learn.microsoft.com/windows/desktop/api/mfidl/nf-mfidl-mfenumdevicesources) or by getting the [Id](https://learn.microsoft.com/uwp/api/Windows.Devices.Enumeration.DeviceInformation) property of the [DeviceInformation](https://learn.microsoft.com/uwp/api/Windows.Devices.Enumeration.DeviceInformation) class.

### `ppSensorGroup` [out]

The symbolic link for the new [IMFSensorGroup](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfsensorgroup).

## Return value

The function returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_POINTER** | The supplied [IMFSensorGroup](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfsensorgroup) is null. |
| **E_INVALIDARG** | The supplied **LPCWSTR** is null. |

## Remarks

If the function succeeds, *ppSensorGroup* will point to a valid [IMFSensorGroup](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfsensorgroup) object. The caller must release this interface.

**Note** When this API is used with a [KSCATEGORY_SENSOR_CAMERA](https://learn.microsoft.com/previous-versions/ff548567(v=vs.85)) or [KSCATEGORY_VIDEO_CAMERA](https://learn.microsoft.com/previous-versions/ff548567(v=vs.85)) symbolic name, the resulting [IMFSensorGroup](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfsensorgroup) object will only contain one sensor device but behaves as a virtualized sensor group. The caller may use the resulting object in the same manner as a sensor group obtained from a [KSCATEGORY_SENSOR_GROUP](https://learn.microsoft.com/previous-versions/ff548567(v=vs.85)).