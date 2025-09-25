# StorPortAcquireMSISpinLock function

## Description

The **StorPortAcquireMSISpinLock** routine acquires the message signaled interrupt (MSI) spin lock that is associated with the specified message.

## Parameters

### `HwDeviceExtension` [in]

A pointer to the hardware device extension for the host bus adapter (HBA).

### `MessageId`

The identifier of the message whose spin lock the caller acquires.

### `OldIrql` [in]

A pointer to the storage for the original IRQL value to be used in a subsequent call to [**StorPortReleaseMSISpinLock**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nf-storport-storportreleasemsispinlock).

## Return value

**StorPortAcquireMSISpinLock** returns one of the following values:

| Return code | Description |
| ----------- | ----------- |
| **STOR_STATUS_NOT_IMPLEMENTED** | This function is not implemented on the active operating system. |
| **STOR_STATUS_SUCCESS** | Indicates that the spin lock was acquired successfully. |
| **STOR_STATUS_INVALID_PARAMETER** | The *HwDeviceExtension* was **NULL**. |

## Remarks

A miniport driver calls the **StorPortAcquireMSISpinLock** routine to acquire the MSI spin lock for a particular message. To release the spin lock, the miniport driver calls the [**StorPortReleaseMSISpinLock**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nf-storport-storportreleasemsispinlock) routine. This routine is used by a miniport drivers to acquire an MSI spin lock for an individual message only when the **InterruptSynchronizationMode** member of the [**PORT_CONFIGURATION_INFORMATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/ns-storport-_port_configuration_information) structure is set to **InterruptSynchronizePerMessage**.

When a miniport needs to synchronize with all messages, it can use one call to [**StorPortAcquireSpinLock**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nf-storport-storportacquirespinlock) which will acquire a lock for each message in the proper order.

## See also

[**PORT_CONFIGURATION_INFORMATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/ns-storport-_port_configuration_information)

[**StorPortAcquireSpinLock**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nf-storport-storportacquirespinlock)

[**StorPortReleaseMSISpinLock**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nf-storport-storportreleasemsispinlock)