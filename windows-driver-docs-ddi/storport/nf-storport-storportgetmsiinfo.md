# StorPortGetMSIInfo function

## Description

The **StorPortGetMSIInfo** routine retrieves the message signaled interrupt (MSI) information for the specified message.

## Parameters

### `HwDeviceExtension` [in]

A pointer to the hardware device extension for the host bus adapter (HBA).

### `MessageId` [in]

The identifier of the message for which the information is retrieved.

### `InterruptInfo` [out]

A pointer to a miniport driver-provided [MESSAGE_INTERRUPT_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/ns-storport-_message_interrupt_information) structure that receives the information for the message specified by the *MessageId* parameter.

## Return value

**StorPortGetMSIInfo** returns one of the status codes:

| Return code | Description |
| --- | --- |
| **STOR_STATUS_NOT_IMPLEMENTED** | This function is not implemented on the active operating system. |
| **STOR_STATUS_SUCCESS** | Indicates that the MSI information was successfully received for the specified message. |
| **STOR_STATUS_INVALID_PARAMETER** | *HwDeviceExtension* passed was **NULL**.<br><br>-or-<br><br>The pointer in *InterruptInfo* for the structure to receive the information is **NULL**.<br><br>-or-<br><br>*MessageId* passed to the function is incorrect. |
| **STOR_STATUS_INVALID_DEVICE_REQUEST** | The HBA does not support MSI. |

## See also

[MESSAGE_INTERRUPT_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/ns-storport-_message_interrupt_information)