# BluetoothGATTGetCharacteristicValue function

## Description

The **BluetoothGATTGetCharacteristicValue** function gets the value of the specified characteristic.

## Parameters

### `hDevice` [in]

Handle to the service.

### `Characteristic` [in]

Pointer to the parent characteristic of the characteristic value to be retrieved.

### `CharacteristicValueDataSize` [in]

The number of bytes allocated for the *CharacteristicValue* parameter.

### `CharacteristicValue` [out, optional]

Pointer to buffer into which to return the characteristic value.

### `CharacteristicValueSizeRequired` [out, optional]

Pointer to buffer into which to store the number of bytes needed to return data in the buffer pointed to by *CharacteristicValue*.

### `Flags` [in]

Flags to modify the behavior of **BluetoothGATTGetCharacteristicValue**:

| Flag | Description |
| --- | --- |
| **BLUETOOTH_GATT_FLAG_NONE** | The client does not have specific GATT requirements (default). |
| **BLUETOOTH_GATT_FLAG_CONNECTION_ENCRYPTED** | The client requests the data to be transmitted over an encrypted channel. |
| **BLUETOOTH_GATT_FLAG_CONNECTION_AUTHENTICATED** | The client requests the data to be transmitted over an authenticated channel. |
| **BLUETOOTH_GATT_FLAG_FORCE_READ_FROM_DEVICE** | The characteristic value is to be read directly from the device. This overwrites the one in the cache if one is already present. |
| **BLUETOOTH_GATT_FLAG_FORCE_READ_FROM_CACHE** | The characteristic value is to be read from the cache (regardless of whether it is present in the cache or not). |

## Return value

The **BluetoothGATTGetCharacteristicValue** function returns the following values:

| Return code | Description |
| --- | --- |
| **S_OK** | The operation completed successfully. |
| **ERROR_MORE_DATA** | The buffer parameter is NULL and the number of items available is being returned instead. |
| **ERROR_ACCESS_DENIED** | Returned if both a parent service and a service handle are provided and the service hierarchy does not roll up to the provided parent service handle. |
| **ERROR_INVALID_PARAMETER** | Both *CharacteristicValue* and *CharacteristicValueSizeRequired* are 0. |
| **ERROR_INVALID_USER_BUFFER** | A buffer is specified, but the buffer count size is smaller than what is required, in bytes. |
| **ERROR_BAD_COMMAND** | The current data in the cache appears to be inconsistent, and is leading to internal errors. |
| **ERROR_BAD_NET_RESP** | The target server did not provide an appropriate network response. |
| **ERROR_SEM_TIMEOUT** | The request timed-out. |
| **ERROR_PRIVILEGE_NOT_HELD** | The characteristic value is not readable as dictated by the characteristic properties. |
| **ERROR_NO_SYSTEM_RESOURCES** | The operation ran out of memory. |
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

The characteristic value is returned from the cache if one is already present. This would be the case most of the time, as all the device attributes are cached at the time of pairing or association. However, if it is not present, the characteristic value is read directly from the device, and will be cached upon successfully reading it from the device. If **BLUETOOTH_GATT_FLAG_FORCE_READ_FROM_CACHE** or **BLUETOOTH_GATT_FLAG_FORCE_READ_FROM_DEVICE** is present, the characteristic value is read using the specified method.

Returned characteristics are cached upon successful retrieval of characteristics from the device directly. Unless a service-change event is received, the list of returned characteristics is not expected to change.

Profile drivers should pre-allocate a sufficiently large buffer for the array of
characteristics to be returned in. Callers can determine the necessary buffer size by passing a non-**NULL** value in *CharacteristicValueSizeRequired* and **NULL** in *CharacteristicValue*.

The parent service must be present in the
cache, otherwise the function will fail. The parent service must be a service returned by either [BluetoothGATTGetServices](https://learn.microsoft.com/windows/desktop/api/bluetoothleapis/nf-bluetoothleapis-bluetoothgattgetservices) or
[BluetoothGATTGetIncludedServices](https://learn.microsoft.com/windows/desktop/api/bluetoothleapis/nf-bluetoothleapis-bluetoothgattgetincludedservices).

**Example**

```cpp

            if (currGattChar->IsReadable) {
////////////////////////////////////////////////////////////////////////////
// Determine Characteristic Value Buffer Size
////////////////////////////////////////////////////////////////////////////

                hr = BluetoothGATTGetCharacteristicValue(
                        hCurrService,
                        currGattChar,
                        0,
                        NULL,
                        &charValueDataSize,
                        BLUETOOTH_GATT_FLAG_NONE);

                if (HRESULT_FROM_WIN32(ERROR_MORE_DATA) != hr) {
                    PrintHr("BluetoothGATTGetCharacteristicValue - Buffer Size", hr);
                    goto GetDescriptors; // Proceed to retrieving descriptors
                }

                pCharValueBuffer = (PBTH_LE_GATT_CHARACTERISTIC_VALUE)malloc(charValueDataSize);

                if (NULL == pCharValueBuffer) {
                    printf("pCharValueBuffer out of memory\r\n");
                    goto Done;
                } else {
                    RtlZeroMemory(pCharValueBuffer, charValueDataSize);
                }

////////////////////////////////////////////////////////////////////////////
// Retrieve the Characteristic Value
////////////////////////////////////////////////////////////////////////////

                hr = BluetoothGATTGetCharacteristicValue(
                        hCurrService,
                        currGattChar,
                        (ULONG)charValueDataSize,
                        pCharValueBuffer,
                        NULL,
                        BLUETOOTH_GATT_FLAG_NONE);

                if (S_OK != hr) {
                    PrintHr("BluetoothGATTGetCharacteristicValue - Actual Data", hr);
                    goto GetDescriptors; // Proceed to retrieving descriptors
                }

                PrintCharacteristicValue(pCharValueBuffer, 2, currGattChar->CharacteristicUuid);

                // Free before going to next iteration, or memory leak.
                free(pCharValueBuffer);
                pCharValueBuffer = NULL;
            }

```

## See also

[BTH_LE_GATT_CHARACTERISTIC](https://learn.microsoft.com/windows/desktop/api/bthledef/ns-bthledef-bth_le_gatt_characteristic)

[BTH_LE_GATT_CHARACTERISTIC_VALUE](https://learn.microsoft.com/windows/desktop/api/bthledef/ns-bthledef-bth_le_gatt_characteristic_value)