# IDeviceController::streaming

## Description

Adds a DLNA DMR or DMS Device, identified by its UPnP Unique Device Name (UDN), to the list of devices that is returned by the [CachedDevices](https://learn.microsoft.com/windows/desktop/mediastreaming/idevicecontroller-cacheddevices) method.

## Parameters

### `uniqueDeviceName` [in]

A string representing the device’s UDN.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## See also

[IDeviceController](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/hh828901(v=vs.85))