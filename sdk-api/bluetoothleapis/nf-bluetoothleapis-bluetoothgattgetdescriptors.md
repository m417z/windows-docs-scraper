# BluetoothGATTGetDescriptors function

## Description

The **BluetoothGATTGetDescriptors** function gets all the descriptors available for the specified characteristic.

## Parameters

### `hDevice` [in]

Handle to the Bluetooth device or service. If a service handle is passed, then the service must be the grandparent of the descriptor.

### `Characteristic` [in]

Pointer to [BTH_LE_GATT_CHARACTERISTIC](https://learn.microsoft.com/windows/desktop/api/bthledef/ns-bthledef-bth_le_gatt_characteristic) structure containing the parent characteristic of the descriptors to be retrieved.

### `DescriptorsBufferCount` [in]

The number of elements allocated for the *DescriptorsBuffer* parameter.

### `DescriptorsBuffer` [out, optional]

Pointer to buffer containing a [BTH_LE_GATT_DESCRIPTOR](https://learn.microsoft.com/windows/desktop/api/bthledef/ns-bthledef-bth_le_gatt_descriptor) structure into which to return descriptors.

### `DescriptorsBufferActual` [out]

Pointer to buffer into which the actual number of descriptors were returned in the *DescriptorsBuffer* parameter.

### `Flags` [in]

Flags to modify the behavior of **BluetoothGATTGetDescriptors**:

| Flag | Description |
| --- | --- |
| **BLUETOOTH_GATT_FLAG_NONE** | The client does not have specific GATT requirements (default). |

## Return value

This function returns the following values:

| Return code | Description |
| --- | --- |
| **S_OK** | The operation completed successfully. |
| **ERROR_MORE_DATA** | The buffer parameter is NULL and the number of items available is being returned instead. |
| **ERROR_ACCESS_DENIED** | Returned if both a parent service and a service handle are provided and the service hierarchy does not roll up to the provided parent service handle. |
| **ERROR_INVALID_PARAMETER** | One of the following conditions occurred: <br><br>* *DescriptorsBuffer* is **NULL**, and *DescriptorsBufferCount* is 0.<br>* *DescriptorsBuffer* is non-**NULL**, but *DescriptorsBufferCount* is **NULL**.<br>* *DescriptorsBuffer* is non-**NULL**, and *DescriptorsBufferCount* is 0. |
| **ERROR_INVALID_USER_BUFFER** | A buffer is specified, but the buffer count size is smaller than what is required, in bytes. |
| **ERROR_BAD_COMMAND** | The current data in the cache appears to be inconsistent, and is leading to internal errors. |
| **ERROR_NO_SYSTEM_RESOURCES** | The operation ran out of memory. |

## Remarks

Returned characteristics are cached upon successful retrieval of characteristics from the device directly. Unless a service-change event is received, the list of returned characteristics is not expected to change.

Profile drivers should pre-allocate a sufficiently large buffer for the array of
characteristics to be returned in. Callers can determine the necessary buffer size by passing a non-**NULL** value in *DescriptorsBufferActual* and **NULL** in *DescriptorsBuffer*.

Do not modify the returned characteristic structure,
and then use the modified structure in subsequent function calls. Behavior is undefined
if the caller does this.

The parent characteristic must be present in the
cache, otherwise the function will fail. The parent service must be a service returned by either [BluetoothGATTGetServices](https://learn.microsoft.com/windows/desktop/api/bluetoothleapis/nf-bluetoothleapis-bluetoothgattgetservices) or
[BluetoothGATTGetIncludedServices](https://learn.microsoft.com/windows/desktop/api/bluetoothleapis/nf-bluetoothleapis-bluetoothgattgetincludedservices).

**Example**

```cpp

////////////////////////////////////////////////////////////////////////////
// Determine Descriptor Buffer Size
////////////////////////////////////////////////////////////////////////////
GetDescriptors:
            hr = BluetoothGATTGetDescriptors(
                    hCurrService,
                    currGattChar,
                    0,
                    NULL,
                    &descriptorBufferSize,
                    BLUETOOTH_GATT_FLAG_NONE);

            if (HRESULT_FROM_WIN32(ERROR_MORE_DATA) != hr) {
                PrintHr("BluetoothGATTGetDescriptors - Buffer Size", hr);
                goto Done; // Allow continuation
            }

            if (descriptorBufferSize > 0) {
                pDescriptorBuffer = (PBTH_LE_GATT_DESCRIPTOR)
                        malloc(descriptorBufferSize
                            * sizeof(BTH_LE_GATT_DESCRIPTOR));

                if (NULL == pDescriptorBuffer) {
                    printf("pDescriptorBuffer out of memory\r\n");
                    goto Done;
                } else {
                    RtlZeroMemory(pDescriptorBuffer, descriptorBufferSize);
                }

////////////////////////////////////////////////////////////////////////////
// Retrieve Descriptors
////////////////////////////////////////////////////////////////////////////

                hr = BluetoothGATTGetDescriptors(
                        hCurrService,
                        currGattChar,
                        descriptorBufferSize,
                        pDescriptorBuffer,
                        &numDescriptors,
                        BLUETOOTH_GATT_FLAG_NONE);

                if (S_OK != hr) {
                    PrintHr("BluetoothGATTGetDescriptors - Actual Data", hr);
                    goto Done;
                }

                if (numDescriptors != descriptorBufferSize) {
                    printf("buffer size and buffer size actual size mismatch\r\n");
                    goto Done;
                }
            }

```

## See also

[BTH_LE_GATT_CHARACTERISTIC](https://learn.microsoft.com/windows/desktop/api/bthledef/ns-bthledef-bth_le_gatt_characteristic)

[BTH_LE_GATT_DESCRIPTOR](https://learn.microsoft.com/windows/desktop/api/bthledef/ns-bthledef-bth_le_gatt_descriptor)