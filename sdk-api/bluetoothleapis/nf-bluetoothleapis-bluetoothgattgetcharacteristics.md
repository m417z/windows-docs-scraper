## Description

The **BluetoothGATTGetCharacteristics** function gets all the characteristics available for the specified service.

## Parameters

### `hDevice` [in]

Handle to the Bluetooth device or service.

### `Service` [in, optional]

Address of a [BTH_LE_GATT_SERVICE](https://learn.microsoft.com/windows/win32/api/bthledef/ns-bthledef-bth_le_gatt_service) structure containing the parent service of the included services to be retrieved. This parameter is required if a device handle is passed to *hDevice*. This parameter is optional if a service handle was passed to *hDevice*, in which case the service specified by the service handle will be treated as the parent.

### `CharacteristicsBufferCount` [in]

The number of elements allocated for the *CharacteristicsBuffer* parameter.

### `CharacteristicsBuffer` [out, optional]

Pointer to a buffer into which to return characteristics as an array of [BTH_LE_GATT_CHARACTERISTIC](https://learn.microsoft.com/windows/win32/api/bthledef/ns-bthledef-bth_le_gatt_characteristic) structures.

### `CharacteristicsBufferActual` [out]

Pointer to buffer into which is returned the actual number of characteristics that were returned in the *CharacteristicsBuffer* parameter.

### `Flags` [in]

Flags to modify the behavior of **BluetoothGATTGetCharacteristics**:

| Flag | Description |
| --- | --- |
| **BLUETOOTH_GATT_FLAG_NONE** | The client does not have specific GATT requirements (default). |

## Return value

This function returns the following values:

| Return code | Description |
| --- | --- |
| **S_OK** | The operation completed successfully. |
| **ERROR_MORE_DATA** | The buffer parameter is **NULL** and the number of items available is being returned instead. |
| **ERROR_ACCESS_DENIED** | Returned if both a parent service and a service handle are provided and the service hierarchy does not roll up to the provided parent service handle. |
| **ERROR_INVALID_PARAMETER** | One of the following conditions occurred:<br><br>* *CharacteristicsBuffer* is **NULL**, and *CharacteristicsBufferCount* is 0<br>* *CharacteristicsBuffer* is non-**NULL**, but *CharacteristicsBufferCount* is **NULL**<br>* *CharacteristicsBuffer* is non-**NULL**, and *CharacteristicsBufferCount* is 0 |
| **ERROR_INVALID_USER_BUFFER** | A buffer is specified, but the buffer count size is smaller than what is required, in bytes. |
| **ERROR_BAD_COMMAND** | The current data in the cache appears to be inconsistent, and is leading to internal errors. |
| **ERROR_NO_SYSTEM_RESOURCES** | The operation ran out of memory. |

## Remarks

Returned characteristics are cached upon successful retrieval of characteristics from the device directly. Unless a service-change event is received, the list of returned characteristics is not expected to change.

Profile drivers should pre-allocate a sufficiently large buffer for the array of
characteristics to be returned in. Callers can determine the necessary buffer size by passing a non-**NULL** value in *CharacteristicsBufferActual* and **NULL** in *CharacteristicsBuffer*.

Do not modify the returned characteristic structure,
and then use the modified structure in subsequent function calls. Behavior is undefined
if the caller does this.

The parent service must be present in the
cache, otherwise the function will fail. The parent service must be a service returned by either [BluetoothGATTGetServices](https://learn.microsoft.com/windows/win32/api/bluetoothleapis/nf-bluetoothleapis-bluetoothgattgetservices) or
[BluetoothGATTGetIncludedServices](https://learn.microsoft.com/windows/win32/api/bluetoothleapis/nf-bluetoothleapis-bluetoothgattgetincludedservices).

**Example**

```cpp
////////////////////////////////////////////////////////////////////////////
// Determine Characteristic Buffer Size
////////////////////////////////////////////////////////////////////////////

        hr = BluetoothGATTGetCharacteristics(
                hCurrService,
                currGattService,
                0,
                NULL,
                &charBufferSize,
                BLUETOOTH_GATT_FLAG_NONE);

        if (HRESULT_FROM_WIN32(ERROR_MORE_DATA) != hr) {
            PrintHr("BluetoothGATTGetCharacteristics - Buffer Size", hr);
            goto Done;
        }

        if (charBufferSize > 0) {
            pCharBuffer = (PBTH_LE_GATT_CHARACTERISTIC)
                    malloc(charBufferSize * sizeof(BTH_LE_GATT_CHARACTERISTIC));

            if (NULL == pCharBuffer) {
                printf("pCharBuffer out of memory\r\n");
                goto Done;
            } else {
                RtlZeroMemory(pCharBuffer,
                        charBufferSize * sizeof(BTH_LE_GATT_CHARACTERISTIC));
            }

////////////////////////////////////////////////////////////////////////////
// Retrieve Characteristics
////////////////////////////////////////////////////////////////////////////

            hr = BluetoothGATTGetCharacteristics(
                    hCurrService,
                    currGattService,
                    charBufferSize,
                    pCharBuffer,
                    &numChars,
                    BLUETOOTH_GATT_FLAG_NONE);

            if (S_OK != hr) {
                PrintHr("BluetoothGATTGetCharacteristics - Actual Data", hr);
                goto Done; // Allow continuation
            }

            if (numChars != charBufferSize) {
                printf("buffer size and buffer size actual size mismatch\r\n");
                goto Done;
            }
        }
```

## See also

[BTH_LE_GATT_CHARACTERISTIC](https://learn.microsoft.com/windows/win32/api/bthledef/ns-bthledef-bth_le_gatt_characteristic)

[BTH_LE_GATT_SERVICE](https://learn.microsoft.com/windows/win32/api/bthledef/ns-bthledef-bth_le_gatt_service)