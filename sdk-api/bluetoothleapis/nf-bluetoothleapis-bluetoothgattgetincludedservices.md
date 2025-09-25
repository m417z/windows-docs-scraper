# BluetoothGATTGetIncludedServices function

## Description

The **BluetoothGATTGetIncludedServices** function gets all the included services available for a given service.

## Parameters

### `hDevice` [in]

Handle to the Bluetooth device or parent service.

### `ParentService` [in, optional]

Address of a [BTH_LE_GATT_SERVICE](https://learn.microsoft.com/windows/desktop/api/bthledef/ns-bthledef-bth_le_gatt_service) structure that contains the parent service of the included services to be retrieved. This parameter is required if a device handle is passed to *hDevice*. This parameter is optional if a service handle was passed to *hDevice*, in which case the service specified by the service handle will be treated as the parent.

### `IncludedServicesBufferCount` [in]

The number of elements allocated for the *IncludedServicesBuffer* parameter.

### `IncludedServicesBuffer` [out, optional]

Address of a buffer containing a [BTH_LE_GATT_SERVICE](https://learn.microsoft.com/windows/desktop/api/bthledef/ns-bthledef-bth_le_gatt_service) structure into which to return included services.

### `IncludedServicesBufferActual` [out]

Pointer to buffer into which the actual number of included services were returned in the *IncludedServicesBuffer* parameter.

### `Flags` [in]

Flags to modify the behavior of **BluetoothGATTGetIncludedServices**:

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
| **ERROR_INVALID_PARAMETER** | One of the following conditions occurred:<br><br>* *IncludedServicesBuffer* is **NULL**, and *IncludedServicesBufferCount* is 0.<br>* *IncludedServicesBuffer* is non-**NULL**, but *IncludedServicesBufferCount* is **NULL**.<br>* *IncludedServicesBuffer* is non-**NULL**, and *IncludedServicesBufferCount* is 0. |
| **ERROR_INVALID_USER_BUFFER** | A buffer is specified, but the buffer count size is smaller than what is required, in bytes. |
| **ERROR_INVALID_FUNCTION** | Services were specified to be retrieved from the cache, but no services are present in the cache. |
| **ERROR_BAD_COMMAND** | The current data in the cache appears to be inconsistent, and is leading to internal errors. |
| **ERROR_NO_SYSTEM_RESOURCES** | The operation ran out of memory. |

## Remarks

Returned services are cached upon successful retrieval of services from the device directly. Unless a service-change event is received, the list of returned services is not expected to change.

Profile drivers should pre-allocate a sufficiently large buffer for the array of
primary services to be returned in. Callers can determine the necessary buffer size by passing a non-**NULL** value in *IncludedServicesBufferActual* and **NULL** in *IncludedServicesBuffer*.

Do not modify the returned service structure,
and then use the modified structure in subsequent function calls. Behavior is undefined
if the caller does this.

**Example**

```cpp

////////////////////////////////////////////////////////////////////////////
// Determine Included Services Buffer Size
////////////////////////////////////////////////////////////////////////////
hr = BluetoothGATTGetIncludedServices(
     hLEDevice,
     gattService,
     0,
     NULL,
     &inclServicesBufferSize,
     BLUETOOTH_GATT_FLAG_NONE);

     if (HRESULT_FROM_WIN32(ERROR_MORE_DATA) != hr) {
         PrintHr("BluetoothGATTGetIncludedServices - Buffer Size", hr);
         goto Done;
     }

     if (inclServicesBufferSize > 0) {
         pInclServicesBuffer = (PBTH_LE_GATT_ PBTH_LE_GATT_SERVICE)
                    malloc(inclServicesBufferSize * sizeof(BTH_LE_GATT_SERVICE));

         if (NULL == pInclServicesBuffer) {
             printf("pInclServicesBuffer out of memory\r\n");
             goto Done;
         } else {
             RtlZeroMemory(pInclServicesBuffer,
                    inclServicesBufferSize * sizeof(BTH_LE_GATT_SERVICE));
         }

         ////////////////////////////////////////////////////////////////////////////
         // Retrieve Included Services
         ////////////////////////////////////////////////////////////////////////////

         hr = BluetoothGATTGetIncludedServices (
              hLEDevice,
              gattService,
              inclServicesBufferSize,
              pInclServicesBuffer,
              &numIncludedServices
              BLUETOOTH_GATT_FLAG_NONE);

         if (S_OK != hr) {
             PrintHr("BluetoothGATTGetIncludedServices - Actual Data", hr);
             goto Done;
         }
     }
```

## See also

[BTH_LE_GATT_SERVICE](https://learn.microsoft.com/windows/desktop/api/bthledef/ns-bthledef-bth_le_gatt_service)