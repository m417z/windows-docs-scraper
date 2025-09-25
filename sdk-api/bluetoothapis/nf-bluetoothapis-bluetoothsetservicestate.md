# BluetoothSetServiceState function

## Description

The **BluetoothSetServiceState** function enables or disables services for a Bluetooth device.

## Parameters

### `hRadio`

A handle of the local Bluetooth radio.

### `pbtdi`

A pointer to a [BLUETOOTH_DEVICE_INFO](https://learn.microsoft.com/windows/win32/api/bluetoothapis/ns-bluetoothapis-bluetooth_device_info_struct) structure. Must be a previously found radio address.

### `pGuidService`

A pointer to the service GUID on the remote device.

### `dwServiceFlags`

The flags that adjust the service. To disable the service, set to **BLUETOOTH_SERVICE_DISABLE**; to enable the service, set to **BLUETOOTH_SERVICE_ENABLE**.

## Return value

Returns **ERROR_SUCCESS** upon successful completion. The following table lists common errors.

| Return code | Description |
| --- | --- |
| **ERROR_INVALID_PARAMETER** | The *dwServiceFlags* are not valid. |
| **ERROR_SERVICE_DOES_NOT_EXIST** | The GUID specified in *pGuidService* is not supported. |
| **E_INVALIDARG** | *dwServiceFlags* is set to **BLUETOOTH_SERVICE_DISABLE** and the service is already disabled, or *dwServiceFlags* is set to **BLUETOOTH_SERVICE_ENABLE** and the service is already enabled. |

## Remarks

Windows maintains a mapping of service Globally Unique Identifiers (GUIDs) to supported drivers for
Bluetooth-enabled devices. Enabling a service installs the corresponding
device driver and disabling a service removes the corresponding device driver.
If a non-supported service is enabled, a driver is not installed.

## See also

[BLUETOOTH_DEVICE_INFO](https://learn.microsoft.com/windows/win32/api/bluetoothapis/ns-bluetoothapis-bluetooth_device_info_struct)

[BLUETOOTH_DEVICE_SEARCH_PARAMS](https://learn.microsoft.com/windows/win32/api/bluetoothapis/ns-bluetoothapis-bluetooth_device_search_params)

[BluetoothDisplayDeviceProperties](https://learn.microsoft.com/windows/desktop/api/bluetoothapis/nf-bluetoothapis-bluetoothdisplaydeviceproperties)

[BluetoothFindDeviceClose](https://learn.microsoft.com/windows/desktop/api/bluetoothapis/nf-bluetoothapis-bluetoothfinddeviceclose)

[BluetoothFindFirstDevice](https://learn.microsoft.com/windows/desktop/api/bluetoothapis/nf-bluetoothapis-bluetoothfindfirstdevice)

[BluetoothFindNextDevice](https://learn.microsoft.com/windows/desktop/api/bluetoothapis/nf-bluetoothapis-bluetoothfindnextdevice)

[BluetoothGetDeviceInfo](https://learn.microsoft.com/windows/desktop/api/bluetoothapis/nf-bluetoothapis-bluetoothgetdeviceinfo)

[BluetoothRemoveDevice](https://learn.microsoft.com/windows/desktop/api/bluetoothapis/nf-bluetoothapis-bluetoothremovedevice)