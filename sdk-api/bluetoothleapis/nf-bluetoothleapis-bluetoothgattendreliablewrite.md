# BluetoothGATTEndReliableWrite function

## Description

The **BluetoothGATTEndReliableWrite** function specifies the end of reliable writes, and the writes should be committed.

## Parameters

### `hDevice` [in]

Handle to the service.

### `ReliableWriteContext` [in]

The context describing the reliable write operation returned from a previous call to [BluetoothGATTBeginReliableWrite](https://learn.microsoft.com/windows/desktop/api/bluetoothleapis/nf-bluetoothleapis-bluetoothgattbeginreliablewrite).

### `Flags` [in]

Flags to modify the behavior of **BluetoothGATTEndReliableWrite**:

| Flag | Description |
| --- | --- |
| **BLUETOOTH_GATT_FLAG_NONE** | The client does not have specific GATT requirements (default). |

## Return value

The **BluetoothGATTEndReliableWrite** function returns the following values:

| Return code | Description |
| --- | --- |
| **S_OK** | The operation completed successfully. |
| **ERROR_ACCESS_DENIED** | Returned if both a parent service and a service handle are provided and the service hierarchy does not roll up to the provided parent service handle. |
| **ERROR_INVALID_FUNCTION** | A reliable write operation is not presently underway. |
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