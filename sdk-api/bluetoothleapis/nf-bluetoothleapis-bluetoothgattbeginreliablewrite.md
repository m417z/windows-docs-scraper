# BluetoothGATTBeginReliableWrite function

## Description

The **BluetoothGATTBeginReliableWrite** function specifies that reliable writes are about to begin.

## Parameters

### `hDevice` [in]

Handle to the service.

### `ReliableWriteContext` [out]

Address of a **BTH_LE_GATT_RELIABLE_WRITE_CONTEXT** structure containing the context describing the reliable write operation.

### `Flags` [in]

Flags to modify the behavior of **BluetoothGATTBeginReliableWrite**:

| Flag | Description |
| --- | --- |
| **BLUETOOTH_GATT_FLAG_NONE** | The client does not have specific GATT requirements (default). |

## Return value

The **BluetoothGATTBeginReliableWrite** function returns the following values:

| Return code | Description |
| --- | --- |
| **S_OK** | The operation completed successfully. |
| **ERROR_ACCESS_DENIED** | Returned if both a parent service and a service handle are provided and the service hierarchy does not roll up to the provided parent service handle. |
| **ERROR_INVALID_FUNCTION** | A reliable write operation is already presently underway. |

## Remarks

The **BluetoothGATTBeginReliableWrite** function notifies the Bluetooth stack that procedures that are to be called after the function returns are reliable write operations. Any operations that do not support reliable writes will return an **ERROR_INVALID_FUNCTION** error. Only the following functions support reliable write operations:

* [BluetoothGATTSetCharacteristicValue](https://learn.microsoft.com/windows/desktop/api/bluetoothleapis/nf-bluetoothleapis-bluetoothgattsetcharacteristicvalue)
* [BluetoothGATTEndReliableWrite](https://learn.microsoft.com/windows/desktop/api/bluetoothleapis/nf-bluetoothleapis-bluetoothgattendreliablewrite)
* [BluetoothGATTAbortReliableWrite](https://learn.microsoft.com/windows/desktop/api/bluetoothleapis/nf-bluetoothleapis-bluetoothgattabortreliablewrite)

#### Examples

```cpp

BTH_LE_GATT_RELIABLE_WRITE_CONTEXT ReliableWriteContext = NULL;
hr = BluetoothGATTBeginReliableWrite(hDevice,
                                    &ReliableWriteContext,
                                    BLUETOOTH_GATT_FLAG_NONE);

if (SUCCEEDED(hr)) {
    // Calls to BluetoothGATTSetCharacteristicValue
}

if (NULL != ReliableWriteContext) {
    BluetoothGATTEndReliableWrite(hDevice,
                                 ReliableWriteContext,
                                  BLUETOOTH_GATT_FLAG_NONE);
}
```