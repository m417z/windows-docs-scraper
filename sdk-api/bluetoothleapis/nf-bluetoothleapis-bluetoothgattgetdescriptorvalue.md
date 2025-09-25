# BluetoothGATTGetDescriptorValue function

## Description

The **BluetoothGATTGetDescriptorValue** function gets the value of the specified descriptor.

## Parameters

### `hDevice` [in]

Handle to the service.

### `Descriptor` [in]

Pointer to [BTH_LE_GATT_DESCRIPTOR](https://learn.microsoft.com/windows/desktop/api/bthledef/ns-bthledef-bth_le_gatt_descriptor) structure containing the parent descriptor of the descriptor value to be retrieved.

### `DescriptorValueDataSize` [in]

The number of bytes allocated for the *DescriptorValue* parameter.

### `DescriptorValue` [out, optional]

Pointer to [BTH_LE_GATT_DESCRIPTOR_VALUE](https://learn.microsoft.com/windows/desktop/api/bthledef/ns-bthledef-bth_le_gatt_descriptor_value) structure into which to return the descriptor value.

### `DescriptorValueSizeRequired` [out, optional]

Pointer to buffer into which to store the number of additional bytes needed to return data in the buffer pointed to by *DescriptorValue*.

### `Flags` [in]

Flags to modify the behavior of **BluetoothGATTGetDescriptorValue**:

| Flag | Description |
| --- | --- |
| **BLUETOOTH_GATT_FLAG_NONE** | The client does not have specific GATT requirements (default). |
| **BLUETOOTH_GATT_FLAG_CONNECTION_ENCRYPTED** | The client requests the data to be transmitted over an encrypted channel. |
| **BLUETOOTH_GATT_FLAG_CONNECTION_AUTHENTICATED** | The client requests the data to be transmitted over an authenticated channel. |
| **BLUETOOTH_GATT_FLAG_FORCE_READ_FROM_DEVICE** | The descriptor value is to be read directly from the device. This overwrites the one in the cache if one is already present. |
| **BLUETOOTH_GATT_FLAG_FORCE_READ_FROM_CACHE** | The descriptor value is to be read from the cache (regardless of whether it is present in the cache or not). |

## Return value

The **BluetoothGATTGetDescriptorValue** function returns the following values:

| Return code | Description |
| --- | --- |
| **S_OK** | The operation completed successfully. |
| **ERROR_MORE_DATA** | The buffer parameter is **NULL** and the number of items available is being returned instead. |
| **ERROR_ACCESS_DENIED** | Returned if both a parent service and a service handle are provided and the service hierarchy does not roll up to the provided parent service handle. |
| **ERROR_INVALID_PARAMETER** | Both *DescriptorValue* and *DescriptorValueSizeRequired* are 0. |
| **ERROR_INVALID_USER_BUFFER** | A buffer is specified, but the buffer count size is smaller than what is required, in bytes. |
| **ERROR_INVALID_FUNCTION** | A descriptor value was specified to be retrieved from the cache, but the descriptor value is not present in the cache. |
| **ERROR_BAD_COMMAND** | The current data in the cache appears to be inconsistent, and is leading to internal errors. |
| **ERROR_BAD_NET_RESP** | The target server did not provide an appropriate network response. |
| **ERROR_SEM_TIMEOUT** | The request timed-out. |
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

The descriptor value is returned from the cache if one is already present. This would be the case most of the time, as all the device attributes are cached at the time of pairing or association. However, if it is not present, the descriptor value is read directly from the device, and will be cached upon successfully reading it from the device. If **BLUETOOTH_GATT_FLAG_FORCE_READ_FROM_CACHE** or **BLUETOOTH_GATT_FLAG_FORCE_READ_FROM_DEVICE** is present, the descriptor value is read using the specified method.

Returned descriptor values are cached upon successful retrieval of descriptor values from the device directly. Unless a service-change event is received, the descriptor values is not expected to change.

Profile drivers should pre-allocate a sufficiently large buffer for the array of
descriptor values to be returned in. Callers can determine the necessary buffer size by passing a non-**NULL** value in *DescriptorValueSizeRequired* and **NULL** in *DescriptorValue*.

The parent service must be present in the
cache, otherwise the function will fail. The parent service must be a service returned by either [BluetoothGATTGetServices](https://learn.microsoft.com/windows/desktop/api/bluetoothleapis/nf-bluetoothleapis-bluetoothgattgetservices) or
[BluetoothGATTGetIncludedServices](https://learn.microsoft.com/windows/desktop/api/bluetoothleapis/nf-bluetoothleapis-bluetoothgattgetincludedservices).

**Example**

```cpp

////////////////////////////////////////////////////////////////////////////
// Determine Descriptor Value Buffer Size
////////////////////////////////////////////////////////////////////////////
                hr = BluetoothGATTGetDescriptorValue(
                        hCurrService,
                        currGattDescriptor,
                        0,
                        NULL,
                        &descValueDataSize,
                        BLUETOOTH_GATT_FLAG_NONE);

                if (HRESULT_FROM_WIN32(ERROR_MORE_DATA) != hr) {
                    PrintHr("BluetoothGATTGetDescriptorValue - Buffer Size", hr);
                    goto Done; // allow continuation
                }

                pDescValueBuffer = (PBTH_LE_GATT_DESCRIPTOR_VALUE)malloc(descValueDataSize);

                if (NULL == pDescValueBuffer) {
                    printf("pDescValueBuffer out of memory\r\n");
                    goto Done;
                } else {
                    RtlZeroMemory(pDescValueBuffer, descValueDataSize);
                }

////////////////////////////////////////////////////////////////////////////
// Retrieve the Descriptor Value
////////////////////////////////////////////////////////////////////////////

                hr = BluetoothGATTGetDescriptorValue(
                        hCurrService,
                        currGattDescriptor,
                        (ULONG)descValueDataSize,
                        pDescValueBuffer,
                        NULL,
                        BLUETOOTH_GATT_FLAG_NONE);

                if (S_OK != hr) {
                    PrintHr("BluetoothGATTGetDescriptorValue - Actual Data", hr);
                    goto Done; // allow continuation
                }

```

## See also

[BTH_LE_GATT_DESCRIPTOR](https://learn.microsoft.com/windows/desktop/api/bthledef/ns-bthledef-bth_le_gatt_descriptor)

[BTH_LE_GATT_DESCRIPTOR_VALUE](https://learn.microsoft.com/windows/desktop/api/bthledef/ns-bthledef-bth_le_gatt_descriptor_value)