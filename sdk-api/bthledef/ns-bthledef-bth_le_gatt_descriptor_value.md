## Description

The BTH_LE_GATT_DESCRIPTOR_VALUE structure describes a parent characteristic.

## Members

### `DescriptorType`

The type of the descriptor value.

### `DescriptorUuid`

The Universally Unique ID (UUID) of the descriptor value.

### `CharacteristicExtendedProperties`

Container structure for the different characteristic extended property members.

### `CharacteristicExtendedProperties.IsReliableWriteEnabled`

The parent characteristic value is reliable write enabled.

### `CharacteristicExtendedProperties.IsAuxiliariesWritable`

The characteristic user description descriptor is writable.

### `ClientCharacteristicConfiguration`

Container structure for the different client characteristic configuration members.

### `ClientCharacteristicConfiguration.IsSubscribeToNotification`

Whether the characteristic has been registered with the device to receive Handle Value Notifications. TRUE if the characteristic has been registered. Otherwise, FALSE.

### `ClientCharacteristicConfiguration.IsSubscribeToIndication`

Whether the characteristic has been registered with the device to receive Handle Value Indications. TRUE if the characteristic has been registered. Otherwise, FALSE.

### `ServerCharacteristicConfiguration`

Container structure for the different server characteristic configuration members.

### `ServerCharacteristicConfiguration.IsBroadcast`

The parent characteristic value can be broadcast.

### `CharacteristicFormat`

Container structure for the different characteristic format members.

### `CharacteristicFormat.Format`

The format of the parent characteristic value.

### `CharacteristicFormat.Exponent`

The exponent value to use to determine how the value of the characteristic value is further formatted.

### `CharacteristicFormat.Unit`

The unit of the characteristic value as defined in the Assigned Numbers specification.

### `CharacteristicFormat.NameSpace`

The name-space where the unit is defined in the Assigned Numbers specification.

### `CharacteristicFormat.Description`

The Universally Unique ID (UUID) that describes the format of the parent characteristic value.

### `DataSize`

The size, in bytes, of the descriptor value.

### `Data`

A pointer to the descriptor value data.

## See also

[BTH_LE_GATT_DESCRIPTOR_TYPE](https://learn.microsoft.com/windows/desktop/api/bthledef/ne-bthledef-bth_le_gatt_descriptor_type)

[BTH_LE_UUID](https://learn.microsoft.com/windows/desktop/api/bthledef/ns-bthledef-bth_le_uuid)

[BluetoothGATTGetDescriptorValue](https://learn.microsoft.com/windows/desktop/api/bluetoothleapis/nf-bluetoothleapis-bluetoothgattgetdescriptorvalue)

[BluetoothGATTSetDescriptorValue](https://learn.microsoft.com/windows/desktop/api/bluetoothleapis/nf-bluetoothleapis-bluetoothgattsetdescriptorvalue)