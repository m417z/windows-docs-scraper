# BluetoothGATTGetServices function

## Description

The **BluetoothGATTGetServices** function gets all the primary services available for a server.

## Parameters

### `hDevice` [in]

Handle to the Bluetooth device from which to obtain the list of primary services.

### `ServicesBufferCount` [in]

The number of elements allocated for the *ServicesBuffer* parameter.

### `ServicesBuffer` [out, optional]

Pointer to buffer containing a [BTH_LE_GATT_SERVICE](https://learn.microsoft.com/windows/desktop/api/bthledef/ns-bthledef-bth_le_gatt_service) structure into which to return services.

### `ServicesBufferActual` [out]

Pointer to buffer into which the actual number of services were returned in the *ServicesBuffer* parameter.

### `Flags` [in]

Flags to modify the behavior of **BluetoothGATTGetServices**:

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
| **ERROR_INVALID_PARAMETER** | One of the following conditions occurred:<br><br>* *ServicesBuffer* is **NULL**, and *ServicesBufferCount* is 0<br>* *ServicesBuffer* is non-**NULL**, but *ServicesBufferCount* is **NULL**<br>* *ServicesBuffer* is non-**NULL**, and *ServicesBufferCount* is 0 |
| **ERROR_INVALID_USER_BUFFER** | A buffer is specified, but the buffer count size is smaller than what is required, in bytes. |
| **ERROR_INVALID_FUNCTION** | Services were specified to be retrieved from the cache, but no services are present in the cache. |
| **ERROR_BAD_COMMAND** | The current data in the cache appears to be inconsistent, and is leading to internal errors. |
| **ERROR_NO_SYSTEM_RESOURCES** | The operation ran out of memory. |

## Remarks

Returned services are cached upon successful retrieval of services from the device directly. Unless a service-change event is received, the list of returned services is not expected to change.

Profile drivers should pre-allocate a sufficiently large buffer for the array of
primary services to be returned in. Callers can determine the necessary buffer size by passing a non-**NULL** value in *ServicesBufferActual* and **NULL** in *ServicesBuffer*.

Do not modify the returned service structure,
and then use the modified structure in subsequent function calls. Behavior is undefined
if the caller does this.

**Example**

```cpp

////////////////////////////////////////////////////////////////////////////
// Determine Services Buffer Size
////////////////////////////////////////////////////////////////////////////

    hr = BluetoothGATTGetServices(
            hLEDevice,
            0,
            NULL,
            &serviceBufferCount,
            BLUETOOTH_GATT_FLAG_NONE);

    if (HRESULT_FROM_WIN32(ERROR_MORE_DATA) != hr) {
        PrintHr("BluetoothGATTGetServices - Buffer Size", hr);
        goto Done;
    }

    pServiceBuffer = (PBTH_LE_GATT_SERVICE)
            malloc(sizeof(BTH_LE_GATT_SERVICE) * serviceBufferCount);

    if (NULL == pServiceBuffer) {
        printf("pServiceBuffer out of memory\r\n");
        goto Done;
    } else {
        RtlZeroMemory(pServiceBuffer,
                sizeof(BTH_LE_GATT_SERVICE) * serviceBufferCount);
    }

////////////////////////////////////////////////////////////////////////////
// Retrieve Services
////////////////////////////////////////////////////////////////////////////

    hr = BluetoothGATTGetServices(
            hLEDevice,
            serviceBufferCount,
            pServiceBuffer,
            &numServices,
            BLUETOOTH_GATT_FLAG_NONE);

    if (S_OK != hr) {
        PrintHr("BluetoothGATTGetServices - Actual Data", hr);
        goto Done;
    }

```

## See also

[BTH_LE_GATT_SERVICE](https://learn.microsoft.com/windows/desktop/api/bthledef/ns-bthledef-bth_le_gatt_service)