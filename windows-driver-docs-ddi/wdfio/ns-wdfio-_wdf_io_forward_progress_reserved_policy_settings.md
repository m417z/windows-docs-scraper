# _WDF_IO_FORWARD_PROGRESS_RESERVED_POLICY_SETTINGS structure

## Description

[Applies to KMDF only]

The **WDF_IO_FORWARD_PROGRESS_RESERVED_POLICY_SETTINGS** structure contains information about specific actions that the framework can take when it receives an I/O request for your driver, if a low-memory situation exists.

## Members

### `Policy`

### `Policy.ExaminePolicy`

### `Policy.ExaminePolicy.EvtIoWdmIrpForForwardProgress`

A pointer to the driver's queue-specific [EvtIoWdmIrpForForwardProgress](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfio/nc-wdfio-evt_wdf_io_wdm_irp_for_forward_progress) callback function.

## Remarks

The **WDF_IO_FORWARD_PROGRESS_RESERVED_POLICY_SETTINGS** structure is used as a member type in the [WDF_IO_QUEUE_FORWARD_PROGRESS_POLICY](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfio/ns-wdfio-_wdf_io_queue_forward_progress_policy) structure.