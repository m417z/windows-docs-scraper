# PFNBLUETOOTH_GATT_EVENT_CALLBACK callback function

## Description

Profile drivers implement a Bluetooth GATT event callback to be called whenever the value of a specific characteristic changes.

## Parameters

### `EventType` [in]

The type of GATT event.

### `EventOutParameter` [in]

Pointer to a [BLUETOOTH_GATT_VALUE_CHANGED_EVENT](https://learn.microsoft.com/windows/win32/api/bthledef/ns-bthledef-bluetooth_gatt_value_changed_event) structure.

### `Context` [in, optional]

The context specified by the profile driver in the *CallbackContext* parameter of
the [BluetoothGATTRegisterEvent](https://learn.microsoft.com/windows/desktop/api/bluetoothleapis/nf-bluetoothleapis-bluetoothgattregisterevent) function
when the profile driver registered the GATT callback function.

## See also

[BLUETOOTH_GATT_VALUE_CHANGED_EVENT](https://learn.microsoft.com/windows/win32/api/bthledef/ns-bthledef-bluetooth_gatt_value_changed_event)

[BTH_LE_GATT_EVENT_TYPE](https://learn.microsoft.com/windows/desktop/api/bthledef/ne-bthledef-bth_le_gatt_event_type)

[BluetoothGATTRegisterEvent](https://learn.microsoft.com/windows/desktop/api/bluetoothleapis/nf-bluetoothleapis-bluetoothgattregisterevent)