# IEnhancedStorageSilo::SendCommand

## Description

Sends a raw silo command to the silo object. This method is utilized to communicate with a silo which is not represented by a driver.

## Parameters

### `Command` [in]

The silo command to be issued. 8 bits of this value are placed in the byte at position 3 of the CDB sent to the device; i.e. the second byte of the **SecurityProtocolSpecific** field.

### `pbCommandBuffer` [in]

The command payload sent to the device in the send data phase of the command.

### `cbCommandBuffer` [in]

The count of bytes contained in the *pbCommandBuffer* buffer.

### `pbResponseBuffer` [out]

The response payload that is returned to the host from the device in the receive data phase of the command.

### `pcbResponseBuffer` [out]

On method entry, contains the size of *pbResponseBuffer* in bytes. On method exit, it contains the count of bytes contained in the returned *pbResponse* buffer.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Silo command completed successfully. |
| **E_INVALIDARG** | The pbCommandBuffer, pbResponseBuffer, or pcbResponseBuffer parameter is **NULL**. |
| **HRESULT_FROM_WIN32(ERROR_NOT_ENOUGH_MEMORY)** | The size of pbResponseBuffer is insufficient to contain the response data. |

## Remarks

This method is currently not supported by the IEEE 1667 certificate and password silos. It is recommended that the [Enhanced Storage Portable Device Commands](https://learn.microsoft.com/previous-versions/windows/desktop/enstor/enhanced-storage-portable-device-commands) are used instead.

The caller is responsible for sending correct parameters to the command, as well as allocating the necessary buffer for the returned results.

## See also

[Enhanced Storage Portable Device Commands](https://learn.microsoft.com/previous-versions/windows/desktop/enstor/enhanced-storage-portable-device-commands)

[IEnhancedStorageSilo](https://learn.microsoft.com/previous-versions/windows/desktop/api/ehstorapi/nn-ehstorapi-ienhancedstoragesilo)