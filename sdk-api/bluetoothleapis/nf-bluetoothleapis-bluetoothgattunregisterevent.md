# BluetoothGATTUnregisterEvent function

## Description

The **BluetoothGATTUnregisterEvent** function unregisters the given characteristic value change event.

## Parameters

### `EventHandle` [in]

Handle returned from a previous call to [BluetoothGATTRegisterEvent](https://learn.microsoft.com/windows/desktop/api/bluetoothleapis/nf-bluetoothleapis-bluetoothgattregisterevent).

### `Flags` [in]

Flags to modify the behavior of **BluetoothGATTUnregisterEvent**:

| Flag | Description |
| --- | --- |
| **BLUETOOTH_GATT_FLAG_NONE** | The client does not have specific GATT requirements (default). |

## Return value

**BluetoothGATTUnregisterEvent** returns the following values:

| Return code | Description |
| --- | --- |
| **S_OK** | The operation completed successfully. |
| **ERROR_ACCESS_DENIED** | Returned if both a parent service and a service handle are provided and the service hierarchy does not roll up to the provided parent service handle. |
| **ERROR_INVALID_PARAMETER** | A parameter was invalid. |

## See also

[BluetoothGATTRegisterEvent](https://learn.microsoft.com/windows/desktop/api/bluetoothleapis/nf-bluetoothleapis-bluetoothgattregisterevent)