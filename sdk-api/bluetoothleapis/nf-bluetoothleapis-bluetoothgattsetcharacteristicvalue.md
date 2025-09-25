# BluetoothGATTSetCharacteristicValue function

## Description

The **BluetoothGATTSetCharacteristicValue** function writes the specified characteristic value to the Bluetooth device.

## Parameters

### `hDevice` [in]

Handle to the service.

### `Characteristic` [in]

Pointer to [BTH_LE_GATT_CHARACTERISTIC](https://learn.microsoft.com/windows/desktop/api/bthledef/ns-bthledef-bth_le_gatt_characteristic) structure containing the parent characteristic.

### `CharacteristicValue` [in]

Pointer to [BTH_LE_GATT_CHARACTERISTIC_VALUE](https://learn.microsoft.com/windows/desktop/api/bthledef/ns-bthledef-bth_le_gatt_characteristic_value) structure containing the characteristic value.

### `ReliableWriteContext` [in, optional]

BTH_LE_GATT_RELIABLE_WRITE_CONTEXT structure containing the context describing the reliable write operation returned from a previous call to [BluetoothGATTBeginReliableWrite](https://learn.microsoft.com/windows/desktop/api/bluetoothleapis/nf-bluetoothleapis-bluetoothgattbeginreliablewrite).

### `Flags` [in]

Flags to modify the behavior of BluetoothGATTSetCharacteristicValue:

| Flag | Description |
| --- | --- |
| **BLUETOOTH_GATT_FLAG_NONE** | The client does not have specific GATT requirements (default). |
| **BLUETOOTH_GATT_FLAG_CONNECTION_ENCRYPTED** | The client requests the data to be transmitted over an encrypted channel. |
| **BLUETOOTH_GATT_FLAG_CONNECTION_AUTHENTICATED** | The client requests the data to be transmitted over an authenticated channel. |
| **BLUETOOTH_GATT_FLAG_WRITE_WITHOUT_RESPONSE** | Write without response. |
| **BLUETOOTH_GATT_FLAG_SIGNED_WRITE** | Signed write. Profile drivers must use with **BLUETOOTH_GATT_FLAG_WRITE_WITHOUT_RESPONSE** in order to produce signed write without a response. |

## Return value

The **BluetoothGATTSetCharacteristicValue** function returns the following values:

| Return code | Description |
| --- | --- |
| **S_OK** | The operation completed successfully. |
| **ERROR_ACCESS_DENIED** | Returned if both a parent service and a service handle are provided and the service hierarchy does not roll up to the provided parent service handle. |
| **ERROR_INVALID_PARAMETER** | A parameter was invalid. |
| **ERROR_BAD_NET_RESP** | The target server did not provide an appropriate network response. |
| **ERROR_SEM_TIMEOUT** | The request timed-out. |
| **ERROR_NO_SYSTEM_RESOURCES** | The operation ran out of memory. |
| **ERROR_INVALID_FUNCTION** | A reliable write operation is already presently underway. |
| **E_BLUETOOTH_ATT_INVALID_HANDLE** | The attribute handle given was not valid on this server. |
| **E_BLUETOOTH_ATT_READ_NOT_PERMITTED** | The attribute cannot be read. |
| **E_BLUETOOTH_ATT_WRITE_NOT_PERMITTED** | The attribute cannot be written. |
| **E_BLUETOOTH_ATT_INVALID_PDU** | The attribute PDU was invalid. |
| **E_BLUETOOTH_ATT_INSUFFICIENT_AUTHENTICATION** | The attribute requires authentication before it can be read or written. |
| **E_BLUETOOTH_ATT_REQUEST_NOT_SUPPORTED** | Attribute server does not support the request received from the client. |
| **E_BLUETOOTH_ATT_INVALID_OFFSET** | Offset specified was past the end of the attribute. |
| **E_BLUETOOTH_ATT_INSUFFICIENT_AUTHORIZATION** | The attribute requires authorization before it can be read or written. |
| **E_BLUETOOTH_ATT_PREPARE_QUEUE_FULL** | Too many prepare writes have been queued. |
| **E_BLUETOOTH_ATT_ATTRIBUTE_NOT_FOUND** | No attribute found within the given attribute handle range. |
| **E_BLUETOOTH_ATT_ATTRIBUTE_NOT_LONG** | The attribute cannot be read or written using the Read Blob Request. |
| **E_BLUETOOTH_ATT_INSUFFICIENT_ENCRYPTION_KEY_SIZE** | The Encryption Key Size used for encrypting this link is insufficient. |
| **E_BLUETOOTH_ATT_INVALID_ATTRIBUTE_VALUE_LENGTH** | The attribute value length is invalid for the operation. |
| **E_BLUETOOTH_ATT_UNLIKELY** | The attribute request that was requested has encountered an error that was unlikely, and therefore could not be completed as requested. |
| **E_BLUETOOTH_ATT_INSUFFICIENT_ENCRYPTION** | The attribute requires encryption before it can be read or written. |
| **E_BLUETOOTH_ATT_UNSUPPORTED_GROUP_TYPE** | The attribute type is not a supported grouping attribute as defined by a higher layer specification. |
| **E_BLUETOOTH_ATT_INSUFFICIENT_RESOURCES** | Insufficient Resources to complete the request. |
| **E_BLUETOOTH_ATT_UNKNOWN_ERROR** | An error that lies in the reserved range has been received. |

## Remarks

Calling **BluetoothGATTSetCharacteristicValue** after [BluetoothGATTBeginReliableWrite](https://learn.microsoft.com/windows/desktop/api/bluetoothleapis/nf-bluetoothleapis-bluetoothgattbeginreliablewrite), notifies the remote Bluetooth device to store this request into a prepare queue on the device.

If signing is required, then the operation must not require a response, and must not occur over a secure channel.

The parent characteristic is returned from a previous call to [BluetoothGATTGetCharacteristics](https://learn.microsoft.com/windows/desktop/api/bluetoothleapis/nf-bluetoothleapis-bluetoothgattgetcharacteristics), and must not be altered. Behavior is undefined
if the caller does this.

**Example**

```cpp

BTH_LE_GATT_CHARACTERISTIC_VALUE newValue;

RtlZeroMemory(&newValue,(sizeof(newValue)));

newValue.DataSize = sizeof(valueData);
newValue.Data = (UCHAR*)&valueData;

// Set the new characteristic value
hr = BluetoothGATTSetCharacteristicValue(hDevice,
                                    parentCharacteristic,
                                    &newValue,
                                    NULL,
                                    BLUETOOTH_GATT_FLAG_NONE);

```

## See also

[BTH_LE_GATT_CHARACTERISTIC](https://learn.microsoft.com/windows/desktop/api/bthledef/ns-bthledef-bth_le_gatt_characteristic)

[BTH_LE_GATT_CHARACTERISTIC_VALUE](https://learn.microsoft.com/windows/desktop/api/bthledef/ns-bthledef-bth_le_gatt_characteristic_value)