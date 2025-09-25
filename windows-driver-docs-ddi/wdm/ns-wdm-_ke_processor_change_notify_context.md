# _KE_PROCESSOR_CHANGE_NOTIFY_CONTEXT structure

## Description

The **KE_PROCESSOR_CHANGE_NOTIFY_CONTEXT** structure describes the notification context that is passed to a registered callback function when a new processor is dynamically added to a hardware partition.

## Members

### `State`

The state of the processor add operation. Possible values are as follows:

#### KeProcessorAddStartNotify

The operating system is about to add the processor. At this state, a device driver that receives this notification can allocate any per-processor data structures and perform any other required tasks to prepare the driver for execution on the new processor.

#### KeProcessorAddCompleteNotify

The operating system has successfully added the processor. At this state, a device driver that receives this notification can start scheduling threads on the new processor.

#### KeProcessorAddFailureNotify

The operating system failed to add the processor. If a device driver receives this notification, it should free any per-processor data structures that it allocated for the new processor when it received the **KeProcessorAddStartNotify** notification.

### `NtNumber`

The processor index of the new processor. For information about the relationship between a processor index and a processor number, see [KeGetProcessorNumberFromIndex](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kegetprocessornumberfromindex).

### `Status`

If the **State** member contains **KeProcessorAddFailureNotify**, this member contains the error status that indicates why the processor add operation failed.

### `ProcNumber`

The processor number of the new processor. This member is a [PROCESSOR_NUMBER](https://learn.microsoft.com/windows-hardware/drivers/ddi/miniport/ns-miniport-_processor_number) structure that specifies a group number and a group-relative processor number.

## Remarks

The **KE_PROCESSOR_CHANGE_NOTIFY_CONTEXT** structure is available starting with Windows Server 2008.

A device driver registers to receive notification when a new processor is dynamically added to the hardware partition by calling the [KeRegisterProcessorChangeCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-keregisterprocessorchangecallback) function. For more information about registering for this notification, see [Registering for Synchronous Driver Notification](https://learn.microsoft.com/windows-hardware/drivers/kernel/registering-for-synchronous-driver-notification).

When a new processor is dynamically added to the hardware partition, the operating system calls each registered callback function two times. The operating system calls each registered callback function the first time with the **KeProcessorAddStartNotify** state, and the second time with either the **KeProcessorAddCompleteNotify** state or the **KeProcessorAddFailureNotify** state.

A device driver's callback function that receives these notifications must not modify the contents of the **KE_PROCESSOR_CHANGE_NOTIFY_CONTEXT** structure.

## See also

[KeGetProcessorNumberFromIndex](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kegetprocessornumberfromindex)

[KeRegisterProcessorChangeCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-keregisterprocessorchangecallback)

[PROCESSOR_NUMBER](https://learn.microsoft.com/windows-hardware/drivers/ddi/miniport/ns-miniport-_processor_number)