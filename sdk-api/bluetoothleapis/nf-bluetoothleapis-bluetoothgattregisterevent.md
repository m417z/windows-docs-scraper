# BluetoothGATTRegisterEvent function

## Description

The **BluetoothGATTRegisterEvent** function registers a routine to be called back during a characteristic value change event on the given characteristic identified by its characteristic handle.

## Parameters

### `hService` [in]

Handle to the service.

### `EventType` [in]

A value from [BTH_LE_GATT_EVENT_TYPE](https://learn.microsoft.com/windows/desktop/api/bthledef/ne-bthledef-bth_le_gatt_event_type). Currently, only **CharacteristicValueChangedEvent** is supported.

### `EventParameterIn` [in]

Pointer to a [BLUETOOTH_GATT_VALUE_CHANGED_EVENT_REGISTRATION](https://learn.microsoft.com/windows/win32/api/bthledef/ns-bthledef-bluetooth_gatt_value_changed_event_registration) structure to pass when the event is triggered.

### `Callback` [in]

The routine to call when the Characteristic value changes.

### `CallbackContext` [in, optional]

Context to pass to *Callback*.

### `pEventHandle` [out]

Pointer to buffer to receive a handle for the registration. Profile drivers must pass this handle when calling [BluetoothGATTUnregisterEvent](https://learn.microsoft.com/windows/desktop/api/bluetoothleapis/nf-bluetoothleapis-bluetoothgattunregisterevent).

### `Flags` [in]

Flags to modify the behavior of **BluetoothGATTRegisterEvent**:

| Flag | Description |
| --- | --- |
| **BLUETOOTH_GATT_FLAG_NONE** | The client does not have specific GATT requirements (default). |

## Return value

**BluetoothGATTRegisterEvent** returns the following values:

| Return code | Description |
| --- | --- |
| **S_OK** | The operation completed successfully. |
| **ERROR_ACCESS_DENIED** | Returned if both a parent service and a service handle are provided and the service hierarchy does not roll up to the provided parent service handle. |
| **ERROR_INVALID_PARAMETER** | A parameter was invalid. |

## See also

[BLUETOOTH_GATT_VALUE_CHANGED_EVENT_REGISTRATION](https://learn.microsoft.com/windows/win32/api/bthledef/ns-bthledef-bluetooth_gatt_value_changed_event_registration)

[BTH_LE_GATT_EVENT_TYPE](https://learn.microsoft.com/windows/desktop/api/bthledef/ne-bthledef-bth_le_gatt_event_type)

[Bluetooth GATT Event Callback Function](https://learn.microsoft.com/windows/desktop/api/bthledef/nc-bthledef-pfnbluetooth_gatt_event_callback)

[BluetoothGATTUnregisterEvent](https://learn.microsoft.com/windows/desktop/api/bluetoothleapis/nf-bluetoothleapis-bluetoothgattunregisterevent)