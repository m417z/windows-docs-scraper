# BLUETOOTH_LOCAL_SERVICE_INFO_STRUCT structure

## Description

The **BLUETOOTH_LOCAL_SERVICE_INFO** structure contains local service information for a Bluetooth device. This structure is used by the [BluetoothSetLocalServiceInfo](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/bb870603(v=vs.85)) function.

## Members

### `Enabled`

If **TRUE**, specifies that the advertised services are enabled; otherwise the advertised services are disabled.

### `btAddr`

A [BLUETOOTH_ADDRESS](https://learn.microsoft.com/windows/win32/api/bluetoothapis/ns-bluetoothapis-bluetooth_address_struct) structure that contains the address of a remote device. This address is used when advertising services to a device.

### `szName`

The service name. The maximum length of this string, including the null terminator, is **BLUETOOTH_MAX_SERVICE_NAME_SIZE** (256).

### `szDeviceString`

The local device name, if any, such as COM4 or LPT1. The maximum length of this string, including the null terminator, is **BLUETOOTH_DEVICE_NAME_SIZE** (256).

## Remarks

In the event the service is not associated with a specific device, **btAddr** should be set to **BTH_ADDR_NULL**.

## See also

[BluetoothSetLocalServiceInfo](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/bb870603(v=vs.85))