# BTH_LE_GATT_CHARACTERISTIC structure

## Description

The BTH_LE_GATT_CHARACTERISTIC structure describes a Bluetooth Low Energy (LE) generic attribute (GATT) profile characteristic.

## Members

### `ServiceHandle`

The handle to the Bluetooth LE GATT profile service.

### `CharacteristicUuid`

The Universally Unique ID (UUID) of the characteristic.

### `AttributeHandle`

The handle to the Bluetooth LE GATT profile attributes.

### `CharacteristicValueHandle`

The handle to the Bluetooth LE GATT profile characteristic value.

### `IsBroadcastable`

The characteristic can be broadcast.

### `IsReadable`

The characteristic can be read.

### `IsWritable`

The characteristic can be written to.

### `IsWritableWithoutResponse`

The characteristic can be written to without requiring a response.

### `IsSignedWritable`

The characteristic can be signed writable.

### `IsNotifiable`

The characteristic can be updated by the device through Handle Value Notifications, and the new value will be returned through the callback function registered via [BluetoothGATTRegisterEvent](https://learn.microsoft.com/windows/desktop/api/bluetoothleapis/nf-bluetoothleapis-bluetoothgattregisterevent).

### `IsIndicatable`

The characteristic can be updated by the device through Handle Value Indications, and the new value will be returned through the callback function registered via [BluetoothGATTRegisterEvent](https://learn.microsoft.com/windows/desktop/api/bluetoothleapis/nf-bluetoothleapis-bluetoothgattregisterevent).

### `HasExtendedProperties`

The characteristic has extended properties, which will be presented through a Characteristic Extended Properties descriptor.

## See also

[BTH_LE_UUID](https://learn.microsoft.com/windows/desktop/api/bthledef/ns-bthledef-bth_le_uuid)

[BluetoothGATTGetCharacteristicValue](https://learn.microsoft.com/windows/desktop/api/bluetoothleapis/nf-bluetoothleapis-bluetoothgattgetcharacteristicvalue)

[BluetoothGATTGetCharacteristics](https://learn.microsoft.com/windows/desktop/api/bluetoothleapis/nf-bluetoothleapis-bluetoothgattgetcharacteristics)

[BluetoothGATTSetCharacteristicValue](https://learn.microsoft.com/windows/desktop/api/bluetoothleapis/nf-bluetoothleapis-bluetoothgattsetcharacteristicvalue)