# StorPortReleaseMSISpinLock function

## Description

The **StorPortReleaseMSISpinLock** routine releases a previously acquired message signaled interrupt (MSI) spin lock for the specified message.

## Parameters

### `HwDeviceExtension` [in]

A pointer to the hardware device extension for the host bus adapter (HBA).

### `MessageId`

The identifier of the message.

### `OldIrql` [in]

The IRQL that the [**StorPortAcquireMSISpinLock**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nf-storport-storportacquiremsispinlock) routine returned when the miniport driver acquired the spin lock.

## Return value

StorPortReleaseMSISpinLock returns one of the following status codes:

| Return code | Description |
| ----------- | ----------- |
| **STOR_STATUS_NOT_IMPLEMENTED** | This function is not implemented on the active operating system. |
| **STOR_STATUS_SUCCESS** | Indicates that the spin lock was released successfully. |
| **STOR_STATUS_INVALID_PARAMETER** | HwDeviceExtension was **NULL**. |

## Remarks

Miniport drivers are not required to acquire MSI spin locks for messages unless the **InterruptSynchronizePerMessage** member of the [**PORT_CONFIGURATION_INFORMATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/ns-storport-_port_configuration_information) structure indicates a synchronization mode of **InterruptSynchronizationMode**.

## See also

[**StorPortAcquireMSISpinLock**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nf-storport-storportacquiremsispinlock)