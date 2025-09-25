# NVME_CDW11_FEATURE_INTERRUPT_COALESCING structure

## Description

Contains parameters for the Interrupt Coalescing Feature that configures the interrupt coalescing settings.

The values from this structure are used in the **InterruptCoalescing** field of the [NVME_CDW11_FEATURES](https://learn.microsoft.com/windows/win32/api/nvme/ns-nvme-nvme_cdw11_features) structure.

## Members

### `DUMMYSTRUCTNAME`

### `DUMMYSTRUCTNAME.THR`

Indicates the recommended minimum number of completion queue entries to aggregate per interrupt vector before signaling an interrupt to the host. This is a 0’s based value. The reset value of this setting is `0h`.

### `DUMMYSTRUCTNAME.Reserved0`

### `DUMMYSTRUCTNAME.TIME`

Indicates the recommended maximum time in 100 microsecond increments that a controller may delay an interrupt due to interrupt coalescing. A value of `0h` corresponds to no delay. The controller may apply this time per interrupt vector or across all interrupt vectors. The reset value of this setting is `0h`.

### `AsUlong`

## Remarks

The controller signals an interrupt when either the Aggregation Time (**TIME**) or the Aggregation Threshold (**THR**) conditions are met. If either the **TIME** or the **THR** fields are cleared to `0h`, then interrupt coalescing is implicitly disabled.

The Interrupt Coalescing Feature is valid when the controller is configured for Pin Based, MSI, Multiple MSI or MSI-X interrupts. There is no requirement for the controller to persist these settings if interrupt modes are changed. It is recommended that the host re-issue this feature after changing interrupt modes.

The controller may delay an interrupt if it detects that interrupts are already being processed for this vector. Specifically, if the [Completion Queue Head Doorbell](https://learn.microsoft.com/windows/win32/api/nvme/ns-nvme-nvme_completion_queue_head_doorbell) register is being updated that is associated with a particular interrupt vector, then the controller has a positive indication that completion queue entries are already being processed. In this case, the aggregation time and/or the aggregation threshold may be reset/restarted upon the associated register write. This may result in interrupts being delayed indefinitely in certain workloads where the aggregation time or aggregation threshold are non-zero.

The Interrupt Coalescing Feature applies only to the I/O Submission and I/O Completion Queues. interrupts for commands that complete in error should not be coalesced.

## See also

- [NVME_CDW11_FEATURES](https://learn.microsoft.com/windows/win32/api/nvme/ns-nvme-nvme_cdw11_features)