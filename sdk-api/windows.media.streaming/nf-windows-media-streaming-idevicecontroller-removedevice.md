# IDeviceController::streaming

## Description

Removes the specified device from the list of devices that is returned by the [CachedDevices](https://learn.microsoft.com/windows/desktop/mediastreaming/idevicecontroller-cacheddevices) method.

## Parameters

### `device` [in]

A reference to an [IBasicDevice](https://learn.microsoft.com/windows/desktop/mediastreaming/ibasicdevice) that represents the device to remove from the list.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## See also

[IDeviceController](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/hh828901(v=vs.85))